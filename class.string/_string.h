#pragma once

#ifndef SRING_H
#define STRING_H
#include <iostream>

using namespace std;


class _string
{
	char*str;
	int length;
public:
	_string();
	_string(int length);
	_string(const char*str);
	_string(const _string &obj);


	int getLength();
	const char* getString();
	void setString(const char*str);
	void input();
	void clear();
	void output();

	~_string();
};

#endif // !SRING_H