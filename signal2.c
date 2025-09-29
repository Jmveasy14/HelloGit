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

int main(int argc, char * argv[])
{
  signal(SIGALRM,alarm_handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds
  while(1){
    alarm_fired = 0;

    alarm(5);

    while (!alarm_fired){
      //waiting
    }

    printf("Turing was right\n");

  } //busy wait for signal to be delivered
  
  return 0; //never reached
}