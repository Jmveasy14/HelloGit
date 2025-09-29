/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t alarm_fired = 0;

void alarm_handler(int signum){
  printf("Hellow World\n");
  alarm_fired =1;
}

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,alarm_handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds
  while(!alarm_fired){

  } //busy wait for signal to be delivered
  printf("Turing was right\n");
  return 0; //never reached
}