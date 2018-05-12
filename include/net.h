#include <boost/asio.hpp>

#ifndef NET_H
#define NET_H


namespace net{

class server{
	typedef boost::asio::ip::udp::socket socket;

	boost::asio::io_service ios;
	socket sock;

public:
	server(unsigned int port);

private:
};

class client{
};

}


#endif
