#include <stdio.h>

//design a program that uses unnamed pipes to facilitate parent/child process communication
int plumbing() {
	//in order to facilitate 2 way communication, you will need 2 pipes
	int input[2];
	int output[2];
	pipe(input);
	pipe(output);
	
	//parent
		//constantly prompts a user for input 
		//sends that input to child 
		//waits for a response 
		//displays the response to the user
	
	//child
		//gets input from parent
		//processes the input: any of a number of string processes (all caps, all lower, reverse)
		//sends the response to parent
		
	
