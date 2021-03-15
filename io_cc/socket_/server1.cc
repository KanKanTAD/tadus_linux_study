#include <cassert>
#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <signal.h>
#include <spdlog/spdlog.h>
#include <sys/socket.h>
#include <unistd.h>

int ser_fd = -1;
extern void signal_handler(int);

int main(int argc, char *argv[]) {
  int port = 9090;
  if (argc >= 2) {
    port = atoi(argv[1]);
  }

  ser_fd = socket(AF_INET, SOCK_STREAM, 0);
  assert(ser_fd > 0);
  int opt = 1;
  auto setop = setsockopt(ser_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                          sizeof(opt));
  sockaddr_in ser_addr;
  assert(setop);

  return 0;
}
void signal_handler(int sig) {}
