#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <unistd.h>
#include<string.h>

int pipefd[2]; //integer array for pipe file descriptors.


void task2(char *str)
{
	char* token = strtok(str," ");
	char *option = strtok(NULL," "); 
	char *args[] = {token,option,NULL};
	dup2(pipefd[0],0); //redirect read end to standard input for whats ater the pipe.
	close(pipefd[1]); //close write end of pipe.

	execvp(token,args); //execute what is after the "|" symbol.

	
}

void task1(char *str)
{
	char* token = strtok(str," ");
	char *option = strtok(NULL," "); 
	char *args[] = {token,option,NULL};
	dup2(pipefd[1],1); //redirect the standard output to the write end of the pipe.
	close(pipefd[0]); //close the read end of the pipe.
	execvp(token,args); //execute the first part of the command.
}

int main(int argc, char *argv[])
{

	
	printf("\nShell$:");
	char str[25]; 
   	scanf("%[^\n]%*c", str);
	char* token = strtok(str,"|"); //seperate input string with "|" delimiter.
	char *option = strtok(NULL,"|");
	int i=0;
	pipe(pipefd); //creating a pipe.
	pid_t pid;
	while(i == 0)
	{
		pid =fork();
		printf("Hello");
		if(pid < 0){
			perror("Fork Failed \n");
		}
		else if(pid == 0){
			printf("Hello");
			//exit(1);
			task1(token);	
			
		}
		//sleep(5);
		wait(NULL);
		task2(option);
		//scanf("To exit, enter 1 %d\n",&i);
	}

	return 0;
}
