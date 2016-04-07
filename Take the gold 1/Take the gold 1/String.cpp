#include <stdio.h>
#include <string.h>
#include "World.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

	/*
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
	*/
}

bool String::operator == (const String& str) const{
	return !(strcmp(buffer, str.buffer)); //! Not, return 0(false) if equal, not converts to 1(true).
}

bool String::operator == (const char* str) const{
	if (str != nullptr){
		return !(strcmp(buffer, str)); //! Not, return 0(false) if equal, not converts to 1(true).
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

void String::tokenize(String& firstcommand, String& secondcommand, String& thirdcommand, String& fourthcommand){
	String buffercopy;
	unsigned int leng = length() + 1;
	char *context;//Strtok_s variable, need it to save the state of the string he analyzes. Doesn't needed with strtok.
	buffercopy.buffer = new char[capacity];
	buffercopy = buffer;

	firstcommand = strtok_s(buffercopy.buffer, " ,.-", &context);
	if (*context != NULL){
		secondcommand = strtok_s(NULL, " ", &context);
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