#include "BindingSocket.hpp"
#include "SimpleSocket.hpp"
#include <sys/socket.h>

NTW::BindingSocket::BindingSocket(int domain, int service, int protocol,
                                  int port, u_long connect_interface)
    : SimpleSocket(domain, service, protocol, port, connect_interface) {
  set_connection(connect_to_network(get_sock(), get_address()));
}

int NTW::BindingSocket::connect_to_network(int sock,
                                           struct sockaddr_in address) {
  return bind(sock, (struct sockaddr *)&address, sizeof(address));
}
