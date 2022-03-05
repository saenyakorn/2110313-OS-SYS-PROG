#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    int r = sem_unlink("pabx");
}
