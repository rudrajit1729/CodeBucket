#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Communication between child and parent
int main()
{
  int data_processed;
  int file_pipes[2];
  const char some_data[] = "Hello World";
  char buffer[BUFSIZ + 1];
  pid_t fork_result;
  memset(buffer, '\0', sizeof(buffer));
  if (pipe(file_pipes) == 0) 
  {
    fork_result = fork();
    if (fork_result == -1) 
    {
      fprintf(stderr, "Fork failure");
      exit(EXIT_FAILURE);
    }
    else if (fork_result == 0) //Child
    {
      sleep(2);
      data_processed = read(file_pipes[0], buffer, BUFSIZ);
      printf("Read %d bytes: %s\n", data_processed, buffer);
      exit(EXIT_SUCCESS);
    }
    else //Parent
    {
      data_processed = write(file_pipes[1], some_data,
      strlen(some_data));
      printf("Wrote %d bytes\n", data_processed);
    }
  }
  exit(EXIT_SUCCESS);
}