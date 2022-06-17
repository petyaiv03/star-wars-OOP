#include <iostream>
#include <cstring>
#include "String.h"

String::String()
{
	data = new char[1];
	data[0] = '\0';
}

String::String(const char* other_string)
{
	if (other_string == nullptr)
	{
		data = new char[1];
		data[0] = '\0';
	}
	else {
		data = new char[strlen(other_string) + 1];
		strcpy(data, other_string);
		data[strlen(other_string)] = '\0';
	}
}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		clear();
		this->copy(other);
	}
	return *this;
}

String::~String()
{
	clear();
}

size_t String::getSize() const
{
	return strlen(data);
}

String String::operator+(const String& other) const
{
	String result(*this);
	result.add(other);
	return result;
}

void String::add(const String& other)
{
	char* array_ = new char[strlen(data) + strlen(other.data) + 1];
	strcpy(array_, data);
	strcat(array_, other.data);
	clear();
	data = array_;
}

void String::print() const
{
	std::cout << data;
}

const char* String::str() const
{
	return data;
}

void String::deserialize(std::ifstream& in)
{
	int length;
	in.read((char*)&length, sizeof(length));
	clear();
	data = new char[length];
	in.read(data, length);
}

void String::readFromConsole()
{
	std::cin.getline(data, MAX_STRLEN);
}

void String::copy(const String& other)
{
	data = new char[strlen(other.data) + 1];
	strcpy(data, other.data);
}

void String::clear()
{
	delete[] data;
}

std::istream& operator>>(std::istream& in, String& string)
{
	char array_[512];
	in >> array_;

	delete[] string.data;//iskam da iztriq na stringa koito iskam da vkaram stringa :D
	string.data = new char[strlen(array_) + 1];
	strcpy(string.data, array_);
	//in >> string.data;
	return in;
}

std::ostream& operator<<(std::ostream& out, const String& string)
{
	out << string.data;
	return out;
}