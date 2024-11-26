#ifndef SERVER_H
#define SERVER_H

#include <windows.h>

class Server {

public:
      Server();
      ~Server();

    void Run();

private:
      HANDLE hPipe;
};




#endif //SERVER_H
