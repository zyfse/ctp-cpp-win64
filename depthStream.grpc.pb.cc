// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: depthStream.proto

#include "depthStream.pb.h"
#include "depthStream.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace depthStream {

static const char* DepthStreamService_method_names[] = {
  "/depthStream.DepthStreamService/DepthStreamReq",
};

std::unique_ptr< DepthStreamService::Stub> DepthStreamService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< DepthStreamService::Stub> stub(new DepthStreamService::Stub(channel));
  return stub;
}

DepthStreamService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_DepthStreamReq_(DepthStreamService_method_names[0], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::ClientReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* DepthStreamService::Stub::DepthStreamReqRaw(::grpc::ClientContext* context) {
  return ::grpc_impl::internal::ClientReaderWriterFactory< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>::Create(channel_.get(), rpcmethod_DepthStreamReq_, context);
}

void DepthStreamService::Stub::experimental_async::DepthStreamReq(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::depthStream::DepthStreamRequest,::depthStream::DepthStreamRsP>* reactor) {
  ::grpc_impl::internal::ClientCallbackReaderWriterFactory< ::depthStream::DepthStreamRequest,::depthStream::DepthStreamRsP>::Create(stub_->channel_.get(), stub_->rpcmethod_DepthStreamReq_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* DepthStreamService::Stub::AsyncDepthStreamReqRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc_impl::internal::ClientAsyncReaderWriterFactory< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>::Create(channel_.get(), cq, rpcmethod_DepthStreamReq_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* DepthStreamService::Stub::PrepareAsyncDepthStreamReqRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncReaderWriterFactory< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>::Create(channel_.get(), cq, rpcmethod_DepthStreamReq_, context, false, nullptr);
}

DepthStreamService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DepthStreamService_method_names[0],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< DepthStreamService::Service, ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>(
          std::mem_fn(&DepthStreamService::Service::DepthStreamReq), this)));
}

DepthStreamService::Service::~Service() {
}

::grpc::Status DepthStreamService::Service::DepthStreamReq(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::depthStream::DepthStreamRsP, ::depthStream::DepthStreamRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace depthStream
