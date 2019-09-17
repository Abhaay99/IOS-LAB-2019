#include <string.h>
	#include <stdio.h> 
	#include <sys/types.h> 
	#include <unistd.h>  
	#include <stdlib.h> 
	#include <errno.h>   
	#include <sys/wait.h> 

	int main(int argc, char **argv){
		pid_t pid; 
	   	int status; 
		char s[100];
		while(1){
			gets(s);
			pid=fork();
			if(pid==0){

				char *args[3];
				args[0]=strtok(s," ");
				args[1]=strtok(NULL," ");
				args[2]=NULL;
				char t[100]="";
				strcat(t,"/bin/");
				strcat(t,args[0]);
	      		execle(t,args[0],args[1],args[2]); 
	      		exit(0); 
			}
			else if(pid>0){
				wait(&status);
			}
		}
	}
