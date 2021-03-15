#include <sys/socket.h>
#include <unistd.h>

int main() {
  int cli_fd;

  cli_fd = socket(AF_INET, SOCK_STREAM, 0);

  close(cli_fd);

  return 0;
}
