#include <cassert>
#include <cstring>
#include <pthread.h>
#include <spdlog/spdlog.h>
#include <sys/file.h>
#include <unistd.h>

int main(int argc, char **argv) {
  static char si_str[1024];
  static char buff[128];
  const char *lock_file = "flock.lock";
  if (argc >= 2) {
    lock_file = argv[1];
  }
  int fd = open(lock_file, O_RDWR | O_CREAT);
  assert(fd > 0);

  bzero(si_str, sizeof(si_str));
  bzero(buff, sizeof(buff));
  assert(0 == flock(fd, LOCK_SH));
  int rd = 0;
  while ((rd = read(fd, buff, sizeof(buff) - 1)) > 0) {
    buff[rd] = '\0';
    strcat(si_str, buff);
  }
  spdlog::info("read : {0}", si_str);
  assert(0 == flock(fd, LOCK_UN));
  close(fd);
  return 0;
}
