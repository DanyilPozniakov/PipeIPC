#include <iostream>
#include "Server.h"

static const char *pipeName = R"(\\.\pipe\server_pipe)";

Server::Server()
{
    hPipe = CreateNamedPipe(
        pipeName,
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
        10,
        512,
        512,
        0,
        nullptr
    );
    if(!hPipe)
    {
        std::cerr << "CreateNamedPipe failed, error: " << GetLastError() << std::endl;
    }
    std::cout << "Server started!" << std::endl;

    if(!ConnectNamedPipe(hPipe, nullptr))
    {
        std::cerr << "ConnectNamedPipe failed, error: " << GetLastError() << std::endl;
        CloseHandle(hPipe);
    }
}

Server::~Server()
{
    CloseHandle(hPipe);
}

void Server::Run()
{
    char buffer[512];

    while(true)
    {
        DWORD bytesRead;
        BOOL success = ReadFile(hPipe, buffer, sizeof(buffer),&bytesRead, nullptr);
        if(!success)
        {
            std::cerr << "Client disconnected! " << GetLastError() << std::endl;
            break;
        }

        buffer[bytesRead] = '\0';
        std::cout << "Received: " << buffer << std::endl;

    }
    std::cerr << "Server stopped!" << std::endl;
}
