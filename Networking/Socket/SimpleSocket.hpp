#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

namespace NTW {
class SimpleSocket {
private:
  struct sockaddr_in address;
  int sock;
  int connection;

public:
  SimpleSocket(int domain, int service, int protocol, int port,
               u_long connect_interface);
  virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;
  void test_connection(int item_to_test);
  struct sockaddr_in get_address();
  int get_sock();
  void set_connection(int ref_connection);
};
} // namespace NTW

#endif
