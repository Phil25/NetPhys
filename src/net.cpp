#include "../include/net.h"

using boost::asio::ip::udp;

net::server::server(unsigned int port):
	ios(),
	sock(ios, udp::endpoint(udp::v4(), port))
{}
