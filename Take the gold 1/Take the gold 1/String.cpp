#include <stdio.h>
#include <string.h>
#include "World.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

String::String(){
	capacity = 2;
	buffer = new char[capacity];
	strcpy_s(buffer, capacity, " ");
}

String::String(const char* str){
	unsigned int leng = strlen(str) + 1;
	capacity = leng;
	buffer = new char[capacity];
	strcpy_s(buffer, capacity, str);
}

String::String(const String& str){
	unsigned int leng = str.length() + 1;
	capacity = leng;
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
	String temp(" ");
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
	unsigned int leng1 = strlen(buffer);
	unsigned int leng2 = strlen(str.buffer);

	if (capacity < (leng1 + leng2 + 1)){
		char *temp = nullptr;
		temp = new char[leng1 + 1];
		strcpy_s(temp, leng1 + 1, buffer);
		delete[]buffer;
		leng1 = strlen(temp) + strlen(str.buffer) + 1;
		capacity = leng1;
		buffer = new char[leng1];
		strcpy_s(buffer, leng1, temp);
		strcat_s(buffer, leng1, str.buffer);
	}
	else{
		strcat_s(buffer, strlen(buffer), str.buffer);
	}
}

bool String::operator == (const String& str) const{
	return !(strcmp(str.buffer, buffer)); //! Not, return 0(false) if equal, not converts to 1(true).
}

bool String::operator == (const char* str) const{
	if (str != nullptr){
		return !(strcmp(buffer, str)); //! Not, return 0(false) if equal, not converts to 1(true).
	}
	else{
		return false;
	}
}

void String::tokenize(String& firstcommand, String& secondcommand, String& thirdcommand, String& fouthcommand){
	String buffercopy;
	unsigned int leng = length() + 1;
	char *context;//Strtok_s variable, need it to save the state of the string he analyzes. Doesn't needed with strtok.
	buffercopy.buffer = new char[capacity];
	buffercopy = buffer;

	char *check;
	firstcommand = strtok_s(buffer, " ", &context);
	check = context;
	if (strtok_s(NULL, " ", &check) != NULL){
		secondcommand = strtok_s(NULL, " ", &context);
		check = context;
		if (strtok_s(NULL, " ", &check) != NULL){
			thirdcommand = strtok_s(NULL, " ", &context);
			check = context;
			if (strtok_s(NULL, " ", &check) != NULL){
				fouthcommand = strtok_s(NULL, " ", &context);
			}
			else{
				fouthcommand.clean();
			}
		}
		else{
			thirdcommand.clean();
		}
	}
	else{
		secondcommand.clean();
	}

	printf("Dins string.\n");
	printf("firstcommand: '%s'\n", firstcommand.c_str());
	printf("secondcommand: '%s'\n", secondcommand.c_str());
	printf("thirdcommand: '%s'\n", thirdcommand.c_str());
	printf("fouthcommand: '%s'\n", fouthcommand.c_str());
}