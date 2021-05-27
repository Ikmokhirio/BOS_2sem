#include <stdio.h>
#include <unistd.h>

int main(void)
{
  int pid = fork();

  if (pid == 0) {
	int childId = getpid();
	int parentId = getppid();
   	 printf("Children process PID: %d\n"
		"Parent process PID: %d\n", childId, parentId);
  } else if (pid > 0) {
    	printf("Parent process\n"
           	"id of process:  %d\n", pid);
  }

  return 0;
}

