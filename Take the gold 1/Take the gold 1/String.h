#ifndef __String__
#define __String__

#include "Vector.h"

class String{

public:

	String();
	String(const char* str);
	String(const String& str);
	~String();

private:

	unsigned int capacity = 1;
	char* buffer = nullptr;
	
public:

	unsigned int length() const;
	const char* c_str() const;
	bool empty() const;
	void clean();
	unsigned int c_capacity() const;
	void shrinktofit();
	Vector <String> tokenize(char*, int&) const;

public:

	String	operator + (const String& str);
	void operator = (const String& str);
	void operator = (const char* str);
	void operator += (const String& str);
	bool operator == (const String& str) const;
	bool operator == (const char* str) const;

};
#endif //__String__