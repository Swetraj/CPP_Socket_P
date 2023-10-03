#include "SimpleSocket.hpp"

NTW::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port,
                                u_long connect_interface) {
  address.sin_family = domain;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(connect_interface);

  sock = socket(domain, service, protocol);
  test_connection(sock);
}

void NTW::SimpleSocket::test_connection(int item_to_test) {
  if (item_to_test < 0) {
    perror("Failed to Connect...");
    exit(EXIT_FAILURE);
  }
}

struct sockaddr_in NTW::SimpleSocket::get_address() { return address; }

int NTW::SimpleSocket::get_sock() { return sock; }

void NTW::SimpleSocket::set_connection(int ref_connection) {
  connection = ref_connection;
}
