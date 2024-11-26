cmake_minimum_required(VERSION 3.29)
project(PipeIPC)

set(CMAKE_CXX_STANDARD 23)

add_executable(Server Server/main.cpp Server/Server.cpp)
add_executable(Client Client/main.cpp Client/Client.cpp)

target_include_directories(Server PUBLIC Server/Server.h)
target_include_directories(Client PUBLIC Client/Client.h)
