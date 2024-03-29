// WebSocketTest.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#define NOMINMAX
#include "stdafx.h"
#include "nlohmann/json.hpp" 

#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <list>

#include <iostream>
#include "websocketpp/config/asio_no_tls.hpp"
#include <websocketpp/server.hpp>
#include "main.h"


class CtpApiAdapter {
private:
	CSimpleHandler m_sh = NULL;
	CSimpleMdHandler m_ash = NULL;

public:
	CtpApiAdapter() {
		init();
	}

	void adapter(nlohmann::json json) {
		std::string method = json["method"];
		if (method.compare("order")) {
			m_sh.getUserApi()->ReqOrderInsert();
		}
	}

private:
	void init() {
		system("COLOR 0A");
		logfile = fopen("syslog.txt", "w");

		string g_chFrontaddr = getConfig("config", "FrontAddr");
		cout << "g_chFrontaddr = " << g_chFrontaddr << "\n" << endl;
		CTraderApi *pUserApi = new CTraderApi;//--------------------------
		pUserApi->CreateFtdcTraderApi(".\\flow\\");
		LOG(pUserApi->GetApiVersion());
		cout << endl;
		CSimpleHandler sh(pUserApi);
		m_sh = sh;

	cir:pUserApi->RegisterSpi(&sh);
		pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);
		pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);
		pUserApi->RegisterFront(const_cast<char *>(g_chFrontaddr.c_str()));
		pUserApi->Init();
		sh.ReqAuthenticate();
		WaitForSingleObject(g_hEvent, INFINITE);
		sh.ReqUserLogin();
		WaitForSingleObject(g_hEvent, INFINITE);

		string g_chFrontMdaddr = getConfig("config", "FrontMdAddr");
		cout << "g_chFrontMdaddr = " << g_chFrontMdaddr << "\n" << endl;
		CThostFtdcMdApi  *pUserMdApi =
			CThostFtdcMdApi::CreateFtdcMdApi(".\\flow\\md");
		CSimpleMdHandler ash(pUserMdApi);
		m_ash = ash;
		pUserMdApi->RegisterSpi(&ash);
		pUserMdApi->RegisterFront(const_cast<char *>(g_chFrontMdaddr.c_str()));
		pUserMdApi->Init();
		cout << "登录等待回报 \n" << endl;
		WaitForSingleObject(xinhao, INFINITE);
	}

	///报单录入请求
	void ReqOrderInsert_Ordinary(string limitprice, int volume, int direction, int combOffsetFlag)
	{
		CThostFtdcInputOrderField ord = { 0 };
		strcpy_s(ord.BrokerID, g_chBrokerID);
		strcpy_s(ord.InvestorID, g_chInvestorID);
		strcpy_s(ord.InstrumentID, g_chInstrumentID);
		strcpy_s(ord.UserID, g_chUserID);
		ord.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
		ord.CombOffsetFlag[0] = THOST_FTDC_OF_Open;

	
	Direction:LOG("请选择买卖方向\t1.买\t2.卖\n");
		if (direction == 1) {
			ord.Direction = THOST_FTDC_D_Buy;//买
		}
		else if (direction == 2) {
			ord.Direction = THOST_FTDC_D_Sell;//卖
		}
		else {
			LOG("输入错误请重新输入\n");
		}

		
	CombOffsetFlag:LOG("请输入开平方向\t1.开仓\t2.平仓\t3.强平\t4.平今\t5.平昨\t6.强减\t7.本地强平\n");
		if (combOffsetFlag == 1) {
			ord.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
		}
		else if (combOffsetFlag == 2) {
			ord.CombOffsetFlag[0] = THOST_FTDC_OF_Close;
		}
		else if (combOffsetFlag == 3) {
			ord.CombOffsetFlag[0] = THOST_FTDC_OF_ForceClose;
		}
		else if (combOffsetFlag == 4) {
			ord.CombOffsetFlag[0] = THOST_FTDC_OF_CloseToday;
		}
		else if (combOffsetFlag == 5) {
			ord.CombOffsetFlag[0] = THOST_FTDC_OF_CloseYesterday;
		}
		else if (combOffsetFlag == 6) {
			ord.CombOffsetFlag[0] = THOST_FTDC_OF_ForceOff;
		}
		else if (combOffsetFlag == 7) {
			ord.CombOffsetFlag[0] = THOST_FTDC_OF_LocalForceClose;
		}
		else {
			LOG("输入错误请重新输入\n");
		}

		//ord.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
		strcpy_s(ord.CombHedgeFlag, "1");
		//ord.LimitPrice = atoi(getConfig("config", "LimitPrice").c_str());
		ord.LimitPrice = atof(limitprice.c_str());
		ord.VolumeTotalOriginal = volume;
		ord.TimeCondition = THOST_FTDC_TC_GFD;///当日有效
		ord.VolumeCondition = THOST_FTDC_VC_CV;///全部数量
		ord.MinVolume = 1;
		ord.ContingentCondition = THOST_FTDC_CC_Immediately;
		ord.StopPrice = 0;
		ord.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
		ord.IsAutoSuspend = 0;
		strcpy_s(ord.ExchangeID, g_chExchangeID);
		int a = m_sh.getUserApi()->ReqOrderInsert(&ord, 1);
		LOG((a == 0) ? "报单录入请求限价单......发送成功\n" : "报单录入请求限价单......发送失败，序号=[%d]\n", a);
	}
};


CtpApiAdapter ctpApiAdapter;

//名称与值数据对
struct NameAndValue
{
	std::string strName;
	std::string strValue;
};
// 字符串分割
int StringSplit(std::vector<std::string>& dst, const std::string& src, const std::string& separator);
//去前后空格
std::string& StringTrim(std::string &str);
//获取请求命令与参数
bool GetReqeustCommandAndParmeter(std::string strUri, std::string & strRequestOperateCommand, std::list<NameAndValue> & listRequestOperateParameter);




typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

// pull out the type of messages sent by our config
typedef server::message_ptr message_ptr;

bool validate(server *, websocketpp::connection_hdl) {
	//sleep(6);
	return true;
}

void on_http(server* s, websocketpp::connection_hdl hdl) {
	server::connection_ptr con = s->get_con_from_hdl(hdl);

	std::string res = con->get_request_body();

	std::stringstream ss;
	ss << "got HTTP request with " << res.size() << " bytes of body data.";

	con->set_body(ss.str());
	con->set_status(websocketpp::http::status_code::ok);
}

void on_fail(server* s, websocketpp::connection_hdl hdl) {
	server::connection_ptr con = s->get_con_from_hdl(hdl);

	std::cout << "Fail handler: " << con->get_ec() << " " << con->get_ec().message() << std::endl;
}

void on_open(server* s, websocketpp::connection_hdl hdl) {
	//申请websocket upgrade成功之后，调用open_handler函数，回调on_open。
	//在这里，可以获取http请求的地址、参数信息。
	std::cout << "open handler" << std::endl;
	/*
	server::connection_ptr con = s->get_con_from_hdl(hdl);
	websocketpp::config::core::request_type requestClient = con->get_request();
	std::string strMethod = requestClient.get_method();		//请求方法
	std::string strUri = requestClient.get_uri();			//请求uri地址，可以解析参数
	std::string strRequestOperateCommand = "";				//操作类型
	std::list<NameAndValue> listRequestOperateParameter;	//操作参数列表
	GetReqeustCommandAndParmeter(strUri, strRequestOperateCommand, listRequestOperateParameter);
	std::cout << "command:" << strRequestOperateCommand << std::endl;
	*/
}

void on_close(websocketpp::connection_hdl hdl) {
	std::cout << "Close handler" << std::endl;
}

// Define a callback to handle incoming messages
void on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg) {
	/*
	hdl.lock().get() 获得连接标识
	msg->get_payload() 是收到的消息内容
	msg->get_opcode() 是收到消息的类型 ，包含：文本TEXT,二进制BINARY等等
	*/
	std::cout << "on_message called with hdl: " << hdl.lock().get()
		<< " and message: " << msg->get_payload()
		<< std::endl;

	nlohmann::json json = nlohmann::json::parse(msg->get_payload());
	ctpApiAdapter.adapter(json);

	//try {
	//	/*
	//	发送消息
	//	s->send(
	//	hdl, //连接
	//	msg->get_payload(), //消息
	//	msg->get_opcode());//消息类型
	//	*/
	//	s->send(hdl, msg->get_payload(), msg->get_opcode());
	//}
	//catch (websocketpp::exception const & e) {
	//	std::cout << "Echo failed because: "
	//		<< "(" << e.what() << ")" << std::endl;
	//}
}

void websocketService() {
	server print_server;
	try {
		// Set logging settings
		print_server.set_access_channels(websocketpp::log::alevel::all);
		print_server.set_error_channels(websocketpp::log::elevel::all);
		//print_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

		// Register our message handler
		print_server.set_message_handler(bind(&on_message, &print_server, ::_1, ::_2));
		print_server.set_http_handler(bind(&on_http, &print_server, ::_1));
		print_server.set_fail_handler(bind(&on_fail, &print_server, ::_1));
		print_server.set_open_handler(bind(&on_open, &print_server, ::_1));
		print_server.set_close_handler(bind(&on_close, ::_1));
		print_server.set_validate_handler(bind(&validate, &print_server, ::_1));

		// Initialize ASIO
		print_server.init_asio();
		print_server.set_reuse_addr(true);

		// Listen on port 9100
		print_server.listen(9100);
		// Start the server accept loop
		print_server.start_accept();

		// Start the ASIO io_service run loop
		print_server.run();

		//stop
		print_server.stop();
	}
	catch (websocketpp::exception const & e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "other exception" << std::endl;
	}
}


int main() {
	websocketService();

	return 0;
}


// 字符串分割
int StringSplit(std::vector<std::string>& dst, const std::string& src, const std::string& separator)
{
	if (src.empty() || separator.empty())
		return 0;

	int nCount = 0;
	std::string temp;
	size_t pos = 0, offset = 0;

	// 分割第1~n-1个
	while ((pos = src.find_first_of(separator, offset)) != std::string::npos)
	{
		temp = src.substr(offset, pos - offset);
		if (temp.length() > 0) {
			dst.push_back(temp);
			nCount++;
		}
		offset = pos + 1;
	}

	// 分割第n个
	temp = src.substr(offset, src.length() - offset);
	if (temp.length() > 0) {
		dst.push_back(temp);
		nCount++;
	}

	return nCount;
}
//去前后空格
std::string& StringTrim(std::string &str)
{
	if (str.empty()) {
		return str;
	}
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
	return str;
}
//获取请求命令与参数
bool GetReqeustCommandAndParmeter(std::string strUri, std::string & strRequestOperateCommand, std::list<NameAndValue> & listRequestOperateParameter)
{
	bool bRet = false;
	std::vector<std::string> vecRequest;
	int nRetSplit = StringSplit(vecRequest, strUri, "?");
	if (nRetSplit > 0)
	{
		if (vecRequest.size() == 1)
		{
			strRequestOperateCommand = vecRequest[0];
		}
		else if (vecRequest.size() > 1)
		{
			strRequestOperateCommand = vecRequest[0];
			std::string strRequestParameter = vecRequest[1];
			std::vector<std::string> vecParams;
			nRetSplit = StringSplit(vecParams, strRequestParameter, "&");
			if (nRetSplit > 0)
			{
				std::vector<std::string>::iterator iter, iterEnd;
				iter = vecParams.begin();
				iterEnd = vecParams.end();
				for (iter; iter != iterEnd; iter++)
				{
					std::vector<std::string> vecNameOrValue;
					nRetSplit = StringSplit(vecNameOrValue, *iter, "=");
					if (nRetSplit > 0)
					{
						NameAndValue nvNameAndValue;
						nvNameAndValue.strName = vecNameOrValue[0];
						nvNameAndValue.strValue = "";
						if (vecNameOrValue.size() > 1)
						{
							nvNameAndValue.strValue = vecNameOrValue[1];
						}
						//insert
						listRequestOperateParameter.push_back(nvNameAndValue);
					}
				}
			}
		}
		else
		{

		}
	}
	return bRet;
}
