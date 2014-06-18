
#include<iostream>

using std::ostream;
typedef unsigned int size_t;
class string
{
public:
	string();
	~string();
	string(char*source);
	
	string&operator=(string rhs);


	inline size_t size()const
	{
		return count;
	}
	inline size_t length()const{
		return count;
	}
	inline bool empty()const{
		return count == 0;
	}
	inline void reserve(size_t newsize){
		max = newsize;
		char* newp = new char[max];
		size_t i;
		for (i = 0; i < count; i++)
		{
			newp[i] = p[i];
		}
		newp[i] = '\0';
		p = newp;
	}
	inline int capacity(){
		return max - count;
	}


	char& at(size_t index)const{
		if (index>0&&index<=count)
		{
			return (*this)[--index];
		}
		throw("out of range");
	}
	inline char& operator[](size_t index)const{
		return p[--index];
	}
	inline char& front()const{
		return p[0];
	}
		
	inline char& back()const{
		return p[count-1];
	}
	char* data()const{
		return p;
	}
	string substr(size_t begin = 0, size_t end = 0){
		if (begin==0&&end==0)
		{
			return *this;
		}
		else
		{
			if (begin<0||end>this->count)
			{
				throw("out of range");
			}
			char*ptemp = new char[end - begin + 5];
			--begin;
			for (size_t i = 0; begin < end; begin++,i++)
			{
				ptemp[i] = this->p[begin];
			}
			return ptemp;
		}
	}
	size_t copy(char*&dest, size_t  size, size_t off = 0) const{
		if (off<0 || off>this->count)
		{
			throw("out of range");
		}
		char*ptemp = new char[size + 5];
		--off;
		size_t i = 0;
		for (; i < size; i++)
		{
			ptemp[i] = this->p[i+off];
		}
		delete[]dest;
		dest = ptemp;
		return i + 1;
	}
	size_t copy(string& dest, size_t  size, size_t off = 0) const{
		if (off<0 || off>this->count)
		{
			throw("out of range");
		}
		char*ptemp = new char[size + 5];
		--off;
		size_t i = 0;
		for (; i < size; i++)
		{
			ptemp[i] = this->p[i + off];
		}
		dest = ptemp;
		return i + 1;
	}

	string& insert(char c, size_t index){
		if (index<0||index>count)
		{
			throw("out of range");
		}
		if (max - count>0)
		{
			p[count + 1] = '\0';
			for (size_t i = count; i !=index; i--)
			{
				p[i] = p[i-1];
			}
			++count;
			p[index] = c;
		}
		else
		{
			char* ptemp = new char[max + 10];
			max += 10;
			ptemp[count + 1] = '\0';
			for (size_t i = count; i !=index; i++)
			{
				ptemp[i] = p[i-1];
			}
			ptemp[index] = c;
			for (size_t i = index-1; i >=0; i++)
			{
				ptemp[i] = p[i];
			}
			delete[]p;
			p = ptemp;
			++count;
		}
	}
	string& push_back(char c){
		if (max-count>0)
		{
			p[count] = c;
			p[count + 1] = '\0';
			++count;
		}
		else
		{
			char* ptemp = new char[max + 10];
			max += 10;
			for (size_t i = 0; i < count; i++)
			{
				ptemp[i] = p[i];
			}
			ptemp[count++] = c;
			ptemp[count] = '\0';
			delete[]p;
			p = ptemp;
		}
	}

	string& pop_back(char c){
		if (count=0)
		{
			throw("out of range");
		}
		p[--count] = '\0';
	}
	string& swap(string&rhs){
		char* ptemp = rhs.p;
		size_t counttemp = rhs.count;
		size_t maxtemp = rhs.max;
		rhs.p = this->p;
		rhs.count = this->count;
		rhs.max = this->max;
		this->p = ptemp;
		this->count = counttemp;
		this->max = maxtemp;
	}
	string& replace(string rhs){

	}
	string& clear(){
		p[0] = '\0';
		count = 0;
	}

	size_t find(string pattern)const{
		//int *sz_overlay = new int[count];
		////	int index = 0;
		//int overlay_value = 0;
		//sz_overlay[0] = 0;
		//for (size_t i = 1; i < count - 1; i++)
		//{
		//	if (p[overlay_value] == p[i])
		//	{
		//		overlay_value++;
		//		sz_overlay[i] = overlay_value;
		//		//			index++;
		//	}
		//	else
		//	{
		//		overlay_value = 0;
		//		//			index = 0;
		//		if (p[overlay_value] == p[i])
		//		{
		//			overlay_value++;
		//			//				index++;
		//		}
		//		sz_overlay[i] = overlay_value;
		//	}
		//}
		////
		////数组构建结束
		////
		//size_t target_index = 0;
		//size_t pattern_index = 0;
		//while (target_index <= count && pattern_index <= pattern.size())
		//{
		//	if (p[target_index] == pattern[pattern_index])
		//	{
		//		target_index++;
		//		pattern_index++;
		//	}
		//	else
		//	{
		//		pattern_index = sz_overlay[pattern_index];
		//	}
		//	if (sz_overlay[pattern_index] == -1)
		//	{
		//		target_index++;
		//	}
		//	if (pattern_index == pattern.size())
		//	{
		//		return target_index - pattern_index;
		//	}
		//}
		//delete[]sz_overlay;
		const int target_length = this->size();
		const int pattern_length = pattern.size();
		int * overlay_value = new int[pattern_length];
		overlay_value[0] = -1;
		int index = 0;
		for (int i = 1; i<pattern_length; ++i)
		{
			index = overlay_value[i - 1];
			while (index >= 0 && pattern[index + 1] != pattern[i])
			{
				index = overlay_value[index];
			}
			if (pattern[index + 1] == pattern[i])
			{
				overlay_value[i] = index + 1;
			}
			else
			{
				overlay_value[i] = -1;
			}
		}
		//match algorithm start
		int pattern_index = 0;
		int target_index = 0;
		while (pattern_index<pattern_length&&target_index<target_length)
		{
			if (p[target_index] == pattern[pattern_index])
			{
				++target_index;
				++pattern_index;
			}
			else if (pattern_index == 0)
			{
				++target_index;
			}
			else
			{
				pattern_index = overlay_value[pattern_index - 1] + 1;
			}
		}
		if (pattern_index == pattern_length)
		{
			return target_index - pattern_index;
		}
		else
		{
			return npos;
		}
		delete[] overlay_value;
		
	}
	bool equal(string rhs)const{
		if (this->count==rhs.count)
		{
			for (size_t i = 0; i < rhs.count; i++)
			{
				if (this->p[i]!=rhs[i])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
	bool less(string rhs)const{
		if (this->count<rhs.count)
		{
			return true;
		}
		else
		{
			for (size_t i = 0; i < rhs.count; i++)
			{
				if (this->p[i]<rhs[i])
				{
					return true;
				}
			}
			return false;
		}
	}
private:
	char *p;
	size_t max;
	size_t count;
	static const unsigned npos = -1;
};
string operator+(string lhs, string rhs);
bool operator==(string lhs, string rhs);
bool operator!=(string lhs, string rhs);
bool operator<(string lhs, string rhs);
bool operator<=(string lhs, string rhs);
bool operator>(string lhs, string rhs);
bool operator>=(string lhs, string rhs);
ostream& operator<<(ostream&os, string rhs);


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
	}
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
ostream& operator<<(ostream&os, string rhs){
	os << rhs.data();
	return os;
}