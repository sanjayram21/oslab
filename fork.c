#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
  
  int r = fork();
  if( r> 0) 
  {
     wait(NULL);

    //sleep(20);
    printf("I am a parent process\n");
    printf("Parent's PID is %d\n",getpid());
    printf("Parent's Parent's PID is %d\n",getppid());

  }
  else{
    printf("I'm a child process\n");
    printf("Child's PID is %d\n",getpid());
    printf("Child's Parent's PID is %d\n",getppid());
  }        
  return 0;
}