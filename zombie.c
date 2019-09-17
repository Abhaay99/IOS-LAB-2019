#include<stdio.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    // Fork returns process id 
    // in parent process 
    pid_t child_pid = fork(); 
  
    // Parent process  
    if (child_pid > 0)
	{
		printf("Parent ID : %d\n",getpid());
        	sleep(5);
printf("Parent ID : %d\n",getpid());
	}	
  
    // Child process 
    else if(child_pid==0)
	{
		printf("Child ID : %d\n",getpid());
		exit(0);
        }
   
  
    return 0; 
}
