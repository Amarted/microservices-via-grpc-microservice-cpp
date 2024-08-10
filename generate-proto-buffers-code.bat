:: Run this file to genereta or regenerate the .proto files to the cpp source files.
:: Add new created .proto files generation commands in this file.

cd .\src\proto-buffers\
@set tools=..\..\vcpkg_installed\x64-windows\x64-windows\tools
@set protoc=%tools%\protobuf\protoc
@set protoc_gen_cpp_plugin=%tools%\grpc\grpc_cpp_plugin.exe

%protoc% --grpc_out=..\Api --plugin=protoc-gen-grpc=%protoc_gen_cpp_plugin% RpcApiService.proto
%protoc% --cpp_out=..\Api RpcApiService.proto