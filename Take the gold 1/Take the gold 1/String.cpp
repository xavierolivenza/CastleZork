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

void String::trim(){
	char *lefttrimmed = buffer;
	char *lefttrimbase = buffer;
	//trimleft
	while (*lefttrimbase++ == ' ' && *lefttrimbase);
	lefttrimbase--;
	while (*lefttrimmed++ = *lefttrimbase++);
}

void String::getcommand(){
	char command[50];
	printf("What do you want to do?\n");
	gets_s(command);
	unsigned int leng = strlen(command) + 1;
	if (capacity < leng){
		delete[] buffer;
		capacity = leng;
		buffer = new char[capacity];
	}
	strcpy_s(buffer, capacity, command);
}

void String::tokenize(String& firstcommand, String& secondcommand, String& thirdcommand, String& fourthcommand) const{
	String buffercopy;
	String trash;
	unsigned int leng = length() + 1;
	char *context;//Strtok_s variable, need it to save the state of the string he analyzes. Doesn't needed with strtok.
	buffercopy.buffer = new char[capacity];
	buffercopy = buffer;
	
	//Tokenize
	firstcommand = strtok_s(buffercopy.buffer, " ,.-", &context);
	if (*context != NULL){
		if (strstr(context, "gas mask") != nullptr){
			secondcommand = "gas mask";
			trash = strtok_s(NULL, " ", &context);
			trash = strtok_s(NULL, " ", &context);
		}
		else if (strstr(context, "venom gas grenade") != nullptr){
			secondcommand = "venom gas grenade";
			trash = strtok_s(NULL, " ", &context);
			trash = strtok_s(NULL, " ", &context);
			trash = strtok_s(NULL, " ", &context);
		}
		else{
			secondcommand = strtok_s(NULL, " ", &context);
		}
		if (*context != NULL){
			thirdcommand = strtok_s(NULL, " ", &context);
			if (*context != NULL){
				fourthcommand = strtok_s(NULL, " ,.-", &context);
			}
			else{
				fourthcommand.clean();
			}
		}
		else{
			thirdcommand.clean();
			fourthcommand.clean();
		}
	}
	else{
		secondcommand.clean();
		thirdcommand.clean();
		fourthcommand.clean();
	}
	firstcommand.shrinktofit();
	secondcommand.shrinktofit();
	thirdcommand.shrinktofit();
	fourthcommand.shrinktofit();
}