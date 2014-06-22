// string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"string.h"


string::string()
{
	p = new char[10];
	max = 10;
	count = 0;
}
string::~string()
{
	delete[]p;
	max = count = 0;
}
string::string(char*source){
	size_t icount = 0;
	while (source[icount]!='\0')
	{
		++icount;
	}
	count = icount;
	max = count + 10;
	icount = 0;
	p = new char[max];
	while (source[icount]!='\0')
	{
		p[icount] = source[icount];
		++icount;
	}
	p[icount] = '\0';
}

string& string::operator=(string rhs){
		char* ptemp = p;
		p = new char[rhs.max];
		for (size_t i = 0; i < rhs.count; i++)
		{
			p[i] = rhs.p[i];
		}
		count = rhs.count;
		max = rhs.max;
		delete[]ptemp;
		return *this;
}


string operator+(string lhs, string rhs){
	string s = lhs;
	rhs.copy(s, rhs.size(), lhs.size());
	return s;
}
bool operator==(string lhs, string rhs){
	return lhs.equal(rhs);
}
bool operator!=(string lhs, string rhs){
	return !lhs.equal(rhs);
}
bool operator<(string lhs, string rhs){
	return lhs.less(rhs);
}
bool operator<=(string lhs, string rhs){
	return lhs.less(rhs) || lhs.equal(rhs);
}
bool operator>(string lhs, string rhs){
	return !(lhs.less(rhs) || lhs.equal(rhs));
}
bool operator>=(string lhs, string rhs){
	return !lhs.less(rhs);
}
ostream& operator<<(ostream&os, const string& rhs){
	os << rhs.data();
	return os;
}

istream& operator>>(istream&is, string rhs){
	char*ptemp = new char[4096];
	is >> ptemp;
	rhs = ptemp;
	delete[]ptemp;
	return is;
}