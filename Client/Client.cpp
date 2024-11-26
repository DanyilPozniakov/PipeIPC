#include <iostream>
#include <string>
#include "Client.h"

static const char *pipeName = R"(\\.\pipe\server_pipe)";

Client::Client()
{
    hPipe = CreateFile(
        pipeName,
        GENERIC_ALL,
        0,
        nullptr,
        OPEN_EXISTING,
        0,
        nullptr
    );

    if(hPipe == INVALID_HANDLE_VALUE)
    {
        std::cerr << "CreateFile failed, error: " << GetLastError() << std::endl;
    }
}

Client::~Client()
{
    CloseHandle(hPipe);
}

void Client::Run()
{
    std::string message;

    while(true)
    {
        std::cout << "Enter message: ";
        std::getline(std::cin, message);

        DWORD bytesWritten;
        WriteFile(hPipe, message.c_str(), message.size(), &bytesWritten, nullptr);
    }
}


