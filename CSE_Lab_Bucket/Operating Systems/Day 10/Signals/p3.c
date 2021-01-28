//Use of SIGQUIT (^C to quit process)
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void oh(int sig)
{
  printf("OH! - I got signal %d\n", sig);
  signal(SIGINT,oh);/* THIS LINE WILL CONTINUE THE EXECUTION OF FUNCTION OH */
  //signal(SIGQUIT,SIG_DFL);
}
int main()
{
  signal(SIGQUIT, oh);
  while(1)
  {
    printf("Hello World!\n");
    sleep(1);
  }
}
