#include <csignal>
#include <signal.h>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <unistd.h>
void signal_handler(int sig) {
  switch (sig) {
  case SIGKILL: /* kill -9 {pid} */
    spdlog::debug("SIGKILL:{0}", sig);
    exit(0);
  case SIGINT: /* ctrl-\ */
    spdlog::debug("SIGINT:{0}", sig);
    exit(0);
  case SIGQUIT: /* ctrl-c */
    spdlog::debug("SIGQUIT:{0}", sig);
    exit(0);
  case SIGALRM:
    spdlog::debug("Sington alarm ");
    break;
  case SIGTSTP: /* ctrl-z */
    spdlog::debug("SIGTSTP:{0}", sig);
    break;
  default:
    break;
  }
}
int main() {
  spdlog::set_level(spdlog::level::debug);
  /* 信号需要先注册 */
  signal(SIGKILL, signal_handler);
  signal(SIGQUIT, signal_handler);
  signal(SIGINT, signal_handler);
  signal(SIGALRM, signal_handler);
  signal(SIGTSTP, signal_handler);

  while (true) {
    alarm(1); // 进程中有一个唯一计时，每次调用覆盖前面的设置
    sleep(1);
  }

  return 0;
}
