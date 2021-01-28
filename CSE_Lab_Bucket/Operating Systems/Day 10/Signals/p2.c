//Use of SIG_DFL (reset to default)
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void oh(int sig)
{
  printf("OH! - I got signal %d\n", sig);
  signal(SIGINT,SIG_DFL);/*resets the signal to default*/
}
int main()
{
  signal(SIGINT, oh);
  while(1)
  {
    printf("Hello World!\n");
    sleep(1);
  }
}
