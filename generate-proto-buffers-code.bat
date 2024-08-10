:: Run this file to generate or regenerate the .proto files for the cpp source files. 
:: Add commands to generate newly created .proto files to this file.

cd .\src\proto-buffers\
@set tools=..\..\vcpkg_installed\x64-windows\x64-windows\tools
@set protoc=%tools%\protobuf\protoc
@set protoc_gen_cpp_plugin=%tools%\grpc\grpc_cpp_plugin.exe

%protoc% --grpc_out=..\Api\generated --plugin=protoc-gen-grpc=%protoc_gen_cpp_plugin% UserGreetingsRpcService.proto
%protoc% --cpp_out=..\Api\generated UserGreetingsRpcService.proto