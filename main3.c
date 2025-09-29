#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>


void child_task(void);

int main(void){
  pid_t pid;
  int i;

  srandom(time(NULL));

  for (i = 0; i < 2; i++) {
    pid = fork();

    if (pid == 0){
      child_process();
    }else if (pid < 0) {
      perror("fork");
      exit(1);

    }
  }
  for (i = 0; i < 2; i++){
    int status;
    pid_t completed_pid = wait (&status);

    printf("Child Pid: %d has completed\n", completed_pid);

  }
  return 0;

}


void child_task(void){

  int iterations = (random() % 30) + 1;

  for (int i = 1; i<= iterations; i++) {
    printf("Child Pid %d is going to sleep!\n", getpid());

    int sleep_time = (random() %10) +1;
    sleep(sleep_time);

    printf("Child Pid: %d is awake! Where is my Parent: %d?\n", getpid(), getppid());
  }
  exit
}

void child_process();
// parent process
int main (){
  int pid;
  int i; 
  for (i = 0; i<2; i++){
    pid = fork(); // stores two child pids
    if (pid == 0) 
				child_process();
    else if (pid<0) 
				exit(1);
  }

  for (i=0; i < 2; i++){
    int status;
    int completed_pid = wait(&status);
    printf("Child Pid: %d has completed with exit status: %d\n", completed_pid, status);
  }
}

// run one child process
void child_process(){
  int pid = getpid();
  int parent_pid = getppid();
  srandom(pid % 42); // seeding random number
  int n = 1 + (random() % 30); // random number no more than 30
  int i;
  for (i=0; i < 2; i++){
    int time = 1 + (random() % 10); // sleep time no more than 10 seconds
    printf("Child Pid: %d is going to sleep for %d seconds!\n", pid, time);
    sleep(time); // sleep
    printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", pid, parent_pid); // print if awake
  }
  exit(0);
}


