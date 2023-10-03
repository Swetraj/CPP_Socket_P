#include "SimpleSocket.hpp"

namespace NTW {
class BindingSocket : public SimpleSocket {
public:
  BindingSocket(int domain, int service, int protocol, int port,
                u_long connect_interface);
  int connect_to_network(int sock, struct sockaddr_in address);
};

} // namespace NTW
