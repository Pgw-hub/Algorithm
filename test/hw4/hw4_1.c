#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND 512
#define MAX_ARG 256

void prompt(char *c_dir){
	getcwd(c_dir,MAX_COMMAND);
	printf("%s > ",c_dir);
}

void ParseCommand(char *command, int *argc, char *argv[]){
    int i = 0;
    char *temp = strtok(command, " ");
	while(temp != NULL){
        argv[i] = temp;
        temp = strtok(NULL, " ");
		i++;
    }
    *argc = i;
	argv[*argc] = NULL;
}         

int main(){
		
	char c_dir[MAX_COMMAND];
	char command[MAX_COMMAND];
	int argc = 0;
	char *argv[MAX_ARG] = { NULL };
	int f_return = -1;

	printf("Welcome to my_shell!\n");

	while(1){
		prompt(c_dir);
		fgets(command,MAX_COMMAND,stdin);
		command[strlen(command)-1] = 0;

		//parsing하기
		ParseCommand(command,&argc,argv);
		
		if(strcmp(argv[0],"exit") == 0){
			printf("BYE!\n");
			break;
		}
		else if(strcmp(argv[0],"cd") == 0){
			chdir(argv[1]);	
		}
		else{
			f_return= fork();
			if(f_return ==0){
				execvp("ls",argv);
			}
			else{
				if(strcmp(argv[argc-1],"&") != 0){
					wait(NULL);
				}
			}
		}
	}
}
