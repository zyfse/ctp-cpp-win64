//GrpcTest.cpp : Defines the entry point for the console application.
#define NOMINMAX

#include "stdafx.h"
#include "main.h"

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "depthStream.grpc.pb.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using depth::DepthStreamRequest;
using depth::DepthStreamRsP;
using depth::DepthStreamService;

// Logic and data behind the server's behavior.
//�e�ۻ������c�����@�e���ѣ������ط����ǁ�y��
class GreeterServiceImpl final : public DepthStreamService::
 {
	Status DepthStreamReq(ServerContext* context, const DepthStreamRequest* request,
		StreamObserver<DepthStreamRsP> reply) override {
		std::string prefix("Hello ");
		reply->set_message(prefix + request->symbol());
		return Status::OK;
	}
};

void RunServer() {
	std::string server_address("0.0.0.0:50051");
	GreeterServiceImpl service;

	ServerBuilder builder;
	// Listen on the given address without any authentication mechanism.
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	// Register "service" as the instance through which we'll communicate with
	// clients. In this case it corresponds to an *synchronous* service.
	builder.RegisterService(&service);
	// Finally assemble the server.
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;

	// Wait for the server to shutdown. Note that some other thread must be
	// responsible for shutting down the server for this call to ever return.
	server->Wait();
}

int main(int argc, char** argv) {
	RunServer();

	return 0;
}