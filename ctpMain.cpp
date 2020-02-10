/*
*
* Copyright 2015 gRPC authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/
#define NOMINMAX

#include "stdafx.h"
#include "main.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include "helper.h"
#ifdef BAZEL_BUILD
#include "examples/protos/route_guide.grpc.pb.h"
#else
#include "depthStream.grpc.pb.h"
#endif;


#include "rpc-service.cpp"

int main(int argc, char** argv) {
	// Expect only arg: --db_path=path/to/route_guide_db.json.
	//std::string db = routeguide::GetDbFileContent(argc, argv);
	//RunServer(db);

	return 0;
}
