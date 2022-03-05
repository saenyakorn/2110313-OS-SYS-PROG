#include <stdio.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int num_lines = 2;
	if (argc > 1)
		num_lines = atoi(argv[1]);
	printf("Starting PABX with %d phone lines.\n", num_lines);

	//
	// OS -- CRAETE NAMED SEMAPHORE HERE
	//
	sem_t *phone_lines = sem_open("phone_lines", O_CREAT, 0644, num_lines);

	int semval;
	while (1)
	{

		//
		// OS -- PLACE CURRENT VALUE OF SEMAPHORE IN 'semval' HERE
		//
		int status = sem_getvalue(phone_lines, &semval);

		printf("status: %d, There are %d phone lines available.\n", status, semval);
		sleep(3);
	}
}
