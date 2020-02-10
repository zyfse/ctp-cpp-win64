///*
//*
//* Copyright 2015 gRPC authors.
//*
//* Licensed under the Apache License, Version 2.0 (the "License");
//* you may not use this file except in compliance with the License.
//* You may obtain a copy of the License at
//*
//*     http://www.apache.org/licenses/LICENSE-2.0
//*
//* Unless required by applicable law or agreed to in writing, software
//* distributed under the License is distributed on an "AS IS" BASIS,
//* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//* See the License for the specific language governing permissions and
//* limitations under the License.
//*
//*/
//#pragma once
//#define NOMINMAX
//
//#include "stdafx.h"
//#include "main.h"
//#include "websocketpp.h"
//
//#include <algorithm>
//#include <chrono>
//#include <cmath>
//#include <iostream>
//#include <memory>
//#include <string>
//
//#include <grpc/grpc.h>
//#include <grpcpp/server.h>
//#include <grpcpp/server_builder.h>
//#include <grpcpp/server_context.h>
//#include <grpcpp/security/server_credentials.h>
//#include <grpcpp/impl/codegen/async_stream.h>
//#include "helper.h"
//#ifdef BAZEL_BUILD
//#include "examples/protos/route_guide.grpc.pb.h"
//#else
//#include "depthStream.grpc.pb.h"
//#endif;
//
//using grpc::Server;
//using grpc::ServerBuilder;
//using grpc::ServerContext;
//using grpc::ServerReader;
//using grpc::ServerReaderWriter;
//using grpc::ServerWriter;
//using grpc::Status;
//
//using depthStream::DepthStreamService;
//using depthStream::DepthStreamRequest;
//using depthStream::DepthStreamRsP;
//
//using std::chrono::system_clock;
//
//class DepthImpl final : public DepthStreamService::Service {
//private:
//	CSimpleHandler m_sh = NULL;
//	CSimpleMdHandler m_ash = NULL;
//public:
//
//	explicit DepthImpl(const std::string& db) {
//		init();
//	}
//	
//	void init() {
//		system("COLOR 0A");
//		logfile = fopen("syslog.txt", "w");
//
//		string g_chFrontaddr = getConfig("config", "FrontAddr");
//		cout << "g_chFrontaddr = " << g_chFrontaddr << "\n" << endl;
//		CTraderApi *pUserApi = new CTraderApi;//--------------------------
//		pUserApi->CreateFtdcTraderApi(".\\flow\\");
//		LOG(pUserApi->GetApiVersion());
//		cout << endl;
//		CSimpleHandler sh(pUserApi);
//		m_sh= sh;
//
//	cir:pUserApi->RegisterSpi(&sh);
//		pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);
//		pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);
//		pUserApi->RegisterFront(const_cast<char *>(g_chFrontaddr.c_str()));
//		pUserApi->Init();
//		sh.ReqAuthenticate();
//		WaitForSingleObject(g_hEvent, INFINITE);
//		sh.ReqUserLogin();
//		WaitForSingleObject(g_hEvent, INFINITE);
//
//		string g_chFrontMdaddr = getConfig("config", "FrontMdAddr");
//		cout << "g_chFrontMdaddr = " << g_chFrontMdaddr << "\n" << endl;
//		CThostFtdcMdApi  *pUserMdApi =
//			CThostFtdcMdApi::CreateFtdcMdApi(".\\flow\\md");
//		CSimpleMdHandler ash(pUserMdApi);
//		m_ash = ash;
//		pUserMdApi->RegisterSpi(&ash);
//		pUserMdApi->RegisterFront(const_cast<char *>(g_chFrontMdaddr.c_str()));
//		pUserMdApi->Init();
//		cout << "登录等待回报 \n" << endl;
//		WaitForSingleObject(xinhao, INFINITE);
//	}
//	//Status DepthStreamReq(ServerContext* context,
//	//	const depthStream::DepthStreamRequest* depthRequest,
//	//	ServerWriter<DepthStreamRsP>* writer) override {
//	//	g_writer = writer;
//
//	//	system("COLOR 0A");
//	//	logfile = fopen("syslog.txt", "w");
//
//	//	string g_chFrontaddr = getConfig("config", "FrontAddr");
//	//	cout << "g_chFrontaddr = " << g_chFrontaddr << "\n" << endl;
//	//	CTraderApi *pUserApi = new CTraderApi;//--------------------------
//	//	pUserApi->CreateFtdcTraderApi(".\\flow\\");
//	//	LOG(pUserApi->GetApiVersion());
//	//	cout << endl;
//	//	CSimpleHandler sh(pUserApi);
//
//	//cir:pUserApi->RegisterSpi(&sh);
//	//	pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);
//	//	pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);
//	//	pUserApi->RegisterFront(const_cast<char *>(g_chFrontaddr.c_str()));
//	//	pUserApi->Init();
//	//	sh.ReqAuthenticate();
//	//	WaitForSingleObject(g_hEvent, INFINITE);
//	//	sh.ReqUserLogin();
//	//	WaitForSingleObject(g_hEvent, INFINITE);
//
//	//	string g_chFrontMdaddr = getConfig("config", "FrontMdAddr");
//	//	cout << "g_chFrontMdaddr = " << g_chFrontMdaddr << "\n" << endl;
//	//	CThostFtdcMdApi  *pUserMdApi =
//	//		CThostFtdcMdApi::CreateFtdcMdApi(".\\flow\\md");
//	//	CSimpleMdHandler ash(pUserMdApi);
//	//	pUserMdApi->RegisterSpi(&ash);
//	//	pUserMdApi->RegisterFront(const_cast<char *>(g_chFrontMdaddr.c_str()));
//	//	pUserMdApi->Init();
//	//	cout << "登录等待回报 \n" << endl;
//	//	WaitForSingleObject(xinhao, INFINITE);
//	//	cout << "查询合约 \n" << endl;
//	//	sh.ReqQryInstrument();//查询合约
//	//	WaitForSingleObject(xinhao, INFINITE);
//	//	cout << "订阅行情 \n" << endl;
//	//	ash.SubscribeMarketData();//订阅行情
//	//	WaitForSingleObject(xinhao, INFINITE);
//	//	
//	//	return Status::OK;
//	//}
//
//	Status DepthStreamReq(ServerContext* context,
//		ServerReaderWriter<DepthStreamRsP, DepthStreamRequest>* stream) override {
//			g_writer = stream; 
//
//			cout << "查询合约 \n" << endl;
//			m_sh.ReqQryInstrument();//查询合约
//			WaitForSingleObject(xinhao, INFINITE);
//			cout << "订阅行情 \n" << endl;
//			m_ash.SubscribeMarketData();//订阅行情
//			WaitForSingleObject(xinhao, INFINITE);
//
//			return Status::OK;
//	}
//
//private:
//	std::vector<DepthStreamRsP> feature_list_;
//	std::mutex mu_;
//};
//
//void RunServer(const std::string& db_path) {
//	std::string server_address("0.0.0.0:50052");
//	DepthImpl service(db_path);
//
//	ServerBuilder builder;
//	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
//	builder.RegisterService(&service);
//	std::unique_ptr<Server> server(builder.BuildAndStart());
//	std::cout << "Server listening on " << server_address << std::endl;
//
//	//server->Wait();
//}
//
//int main(int argc, char** argv) {
//	// Expect only arg: --db_path=path/to/route_guide_db.json.
//	std::string db = routeguide::GetDbFileContent(argc, argv);
//	RunServer(db);
//	//websocketService();
//
//	return 0;
//}
//
//
