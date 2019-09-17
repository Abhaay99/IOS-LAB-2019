#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include<stdlib.h>
  
int main() 
{ 
    // Create a child process       
    int pid = fork(); 
  
    if (pid > 0)
	{
        	printf("Parent process\n");
		printf("ID : %d\n\n",getpid());
		exit(0);
		//sleep(5);

	} 
  
    // Note that pid is 0 in child process 
    // and negative if fork() fails 
    else if (pid == 0) 
    {
	printf("Child process\n");
	// getpid() will return process id of child process
	printf("ID: %d\n",getpid());
	// getppid() will return parent process id of child process
	printf("Parent -ID: %d\n\n",getppid());
	
        sleep(2); 
	
        printf("\nChild process \n");
	printf("ID: %d\n",getpid());
	printf("Parent -ID: %d\n",getppid());
    }
  
    return 0; 
} 
