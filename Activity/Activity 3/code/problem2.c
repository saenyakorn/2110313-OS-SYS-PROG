#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  int i;
  int n;
  pid_t childpid;

  n = 4;
  for (i = 0; i < n; ++i)
  {
    // clone
    childpid = fork();
    // id == 0 if it is a child
    if (childpid > 0)
    {
      break;
    }
  }
  wait(0); // waits for child to change state (in this case, terminate) before continuing
  printf("This is process %ld with parent %ld\n", (long)getpid(), (long)getppid());
  return 0;
}
