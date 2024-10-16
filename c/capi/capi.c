#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <time.h>


// server port number
#define PORT 8080
// maximum buffer size for reading response (incerement as per need)
#define BUFFER_SIZE 1024
// maximum number of requests to queue at once before refuseing new connection
#define MAX_CONCURRENT_REQUESTS 10
// printf but for printing into a string variable
#define print_to_string_var snprintf
// find the index of string in given string
// similar to finding needle in haystack
#define find_index_in_of(haystack,needle) strstr((haystack),(needle))

void respond(int client_fd,int status_code,const char *content_type,const char *data){
    char *status;
    if(status_code>=200 && status_code < 300){
        status = "OK";
    }else if (status_code == 404){
        status = "Not Found";
    }else{
        status = "Error";
    }
    char response_buffer[BUFFER_SIZE];
    /*
        HTTP -> protocal name, http
        1.1  -> http version
        %d   -> status code (200,302,404,..)
        %s   -> Status code Text
        \r\n -> data splitter for http data encoding,
                similar to ',' is data splitter in CSV data format
        -- now we put headers
        Content-Type -> header name that hints the browser how to render the content
        %s           -> content type value formator
        
        -- end of headers
        \r\n\r\n  -> two consecutive splitters denote end of headers and remaning
                    contents are treated as response body or response content
        %s   -> response content 
    */
    const char *response_fmt = "HTTP/1.1 %d %s\r\nContent-Type: %s\r\n\r\n%s";
    print_to_string_var(response_buffer,sizeof(response_buffer),response_fmt,status_code,status,content_type,data);
    send(client_fd, response_buffer, strlen(response_buffer), 0);

}

void send_text_response(int client_fd, int status_code, const char *text) {
    respond(client_fd,status_code, "text/plain",text);
}


void send_json_response(int client_fd, int status_code, const char *jsonText) {
    respond(client_fd,status_code, "application/json",jsonText);
}

void handle_request(int client_fd) {
    
    char buffer[BUFFER_SIZE];
    read(client_fd, buffer, sizeof(buffer) - 1);
    buffer[BUFFER_SIZE - 1] = '\0'; // Null terminate the string

    if (find_index_in_of(buffer, "GET /status") != NULL) {
        send_json_response(client_fd, 200,"{\"status\": \"running\"}");
    } 
    else if (find_index_in_of(buffer, "POST /echo") != NULL) {
        char *body = find_index_in_of(buffer, "\r\n\r\n");
        if (body) {
            body += 4; // Move past the \r\n\r\n
            send_text_response(client_fd,200,body);
        }
    } 
    else if (find_index_in_of(buffer, "GET /time") != NULL) {
        
        // get current time
        time_t now = time(0);
        // convert time to string
        char *time_str = ctime(&now);
        // replace the \n [newline] with null (0) 
        time_str[strlen(time_str) - 1] = '\0';

        char jsonText[BUFFER_SIZE];
        // print the json string to jsonText var
        print_to_string_var(jsonText, sizeof(jsonText), "{\"time\": \"%s\"}", time_str);
        
        send_json_response(client_fd, 200,jsonText);
    } 
    else {
        send_text_response(client_fd,404,"404 Not Found");
    }

    close(client_fd);
}

int main() {
    // server and client file-descriptor(fd)
    int server_fd, client_fd;
    // struct that holds the connection information
    struct sockaddr_in server_addr, client_addr;

    socklen_t client_addr_len = sizeof(client_addr);

    /*
    // Create socket
    int socket(int domain, int type, int protocol);
    
    //Args
    --domain-- (determines the communication domain; this selects the protocol family)
     Name         Purpose
     AF_UNIX      Local communication
     AF_LOCAL     Synonym for AF_UNIX
     AF_INET      IPv4 Internet protocols
     AF_AX25      Amateur radio AX.25 protocol
     AF_IPX       IPX - Novell protocols
     AF_APPLETALK AppleTalk
     AF_X25       ITU-T X.25 / ISO-8208 protocol
     AF_INET6     IPv6 Internet protocols
     AF_DECnet    DECet protocol sockets
     ....etc
    
    --type-- (specifies the communication semantics)
     Name             Purpose
     SOCK_STREAM      Provides a reliable, ordered communication channel like a phone call (TCP)
     SOCK_DGRAM       Provides a reliable, ordered communication channel like a phone call (UDP)
     SOCK_SEQPACKET   Combines reliability and ordered delivery for distinct packets, like sending packages with tracking (websocket)
     SOCK_RAW         Allows full control over network data, akin to sending a letter directly to the post office. (user has fullcontrol)
     SOCK_PACKET      Facilitates low-level networking by sending raw packets, similar to special delivery services. ( user has control over packets)
     ....etc

    --protocol-- (specifies a particular protocol to be used with the socket)
    it's `0` for most cases as only single protocol is used in a socket

    See `man 2 socket` (linux/unix) for more information or 
    visit `https://www.man7.org/linux/man-pages/man2/socket.2.html` for windows user
    */
    // create a ip socket with TCP connection 
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        return 1;
    }

    // Start listening for incoming connections
    listen(server_fd, MAX_CONCURRENT_REQUESTS);
    printf("Server is listening on port http://0.0.0.0:%d\n", PORT);

    while (1) {
        // wait for client requests
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }

        handle_request(client_fd);
    }

    // Close server socket (unreachable in this example)
    close(server_fd);
    return 0;
}
