#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
  void *small, *large, *map;
  FILE *fp; // file pointer
  int fd;   // file descriptor
  int i;
  char x;

  int FILESIZE = (1024 * 1024);
  char *FILENAME = "mmap.dat";
  char *data = "just monika ";
  int len;

  printf("Program starts. Press Enter to continue.\n");
  getchar();

  small = malloc(1 << 10);
  printf("Allocated memory 1 KB\n");
  getchar();

  memset(small, 1, (1 << 10));
  printf("Access memory 1 KB\n");
  getchar();

  large = malloc(1 << 20);
  printf("Allocated memory 1 MB\n");
  getchar();

  memset(large, 1, (1 << 20));
  printf("Access memory 1 MB\n");
  getchar();

  // Create a file with specified size
  fp = fopen(FILENAME, "w+");
  if (fp)
  {
    fseek(fp, FILESIZE - 1, SEEK_SET);
    fwrite("", 1, sizeof(char), fp);
    fclose(fp);
  }
  else
  {
    perror("fopen");
    exit(-1);
  }
  printf("Create file\n");
  getchar();

  fd = open(FILENAME, O_RDWR);
  if (fd == -1)
  {
    perror("open");
    exit(-1);
  }

  printf("Open file\n");
  getchar();

  // Memory map to file
  map = mmap(NULL, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (map == MAP_FAILED)
  {
    perror("mmap");
    exit(-1);
  }
  printf("Create memory map\n");
  getchar();

  // Write to memory map
  len = strlen(data);
  for (i = 0; i < FILESIZE / len; i++)
  {
    strcpy((char *)map + (i * len), data);
  }
  printf("Access Memory map. You can see data in the file.\n");
  getchar();

  free(small);
  free(large);
  munmap(map, FILESIZE);
  printf("Free memory\n");
  getchar();

  printf("End\n");
}
