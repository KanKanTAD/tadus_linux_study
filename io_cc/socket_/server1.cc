#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <signal.h>
#include <spdlog/spdlog.h>
#include <sys/socket.h>
#include <unistd.h>

int ser_fd = -1;
void singal_handler(int sig) {
  switch (sig) {
  case SIGKILL:
  case SIGINT:
  case SIGQUIT:
    spdlog::info("quit!");
    if (ser_fd != -1) {
      close(ser_fd);
    }
    exit(0);
  default:
    break;
  }
}

int main(int argc, char **argv) {
  signal(SIGKILL, singal_handler);
  signal(SIGQUIT, singal_handler);
  signal(SIGINT, singal_handler);
  int port = 9999;
  if (argc >= 2) {
    port = atoi(argv[1]);
  }
  sockaddr_in ser_addr;

  if ((ser_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    spdlog::error("create socket error!");
    return 0;
  }
  bzero(&ser_addr, sizeof(ser_addr));
  ser_addr.sin_family = AF_INET;
  ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  ser_addr.sin_port = htons(htons(port));

  socklen_t addr_len = sizeof(ser_addr);
  if (bind(ser_fd, (sockaddr *)&ser_addr, addr_len) != 0) {
    spdlog::error("bind socket fail!");
    return 0;
  }

  if (listen(ser_fd, 256) != 0) {
    spdlog::error("listen {0} fail!", port);
    return 0;
  }

  while (true) {
    auto connfd = accept(ser_fd, nullptr, nullptr);

    char buff[1024];
    bzero(buff, sizeof(buff));
    auto n = recv(connfd, buff, 1024, 0);
    buff[n] = '\0';
    spdlog::info("got info:{0}", buff);
    close(connfd);
  }

  return 0;
}
