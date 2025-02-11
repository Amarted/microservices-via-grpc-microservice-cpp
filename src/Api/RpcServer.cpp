module;
#include <grpcpp/grpcpp.h>
#include "generated/UserGreetingsRpcService.grpc.pb.h"
#include <memory>
#include <string>

export module Api:Server;
import :UserGreetingsRpcService;
import <iostream>;
using grpc::Server;
using grpc::ServerBuilder;

export namespace Api {
  export class RpcServer {
  private:
    std::string serverAddress = "0.0.0.0:50051";
    std::unique_ptr<Server> server;

  public:
    void start() {
      server = createServer(serverAddress);
      displayStatus();
    }

    void doNotShutdown() {
      server->Wait();
    }

  private:
    std::unique_ptr<grpc::Server> createServer(std::string serverAddress) {
      UserGreetingsRpcService service;
      grpc::ServerBuilder builder;
      builder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
      builder.RegisterService(&service);

      return builder.BuildAndStart();
    }

    void displayStatus() const {
      std::cout << "Server listening on " << serverAddress << std::endl;
    }
  };
}
