// WinSockAppServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 4096
#define DEFAULT_PORT "27015"

int recvTimeOutTCP(SOCKET socket, long sec, long usec)
{

    // Setup timeval variable
    struct timeval timeout;
    struct fd_set fds;
    // assign the second and microsecond variables
    timeout.tv_sec = sec;
    timeout.tv_usec = usec;
    // Setup fd_set structure
    FD_ZERO(&fds);
    FD_SET(socket, &fds);
    // Possible return values:
    // -1: error occurred
    // 0: timed out
    // > 0: data ready to be read
    return select(0, &fds, 0, 0, &timeout);
}

int main()
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    int selectTiming;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for the server to listen for client connections.
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    else
        printf("Server: listen() is OK, I'm listening for connections...\n");

    // Wait for a connection
    sockaddr_in client;
    int clientSize = sizeof(client);

    ClientSocket = accept(ListenSocket, (sockaddr*)&client, &clientSize);

    // While loop: accept and echo message back to client
    char buf[4096];

    while (true)
    {
        ZeroMemory(recvbuf, 4096);

        // Wait for client to send data
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult == SOCKET_ERROR)
        {
            std::cerr << "Error in recv(). Quitting" << std::endl;
            break;
        }

        if (iResult == 0)
        {
            std::cout << "Client disconnected " << std::endl;
            break;
        }

        std::cout << std::string(recvbuf, 0, iResult) << std::endl;

        std::string header = "HTTP/1.1 101 Switching Protocols\r\n"
            "Connection : upgrade\r\n"
            "Upgrade: websocket\r\n\r\n";
            

        // Echo message back to client
        send(ClientSocket, header.c_str(), header.length() + 1, 0);

    }

    // Close the socket
    closesocket(ClientSocket);

    // Cleanup winsock
    WSACleanup();

    return 0;
}

    // Set 10 seconds 10 useconds timeout

    /*selectTiming = recvTimeOutTCP(ListenSocket, 100, 0);

    if (selectTiming == -1)
        printf("\nServer: Some error encountered with code number : % ld\n", WSAGetLastError());
    else if (selectTiming == 0)
        printf("\nServer: Timeout lor while waiting you retard client!...\n");
    else {
        while (1)
        {
            // Reset the NewConnection socket to SOCKET_ERROR
            // Take note that the NewConnection socket in not listening
            ClientSocket = SOCKET_ERROR;
            // While the NewConnection socket equal to SOCKET_ERROR
            // which is always true in this case...

            while (ClientSocket == SOCKET_ERROR)
            {
                ZeroMemory(recvbuf, recvbuflen);

                // Accept a client socket
                ClientSocket = accept(ListenSocket, NULL, NULL);
                printf("\nServer: accept() is OK...\n");
                printf("Server: New client got connected, ready to receive and send data...\n");
                iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
                if (iResult > 0) {
                    printf("Bytes received: %d\n", iResult);
                    printf("Those bytes are : ");
                    for (int i = 0; i < iResult; i++)
                        printf(" % c", recvbuf[i]);
                    //printf("\");

                    // Echo message back to client
                    send(ListenSocket, recvbuf, iResult + 1, 0);
                }
                else if (iResult == 0)
                    printf("Server: Connection closed!\n");
                else {
                    printf("recv failed with error: %d\n", WSAGetLastError());

                }
            }

            // shutdown the connection since we're done
            iResult = shutdown(ClientSocket, SD_SEND);
            if (iResult == SOCKET_ERROR) {
                printf("shutdown failed with error: %d\n", WSAGetLastError());
            }

            if (recvTimeOutTCP(ListenSocket, 5, 0) == 0)
                break;

        }


    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}
*/


    // Accept a client socket
    /*ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // No longer need server socket
    closesocket(ListenSocket);

    // Receive until the peer shuts down the connection
    do {

        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);
            printf("Received text: %s", recvbuf);

            // Echo the buffer back to the sender
            iSendResult = send(ClientSocket, recvbuf, iResult, 0);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }
            printf("Bytes sent: %d\n", iSendResult);
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

    } while (iResult > 0);

    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}*/

