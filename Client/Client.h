#ifndef CLIENT_H
#define CLIENT_H

#include <windows.h>

class Client {
public:
    Client();
    ~Client();

    void Run();

private:
    HANDLE hPipe = {};

};



#endif //CLIENT_H
