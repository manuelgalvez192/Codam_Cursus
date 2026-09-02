#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    // 1. create a socket --- af_inet: ipv4, sock_stream: tcp, 0: default protocol
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) // -1 would be error
    {
        std::cerr << "Error creating the socket" << std::endl;
        return 1;
    }

    // 2. Avoid "Address already in use" error on restart
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 3. Which port to listen on
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // accept conections from any IP address
    address.sin_port = htons(8080);       // the port

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        std::cerr << "Error in bind" << std::endl;
        return 1;
    }

    // 4. Listening for connections
    if (listen(server_fd, 10) < 0)
    {
        std::cerr << "Error in listen" << std::endl;
        return 1;
    }

    std::cout << "Server listening on port 8080..." << std::endl;

    // 5. Accept external connections
    int client_fd = accept(server_fd, NULL, NULL);
    std::cout << "Connected!" << std::endl;

    close(client_fd);
    close(server_fd);
    return 0;
}
