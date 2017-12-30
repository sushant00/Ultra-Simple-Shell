#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *delim = " \n\r\t";//space, carriage return , newline, tab

char *readCommand();
char **parseCommand(char * command);
int exec_builtins(char **args);
int exec_newprocess(char **args);

int main(){
	while(1){
		char **args;
		char *command;

		printf("sh>>>");
		command = readCommand();
		args = parseCommand(command);

		//execution
		int builtin = exec_builtins(args);
		if(!builtin)
			exec_newprocess(args);
	}
}


char *readCommand(){
	char *line = NULL;
	size_t bufsize = 40;//auto increase if required
	getline(&line, &bufsize,stdin);
	return line;
}


char **parseCommand(char * command){
	char **tokens = malloc(60*sizeof(char *));//assume max tokens = 60
	int index = 0;

	char *next = strtok(command, delim);

	while(next!=NULL && index<60){
		tokens[index++] = next;
		next = strtok(NULL, delim);
	}
	tokens[index] = 0;//end of args
	return tokens;
}



int exec_builtins(char **args) {
	char *command = args[0];

	if(strcmp(command,"cd")==0){
		chdir(args[1]);
		return 1;
	}
	else if(strcmp(command,"echo")==0){	
		printf("not implemented\n");
		return 1;
	}
	else if(strcmp(command,"exit")==0){
		exit(0);
		return 1;

	}
	else if(strcmp(command,"help")==0){
		printf("not implemented\n");
		return 1;
	}
	else if(strcmp(command,"pwd")==0){
		printf("not implemented\n");
		return 1;
	}
	return 0;
}

int exec_newprocess(char **args){
	if(fork()==0){
		execvp(args[0],args);
		exit(0);
	}else{
		wait(0);
	}
	return 0;
}

