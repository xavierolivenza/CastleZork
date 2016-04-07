#ifndef __String__
#define __String__

class String{

public:

	String();
	String(const char* str);
	String(const String& str);
	~String();

private:

	char* buffer = nullptr;
	unsigned int capacity;

public:

	unsigned int length() const;
	const char* c_str() const;
	bool empty() const;
	void clean();
	unsigned int c_capacity() const;
	void tokenize(String& firstcommand, String& secondcommand, String& thirdcommand, String& fouthcommand);

public:

	String	operator + (const String& str);
	void operator = (const String& str);
	void operator = (const char* str);
	void operator += (const String& str);
	bool operator == (const String& str) const;
	bool operator == (const char* str) const;

};
#endif //__String__