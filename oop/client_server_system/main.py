import socket

class Server:
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind((host, port))
        self.server_socket.listen()

    def accept_connection(self):
        client_socket, addr = self.server_socket.accept()
        print(f"Connection from {addr}")

class Client:
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect((host, port))

# Usage
server = Server("127.0.0.1", 8080)
client = Client("127.0.0.1", 8080)
server.accept_connection()