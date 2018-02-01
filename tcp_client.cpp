#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>

#include "tcp_client.h"

TcpClient::TcpClient()
{
}

int TcpClient::TCP_Connect(char *host, unsigned long int port)
{
    struct sockaddr_in server;
    struct hostent *host_ptr;
    int sock;
    int result;

    host_ptr = gethostbyname(host);

    if (!host_ptr)
    {
        fprintf(stderr, "Invalid host name\n");
        return -1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    memcpy((char *) &server.sin_addr, host_ptr->h_addr_list[0], (size_t) host_ptr->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons((short) port);

    result = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (result < 0)
    {
        fprintf(stderr, "Unable to connect %d\n", result);
        return -1;
    }
    return sock;
}

int TcpClient::TCP_Send(int sock, unsigned char *buffer, int length)
{
    int sent = 0;
    while (sent < length)
    {
        int result = (int) send(sock, buffer + sent, (size_t) (length - sent), 0);
        if (result <= 0)
        {
            return -1;
        }
        sent += result;
    }
    return 0;
}

int TcpClient::TCP_Receive(int sock, unsigned char *buffer, int length)
{
    int received = 0;
    while (received < length)
    {
        int result = (int) recv(sock, buffer + received, (size_t) (length - received), 0);
        if (result == 0)
        {
            printf("TCP_Receive: Client has disconnected\n");
            return -1;
        }
        else if (result < 0)
        {
            printf("TCP_Receive: Error in receive\n");
            int err = errno;
            printf("ERROR #: %d\n", err);
            return -1;
        }
        received += result;
    }
    return 0;
}

int TcpClient::TCP_Disconnect(int socket)
{
    close(socket);
    return 0;
}
