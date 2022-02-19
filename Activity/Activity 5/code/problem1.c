#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void *say_hello(void *data)
{
  char *str;
  str = (char *)data;
  while (1)
  {
    printf("%s\n", str);
    sleep(1);
  }
  return (void *)0;
}

int main(int argc, char *argv[])
{
  pthread_t t1, t2;

  pthread_create(&t1, NULL, say_hello, argv[1]);
  pthread_create(&t2, NULL, say_hello, argv[2]);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}