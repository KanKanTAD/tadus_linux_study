#include <cassert>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <unistd.h>

int main(int argc, char **argv) {
  const char *lock_file = "flock.lock";
  if (argc >= 2) {
    lock_file = argv[1];
  }
  int fd = open(lock_file, O_WRONLY | O_CREAT);

  char *si_str = nullptr;
  size_t sz = 0;
  while (true) {
    assert(0 == flock(fd, LOCK_EX));
    printf("please input:\n");
    getline(&si_str, &sz, stdin);
    assert(si_str);
    write(fd, si_str, strlen(si_str));
    free(si_str);
    assert(0 == flock(fd, LOCK_UN));
    sleep(1);
  }
  return 0;
}
