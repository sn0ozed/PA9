#include<SFML/Network.hpp>
#include <string>
#include<iostream>
using namespace std;
class Game_Network
{
private:
	int port;
	sf::IpAddress ipAddress;
public:
	Game_Network(int p,string ip) 
	{
		//initialize the object and set ip and port
		port = p;
		ipAddress = ip;
	}
	//send the packet from sever to client
	void sendMessageFromSeverToClient(sf::Packet packet);
	//send the packet from the client to server
	void sendMessageFromClientToServer(sf::Packet packet);
	//receive the packet from the server to client
	sf::Packet receiveMessageFromServerToClient();
	//receive the packet from the client to server
	sf::Packet receiveMessageFromClientToServer();
};

