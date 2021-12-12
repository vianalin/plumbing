#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <string.h>

#define READ 0
#define WRITE 1

//design a program that uses unnamed pipes to facilitate parent/child process communication
//a pipe is a conduit in memory between 2 separate processes on the same comp
//2 ends: read end [0] and write end [1]
int main() {

	//in order to facilitate 2 way communication, you will need 2 pipes
	
	//to child
	int child[2];
	pipe(child);
	
	//to parent
	int parent[2];
	pipe(parent);
	
	int f;
	f = fork(); //creates separate process based on current one, new proc = child
	
	if(f) { 
	
		//parent
		//good idea to close the end of pipe you are not using
		close(child[READ]); 
		close(parent[WRITE]);
		
		while(1) { //if parent process ends before child, childs new parent pid is 1
		
			//constantly prompts a user for input
			printf("input: ");
			
			//sends that input to child 
			char line[20];
			fgets(line, 20, stdin);
			write(child[WRITE], line, sizeof(line)); //writing into child line in size bytes
			
			//displays the response to the user
			char s[20];
			read(parent[READ], s, sizeof(s));
			printf("response from child: %s\n", s);
		}
		
	} else {
	
		//child
		close(parent[READ]);
		close(child[WRITE]);
		
		//gets input from parent
		char s[20]; 
		while(read(child[READ], s, sizeof(s))) {
		
		//processes the input: any of a number of string processes (all caps, all lower, reverse)
			s[strlen(s) - 1] = '\0';
			strcat(s, ":)");
			s[strlen(s)] = '\0';
			
			//sends the response to parent
			write(parent[WRITE], s, strlen(s) + 1);
			s[0] = '\0';
		}
	}

	return 0; //returns 0 if pipe was created, -1 if not
}

