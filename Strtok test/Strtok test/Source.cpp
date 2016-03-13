#include <stdio.h>
#include <string.h>

void move(){
	char fullcommand[20];
	char firstcommand[10];
	char secondcommand[10];
	char command[10];
	char *context;//Strtok_s variable, need it to save the state of the string he analyzes. Doesn't needed with strtok.
	printf("What do you want to do?\n");
	gets_s(fullcommand);
	strcpy_s(firstcommand, strtok_s(fullcommand, " ", &context));
	strcpy_s(secondcommand, strtok_s(NULL, " ", &context));
	// --------------------------------------------------------------------------------------------------------------
	printf("command1: %s\n", firstcommand);
	printf("command2: %s\n", secondcommand);
}

int main(){
	move();
	getchar();
	return 0;
}