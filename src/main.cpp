#include <grpcpp/grpcpp.h>
import <iostream>;
import Utils;
import Api;
using grpc::Server;
using grpc::ServerBuilder;

int main()
{
    Utils::Screen::clear();

    std::cout << "Starting the gRPC server...\n";

    Api::RpcServer apiServer;
    apiServer.start();
    apiServer.doNotShutdown();
}
