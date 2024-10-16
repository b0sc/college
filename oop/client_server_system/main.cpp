#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class Server {
public:
    Server(int port) {
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == 0) {
            std::cerr << "Socket creation failed." << std::endl;
            exit(EXIT_FAILURE);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port);

        if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            std::cerr << "Bind failed." << std::endl;
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        if (listen(server_fd, 3) < 0) {
            std::cerr << "Listen failed." << std::endl;
            close(server_fd);
            exit(EXIT_FAILURE);
        }
        std::cout << "Server listening on port " << port << std::endl;
    }

    int accept_connection() {
        int addrlen = sizeof(server_addr);
        int new_socket = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            std::cerr << "Accept failed." << std::endl;
            exit(EXIT_FAILURE);
        }
        std::cout << "Connection accepted." << std::endl;
        return new_socket;
    }

    void close_server() {
        close(server_fd);
    }

private:
    int server_fd;
    struct sockaddr_in server_addr;
};

class Client {
public:
    Client(const char* server_ip, int port) {
        client_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (client_fd < 0) {
            std::cerr << "Socket creation failed." << std::endl;
            exit(EXIT_FAILURE);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);

        if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
            std::cerr << "Invalid address." << std::endl;
            exit(EXIT_FAILURE);
        }

        if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            std::cerr << "Connection failed." << std::endl;
            close(client_fd);
            exit(EXIT_FAILURE);
        }
        std::cout << "Connected to server at " << server_ip << ":" << port << std::endl;
    }

    void close_client() {
        close(client_fd);
    }

    int get_socket() const {
        return client_fd;
    }

private:
    int client_fd;
    struct sockaddr_in server_addr;
};

void run_server() {
    Server server(8080);

    int client_socket = server.accept_connection();

    // Communication with the client
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    std::cout << "Message from client: " << buffer << std::endl;

    const char *message = "Hello from server";
    send(client_socket, message, strlen(message), 0);
    std::cout << "Message sent to client." << std::endl;

    close(client_socket);
    server.close_server();
}

void run_client() {
    Client client("127.0.0.1", 8080);

    const char *message = "Hello from client";
    send(client.get_socket(), message, strlen(message), 0);
    std::cout << "Message sent to server." << std::endl;

    char buffer[1024] = {0};
    read(client.get_socket(), buffer, 1024);
    std::cout << "Message from server: " << buffer << std::endl;

    client.close_client();
}

int main() {
    int choice;
    std::cout << "Select mode:\n1. Server\n2. Client\nChoice: ";
    std::cin >> choice;

    if (choice == 1) {
        run_server();
    } else if (choice == 2) {
        run_client();
    } else {
        std::cerr << "Invalid choice." << std::endl;
    }

    return 0;
}
