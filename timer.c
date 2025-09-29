/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

time_t start_time;

void ctrl_c_handler(int signum){
  time_t end_time = time(NULL);

  // calculate the diff vetween end and start time
  double elapsed_time = difftime(end_time, start_time);

  printf("\nCTRL-C received. Exiting.\n");
  printf("Total execution time: %.0f seconds.\n", elapsed_time);

  exit(0);
}

void alarm_handler(int signum){
  alarm(1);
}

int main(int argc, char * argv[])
{
  start_time = time(NULL);

  signal(SIGNT, ctrl_c_handler);

  signal(SIGALRM, alarm_handler);

  alarm(1);

  printf("Time started. Press CTRL-C to exit.\n");
  while(1){
    //wait for signals
  }
  return 0;
}