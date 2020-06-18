#include "Game_Network.h"

//send the packet from sever to client
void Game_Network::sendMessageFromSeverToClient(sf::Packet packet)
{
	sf::TcpListener listener;
	sf::TcpSocket peer;
	//create a listener to listen to the port
	if (listener.listen(port) != sf::Socket::Done)
		std::cout << "listener error" << std::endl;
	//if there is a socket connect to the port, listener catch it
	if (listener.accept(peer) == sf::Socket::Done)
	{
		std::cout << "connection successful" << std::endl;
		//send packet
		peer.send(packet);
	}
}
//send the packet from the client to server
void Game_Network::sendMessageFromClientToServer(sf::Packet packet)
{
	sf::TcpSocket peer;
	//create a connect to a specified ip and port
	sf::Socket::Status status = peer.connect(ipAddress, port);
	if (status != sf::Socket::Done) {
		std::cout << "cannot connect" << std::endl;
		std::cout << "error number: " << status;
	}
	else if (status == sf::Socket::Done)
	{
		//connect success
		std::size_t received;
		std::cout << "connection successful" << std::endl;
		//send packet
		peer.send(packet);
	}
}
//receive the packet from the server to client
sf::Packet Game_Network::receiveMessageFromServerToClient()
{
	sf::Packet packet;
	sf::TcpSocket peer;
	//create a connect to a specified ip and port
	sf::Socket::Status status = peer.connect(ipAddress, port);
	if (status != sf::Socket::Done) {
		std::cout << "cannot connect" << std::endl;
		std::cout << "error number: " << status;
	}
	else if (status == sf::Socket::Done)
	{
		//connect success
		std::size_t received;
		std::cout << "connection successful" << std::endl;
		//receive packet
		peer.receive(packet);
	}
	return packet;
}
//receive the packet from the client to server
sf::Packet Game_Network::receiveMessageFromClientToServer()
{
	sf::Packet packet;
	sf::TcpListener listener;
	sf::TcpSocket peer;
	//create a listener to listen to the port
	if (listener.listen(port) != sf::Socket::Done)
		std::cout << "listener error" << std::endl;
	//if there is a socket connect to the port, listener catch it
	if (listener.accept(peer) == sf::Socket::Done)
	{
		std::cout << "connection successful" << std::endl;
		//receive packet
		peer.receive(packet);
	}
	return packet;
}