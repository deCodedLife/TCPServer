#include "customserver.h"


void CustomServer::HandleMessages(TCPUser client)
{
    const std::chrono::duration thread_delay = std::chrono::milliseconds(100);
    std::cout << "[ ] New client connected" << std::endl;

    while (true)
    {
        std::this_thread::sleep_for(thread_delay);

        std::string client_message;
        bool is_quit = false;
        RecieveMessage(&client, &client_message, &is_quit);

        if (is_quit) break;
        writeToFile("log.txt", client_message + '\n');
    }
}

void CustomServer::writeToFile(std::string file_name, std::string data)
{
    std::lock_guard<std::mutex> guard(block_file);
    std::ofstream log_file;
    log_file.open(file_name, std::ios_base::app);
    log_file << data;
}
