//#pragma once
//#define NOMINMAX
//
//#include "CtpApiAdapter.h"
//
//CtpApiAdapter::CtpApiAdapter() {
//	init();
//}
//
//void CtpApiAdapter::init() {
//	system("COLOR 0A");
//	logfile = fopen("syslog.txt", "w");
//
//	string g_chFrontaddr = getConfig("config", "FrontAddr");
//	cout << "g_chFrontaddr = " << g_chFrontaddr << "\n" << endl;
//	CTraderApi *pUserApi = new CTraderApi;//--------------------------
//	pUserApi->CreateFtdcTraderApi(".\\flow\\");
//	LOG(pUserApi->GetApiVersion());
//	cout << endl;
//	CSimpleHandler sh(pUserApi);
//	m_sh = sh;
//
//cir:pUserApi->RegisterSpi(&sh);
//	pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);
//	pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);
//	pUserApi->RegisterFront(const_cast<char *>(g_chFrontaddr.c_str()));
//	pUserApi->Init();
//	sh.ReqAuthenticate();
//	WaitForSingleObject(g_hEvent, INFINITE);
//	sh.ReqUserLogin();
//	WaitForSingleObject(g_hEvent, INFINITE);
//
//	string g_chFrontMdaddr = getConfig("config", "FrontMdAddr");
//	cout << "g_chFrontMdaddr = " << g_chFrontMdaddr << "\n" << endl;
//	CThostFtdcMdApi  *pUserMdApi =
//		CThostFtdcMdApi::CreateFtdcMdApi(".\\flow\\md");
//	CSimpleMdHandler ash(pUserMdApi);
//	m_ash = ash;
//	pUserMdApi->RegisterSpi(&ash);
//	pUserMdApi->RegisterFront(const_cast<char *>(g_chFrontMdaddr.c_str()));
//	pUserMdApi->Init();
//	cout << "µÇÂ¼µÈ´ý»Ø±¨ \n" << endl;
//	WaitForSingleObject(xinhao, INFINITE);
//}
//
//void CtpApiAdapter::adapter(nlohmann::json json) {
//	std::string method = json["method"];
//	if (method.compare("order")) {
//		//m_sh.getUserApi()->ReqOrderInsert();
//	}
//}
