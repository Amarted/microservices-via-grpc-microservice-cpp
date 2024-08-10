module;
#include <grpcpp/grpcpp.h>
#include "RpcApiService.grpc.pb.h"

export module Api:RpcService;

import <iostream>;
import <memory>;
import <string>;

using grpc::ServerContext;
using grpc::Status;
using Api::GrpcProto::UserGreetingsRequest;
using Api::GrpcProto::UserGreetingsResponse;

export namespace Api {
  export class RpcApiService final : public Api::GrpcProto::RcpApiService::Service {
    Status greet(
      ServerContext* context,
      const UserGreetingsRequest* request,
      UserGreetingsResponse* reply
    ) override {
      std::string prefix("Hello ");
      reply->set_greetings(prefix + request->username());
      return Status::OK;
    }
  };
}