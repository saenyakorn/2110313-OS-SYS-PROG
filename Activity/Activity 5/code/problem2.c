
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void *say_hello(void *data)
{
  int index = *(int *)data;
  printf("This is thread %d\n", index + 1);
  return (void *)0;
}

int main(int argc, char *argv[])
{
  int num_threads = 10;
  pthread_t t[num_threads];

  int i;
  for (i = 0; i < num_threads; i++)
  {
    pthread_create(&t[i], NULL, say_hello, &i);
    pthread_join(t[i], NULL);
  }

  return 0;
}