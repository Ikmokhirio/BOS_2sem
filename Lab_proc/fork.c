#include <stdio.h>
#include <unistd.h>

int main(void)
{
  int pid = fork();

  if (pid == 0) {
    printf("Children process\n");
  } else if (pid > 0) {
    printf("Parent process\n"
           "id of process:  %d\n", pid);
  }

  return 0;
}

