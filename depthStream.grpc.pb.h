// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: depthStream.proto
// Original file comments:
// Copyright 2015 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_depthStream_2eproto__INCLUDED
#define GRPC_depthStream_2eproto__INCLUDED

#include "depthStream.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace depthStream {

// The greeting service definition.
class DepthStreamService final {
 public:
  static constexpr char const* service_full_name() {
    return "depthStream.DepthStreamService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Sends a greeting
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>> DepthStreamReq(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>>(DepthStreamReqRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>> AsyncDepthStreamReq(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>>(AsyncDepthStreamReqRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>> PrepareAsyncDepthStreamReq(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>>(PrepareAsyncDepthStreamReqRaw(context, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      // Sends a greeting
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void DepthStreamReq(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::depthStream::DepthStreamRequest,::depthStream::DepthStreamRsP>* reactor) = 0;
      #else
      virtual void DepthStreamReq(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::depthStream::DepthStreamRequest,::depthStream::DepthStreamRsP>* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientReaderWriterInterface< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* DepthStreamReqRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* AsyncDepthStreamReqRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* PrepareAsyncDepthStreamReqRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>> DepthStreamReq(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>>(DepthStreamReqRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>> AsyncDepthStreamReq(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>>(AsyncDepthStreamReqRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>> PrepareAsyncDepthStreamReq(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>>(PrepareAsyncDepthStreamReqRaw(context, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void DepthStreamReq(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::depthStream::DepthStreamRequest,::depthStream::DepthStreamRsP>* reactor) override;
      #else
      void DepthStreamReq(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::depthStream::DepthStreamRequest,::depthStream::DepthStreamRsP>* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* DepthStreamReqRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* AsyncDepthStreamReqRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* PrepareAsyncDepthStreamReqRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_DepthStreamReq_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Sends a greeting
    virtual ::grpc::Status DepthStreamReq(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::depthStream::DepthStreamRsP, ::depthStream::DepthStreamRequest>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_DepthStreamReq : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_DepthStreamReq() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_DepthStreamReq() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DepthStreamReq(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::depthStream::DepthStreamRsP, ::depthStream::DepthStreamRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDepthStreamReq(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::depthStream::DepthStreamRsP, ::depthStream::DepthStreamRequest>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_DepthStreamReq<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_DepthStreamReq : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_DepthStreamReq() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc_impl::internal::CallbackBidiHandler< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context) { return this->DepthStreamReq(context); }));
    }
    ~ExperimentalWithCallbackMethod_DepthStreamReq() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DepthStreamReq(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::depthStream::DepthStreamRsP, ::depthStream::DepthStreamRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerBidiReactor< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* DepthStreamReq(
      ::grpc::CallbackServerContext* /*context*/)
    #else
    virtual ::grpc::experimental::ServerBidiReactor< ::depthStream::DepthStreamRequest, ::depthStream::DepthStreamRsP>* DepthStreamReq(
      ::grpc::experimental::CallbackServerContext* /*context*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_DepthStreamReq<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_DepthStreamReq<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_DepthStreamReq : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_DepthStreamReq() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_DepthStreamReq() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DepthStreamReq(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::depthStream::DepthStreamRsP, ::depthStream::DepthStreamRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_DepthStreamReq : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_DepthStreamReq() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_DepthStreamReq() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DepthStreamReq(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::depthStream::DepthStreamRsP, ::depthStream::DepthStreamRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDepthStreamReq(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_DepthStreamReq : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_DepthStreamReq() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc_impl::internal::CallbackBidiHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context) { return this->DepthStreamReq(context); }));
    }
    ~ExperimentalWithRawCallbackMethod_DepthStreamReq() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DepthStreamReq(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::depthStream::DepthStreamRsP, ::depthStream::DepthStreamRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* DepthStreamReq(
      ::grpc::CallbackServerContext* /*context*/)
    #else
    virtual ::grpc::experimental::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* DepthStreamReq(
      ::grpc::experimental::CallbackServerContext* /*context*/)
    #endif
      { return nullptr; }
  };
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};

}  // namespace depthStream


#endif  // GRPC_depthStream_2eproto__INCLUDED
