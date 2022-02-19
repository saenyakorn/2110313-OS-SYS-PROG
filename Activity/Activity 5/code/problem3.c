
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void *say_hello(void *data)
{
  int index = *(int *)data;
  switch (index)
  {
  case 0:
    printf("First thread from parent process\n");
    break;
  case 1:
    printf("Second thread from parent process\n");
    break;
  case 2:
    printf("First thread from child process\n");
    break;
  case 3:
    printf("Second thread from child process\n");
    break;
  }
  return (void *)0;
}

int main(int argc, char *argv[])
{

  pid_t pid;
  int id[] = {0, 1, 2, 3};
  pid = fork();

  pthread_t t1, t2;

  // if parent
  if (pid > 0)
  {
    pthread_create(&t1, NULL, say_hello, id);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, say_hello, id + 1);
    pthread_join(t2, NULL);
  }
  // if child
  else if (pid == 0)
  {
    pthread_create(&t1, NULL, say_hello, id + 2);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, say_hello, id + 3);
    pthread_join(t2, NULL);
  }

  return 0;
}