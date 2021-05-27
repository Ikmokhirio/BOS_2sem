#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main( void ) {

  int pid = fork();
  int status;

  if(pid == 0) {
    char *cmd = "ls";
    char *argv[3] = {cmd, "-la", NULL};
    execvp(cmd, argv);
    // после exec программный код выполняться не будет, так как адресное
    // пространство перейдёт в новый процесс, где программный код начнёт
    // выполняться с функции main команды ls
  }

  // родительский поток ожидает заврешение дочернего
  wait(&status);
  return 0;
}

