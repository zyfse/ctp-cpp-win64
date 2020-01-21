// //GrpcTest.cpp : Defines the entry point for the console application.
//#define NOMINMAX
//
//#include "stdafx.h"
//#include "main.h"
//
//#include <iostream>
//#include <memory>
//#include <string>
//
//#include <grpc++/grpc++.h>
//
//#include "depth.grpc.pb.h"
//
//
//using grpc::Server;
//using grpc::ServerBuilder;
//using grpc::ServerContext;
//using grpc::Status;
//using depth::DepthRequest;
//using depth::DepthRsP;
//using depth::DepthService;
//
//// Logic and data behind the server's behavior.
////別眼花，重點就在這裡而已，其他地方都是來亂的
//class GreeterServiceImpl final : public DepthService::Service {
//	Status DepthReq(ServerContext* context, const DepthRequest* request,
//		DepthRsP* reply) override {
//		std::string prefix("Hello ");
//		reply->set_message(prefix + request->symbol());
//		return Status::OK;
//	}
//};
//
//void RunServer() {
//	std::string server_address("0.0.0.0:50051");
//	GreeterServiceImpl service;
//
//	ServerBuilder builder;
//	// Listen on the given address without any authentication mechanism.
//	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
//	// Register "service" as the instance through which we'll communicate with
//	// clients. In this case it corresponds to an *synchronous* service.
//	builder.RegisterService(&service);
//	// Finally assemble the server.
//	std::unique_ptr<Server> server(builder.BuildAndStart());
//	std::cout << "Server listening on " << server_address << std::endl;
//
//	// Wait for the server to shutdown. Note that some other thread must be
//	// responsible for shutting down the server for this call to ever return.
//	server->Wait();
//}
//
//int main(int argc, char** argv) {
//	RunServer();
//
//	return 0;
//}