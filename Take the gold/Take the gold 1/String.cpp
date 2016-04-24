#include <stdio.h>
#include <string.h>
#include "World.h"
#include <ctype.h>
#include "string.h"

String::String(){
	capacity = 1;
	buffer = new char[capacity];
	strcpy_s(buffer, capacity, "\0");
}

String::String(const char* str){
	capacity = strlen(str) + 1;
	buffer = new char[capacity];
	strcpy_s(buffer, capacity, str);
}

String::String(const String& str){
	capacity = str.length() + 1;
	buffer = new char[capacity];
	strcpy_s(buffer, capacity, str.buffer);
}

String::~String(){
	delete[] buffer;
}

unsigned int String::length() const{
	return strlen(buffer);
}

const char* String::c_str()const{
	return buffer;
}

bool String::empty() const{
	return (length() == 0);
}

unsigned int String::c_capacity() const{
	return capacity;
}

void String::clean(){
	buffer[0] = '\0';
}

String String::operator + (const String& str){
	String temp;
	unsigned int leng1 = strlen(buffer);
	unsigned int leng2 = strlen(str.buffer);

	capacity = (leng1 + leng2 + 1);
	temp.buffer = new char[leng1 + leng2 + 1];
	strcpy_s(temp.buffer, leng1 + leng2 + 1, buffer);
	strcat_s(temp.buffer, leng1 + leng2 + 1, str.buffer);

	return temp;
}

void String::operator = (const String& str){
	if (str.capacity > capacity){
		delete[] buffer;
		capacity = str.capacity;
		buffer = new char[capacity];
	}
	strcpy_s(buffer, capacity, str.buffer);
}

void String::operator = (const char* str){
	unsigned int leng = strlen(str) + 1;
	if (str != nullptr){
		if (capacity < leng){
			delete[] buffer;
			capacity = leng;
			buffer = new char[capacity];
		}
		strcpy_s(buffer, leng, str);
	}
}

void String::operator += (const String& str){
	char* temp = nullptr;
	temp = new char[capacity];
	strcpy_s(temp, capacity, buffer);

	if (capacity < length() + str.length() + 1)
	{
		capacity = str.length() + length() + 1;
		delete[] buffer;
		buffer = new char[capacity];
	}

	strcpy_s(buffer, capacity, temp);
	strcat_s(buffer, capacity, str.buffer);
	delete[] temp;
}

bool String::operator == (const String& str) const{
	return !(_stricmp(buffer, str.buffer)); //! Not, return 0(false) if equal, not converts to 1(true).
}

bool String::operator == (const char* str) const{
	if (str != nullptr){
		return !(_stricmp(buffer, str)); //! Not, return 0(false) if equal, not converts to 1(true).
	}
	else{
		return false;
	}
}

void String::shrinktofit(){
	char *temp;
	temp = new char[length() + 1];
	strcpy_s(temp, length() + 1, buffer);
	capacity = length() + 1;
	delete[]buffer;
	buffer = new char[capacity];
	strcpy_s(buffer, capacity, temp);
}

Vector <String> String::tokenize(char* command, int& command_words) const{
	String trash;
	Vector <String> commandvector;
	char *lefttrimmed = command;
	char *lefttrimbase = command;
	unsigned int leng = length() + 1, laps = 0;
	char *commandtosplit;
	char *context;//Strtok_s variable, need it to save the state of the string he analyzes. Doesn't needed with strtok.
	
	command_words = 0;

	//trimleft
	while (*lefttrimbase++ == ' ' && *lefttrimbase);
	lefttrimbase--;
	while (*lefttrimmed++ = *lefttrimbase++);

	//Tokenize
	commandtosplit = strtok_s(command, " ,.-", &context);
	commandvector.pushback(commandtosplit);
	command_words++;
	while ((*context != NULL) && (laps < 3)){// I want 4 commands, but the first one is outside, so 3 laps in the while
		if (laps == 0){
			if (strstr(context, "gas mask") != nullptr){
				commandtosplit = "gas mask";
				trash = strtok_s(NULL, " ", &context);
				trash = strtok_s(NULL, " ", &context);
				commandvector.pushback(commandtosplit);
			}
			else if (strstr(context, "venom gas grenade") != nullptr){
				commandtosplit = "venom gas grenade";
				trash = strtok_s(NULL, " ", &context);
				trash = strtok_s(NULL, " ", &context);
				trash = strtok_s(NULL, " ", &context);
				commandvector.pushback(commandtosplit);
			}
			else if (strstr(context, "rusty katana") != nullptr){
				commandtosplit = "rusty katana";
				trash = strtok_s(NULL, " ", &context);
				trash = strtok_s(NULL, " ", &context);
				commandvector.pushback(commandtosplit);
			}
			else{
				commandtosplit = strtok_s(NULL, " ", &context);
				commandvector.pushback(commandtosplit);
			}
		}
		else{
			commandtosplit = strtok_s(NULL, " ", &context);
			commandvector.pushback(commandtosplit);
		}
		laps++;
		command_words++;
	}

	return commandvector;
}