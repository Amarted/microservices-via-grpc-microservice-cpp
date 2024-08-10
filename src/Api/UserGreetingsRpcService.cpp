module;
#include <grpcpp/grpcpp.h>
#include "generated/UserGreetingsRpcService.grpc.pb.h"

export module Api:UserGreetingsRpcService;

import <iostream>;
import <memory>;
import <string>;

using grpc::ServerContext;
using grpc::Status;
using Api::GrpcProto::UserGreetingsRequest;
using Api::GrpcProto::UserGreetingsResponse;

export namespace Api {
  export class UserGreetingsRpcService final : public Api::GrpcProto::UserGreetingRpcService::Service {
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