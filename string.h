#pragma once
#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

	const size_t MAX_STRLEN = 128;

class String {
private:
	char* data;
public:
	String();
	String(const char* other_string);
	String(const String& other);
	String& operator=(const String& other);
	~String();
	void setData(char* _data);
	size_t getSize() const;
	String operator+(const String& other) const;
	void add(const String& other);
	void print() const;
	const char* str() const;
	void deserialize(std::ifstream& in);
	friend std::istream& operator >> (std::istream& in, String& string);
	friend std::ostream& operator << (std::ostream& out, const String& string);
	void readFromConsole();
private:
	void copy(const String& other);
	void clear();
};


