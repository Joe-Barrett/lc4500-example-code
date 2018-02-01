#ifndef LC4500_DRIVER_TCP_CLIENT_H
#define LC4500_DRIVER_TCP_CLIENT_H

class TcpClient
{

public:

    TcpClient();

    static int TCP_Connect(char *host, unsigned long int port);

    int TCP_Send(int sock, unsigned char *buffer, int length);

    int TCP_Receive(int sock, unsigned char *buffer, int length);

    int TCP_Disconnect(int sock);

private:
protected:

};

#endif //LC4500_EXPERIMENTAL_TCP_CLIENT_H
