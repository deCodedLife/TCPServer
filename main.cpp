#include <iostream>

#define SERVER_HOST "127.0.0.1"
#define SERVER_PORT 5011

#include <tcpuser.h>
#include "customserver.h"

using namespace std;

int main(int argc, char **argv)
{
    uint server_port = SERVER_PORT;

    if (argc == 1) {
        std::cout << "[-] Warn! Port not specified. Default: "
                  << SERVER_PORT << " Will be used" << std::endl;
    }
    else server_port = (uint) std::atoi(argv[1]);

    TCPUser server_data = TCPUser(0, NetAddr {
        .tcp_host = SERVER_HOST,
        .tcp_port = server_port
    });

    CustomServer server(server_data);
    server.ListenAll();

    return 0;
}
