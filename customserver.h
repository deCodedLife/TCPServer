#ifndef CUSTOMSERVER_H
#define CUSTOMSERVER_H

#include <fstream>
#include <tcpserver.h>

class CustomServer : public TCPServer
{
    using TCPServer::TCPServer;
    void HandleMessages(TCPUser client) override;

private:
    void writeToFile(std::string file_name, std::string data);

private:
    std::mutex block_file;
};

#endif // CUSTOMSERVER_H
