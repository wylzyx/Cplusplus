#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
//class String
//{
//public:
//	/*String()
//		:_str(new char[1])
//		{
//		*_str = '\0';
//		}
//
//		String(char* str)
//		:_str(new char[strlen(str) + 1])
//		{
//		strcpy(_str, str);
//		}
//		*/
//
//	String(char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//
//	/*String(const String& str)
//		:_str(new char[strlen(str._str) + 1])
//	{
//		strcpy(_str, str._str);
//	}*/
//
//	String(const String& str)
//		:_str(nullptr)
//	{
//		String tmp(str._str);
//		swap(_str, tmp._str);
//	}
//
//	/*String& operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			delete[] _str;
//			_str = new char[strlen(str._str) + 1];
//			strcpy(_str, str._str);
//		}
//		return *this;
//	}*/
//
//	String& operator=(String str)
//	{
//		//String tmp(str._str);
//		swap(_str, str._str);
//		return *this;
//	}
//	
//
//	const char* c_str() const
//	{
//		return _str;
//	}
//
//	~String()
//	{
//		if (_str)
//			delete[] _str;
//	}
//
//private:
//	char* _str;
//};
//
//void testString1()
//{
//	String s;
//	/*string s2;
//	cout << s.c_str() << endl;
//	cout << s2.c_str() << endl;
//	cout << (int*)s.c_str() << endl;
//	cout << (int*)s2.c_str() << endl;*/
//	/*cout << s2.capacity() << endl;
//	cout << s2.size() << endl;*/
//	char* str = new char[10];
//	strcpy(str, "hello");
//	String s3(str);
//
//	delete[] str;
//
//	char sarr[] = "\0";  // \0 \0
//	char sarr2[] = "\\0"; // \  0  \0
//	char sarr3[] = "\000"; // \0 \0 
//
//}
//
//void testString2()
//{
//	String s1("hello");
//	String s2 = s1;  // 拷贝构造
//	s2 = s1; // 赋值运算符
//}
//
//int main()
//{
//	//testString1();
//	testString2();
//	return 0;
//}

char* StrStr(char* dest, char* src)
{
	char* pdest = dest;
	char* psrc = src;
	while (*pdest)
	{
		if (*pdest == *psrc)
		{
			char* mdest = pdest;
			char* msrc = psrc;
			while (*mdest && *msrc)  // a,   e
			{
				if (*mdest != *msrc)
					break;
				mdest++;
				msrc++;
			}
			if (*msrc == '\0')
				return pdest;
		}
		++pdest;
	}

	return nullptr;
}

class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;

	//构造
	String(char* str = "")
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	String(const String& str)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._str);
		Swap(tmp);
	}

	void Swap(String& str)
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	//访问 非const 调用： 可读可写
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	//const 调用： 只读接口
	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}
	//返回第一个元素的位置， 可读可写
	iterator begin()
	{
		return _str;
	}
	//返回最后一个元素的下一个位置
	iterator end()
	{
		return _str + _size;
	}

	//返回第一个元素的位置， 可读可写
	const_iterator begin() const
	{
		return _str;
	}
	//返回最后一个元素的下一个位置
	const_iterator end() const
	{
		return _str + _size;
	}


	//只读
	const_iterator cbegin() const
	{
		return _str;
	}

	const_iterator cend() const
	{
		return _str + _size;
	}


	//容量
	size_t Size() const
	{
		return _size;
	}
	size_t Capacity();
	void resize(size_t sz, char c = '\0')
	{
		// sz > _capacity : 增容， 内容赋值
		if (sz > _capacity)
			reserve(sz);

		// _size < sz <= _capacity ： 内容赋值
		if (sz > _size)
		{
			memset(_str + _size, c, sz - _size);
		}
		// sz <= _size
		_size = sz;
		_str[_size] = '\0';
	}
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	const char* c_str() const
	{
		return _str;
	}

	//修改

	void push_back(char c)
	{
		////检查容量
		//if (_size == _capacity)
		//{
		//	size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
		//	reserve(newC);
		//}
		//_str[_size] = c;
		//++_size;
		//_str[_size] = '\0';
		insert(_size, c);
	}

	void Append(const char* str)
	{
		//int sz = strlen(str);
		//if (_size + sz > _capacity)
		//{
		//	reserve(_size + sz);
		//}
		//// "123\0"  + "456\0"
		//strcpy(_str + _size, str);
		//_size += sz;
		insert(_size, str);
	}

	String& operator+=(char c)
	{
		push_back(c);
		return *this;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	String& operator+=(const String&  str)
	{
		Append(str._str);
		return *this;
	}

	void insert(size_t pos, char c)
	{
		assert(pos <= _size);
		//检查容量
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//移动元素; 从后向前移动，防止覆盖
		size_t end = _size + 1;
		// end >= pos : 头插死循环
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		//插入
		_str[pos] = c;
		++_size;
	}
	void insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		int sz = strlen(str);
		if (_size + sz > _capacity)
			reserve(_size + sz);
		size_t end = _size + sz;
		while (end > pos + sz - 1)  // pos + sz
		{
			//_size  --->  _size + sz
			//pos   --->  pos + sz
			_str[end] = _str[end - sz];
			--end;
		}
		int i = 0;
		while (*str)
		{
			_str[pos + i] = *str++;
			++i;
		}
		_size += sz;
		//_str[_size] = '\0';
	}

	void erase(size_t pos, int len)
	{
		assert(pos < _size);
		// 5  10   15
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
			return;
		}
		size_t start = pos + len;
		//从前向后一次移动
		while (start <= _size)
		{
			_str[start - len] = _str[start];
			++start;
		}
		_size -= len;
	}

	void erase(iterator it)
	{
		assert(it < end() && it >= begin());
		while (it != end())
		{
			*it = *(it + 1);
			++it;
		}
		--_size;
	}

	size_t find(const char* str, size_t pos = 0)
	{
		char* start = strstr(_str + pos, str);
		if (start == nullptr)
			return npos;
		else
			return start - _str;
	}

	size_t find(char ch, size_t pos = 0)
	{
		for (int i = pos; i < _size; ++i)
		{
			if (ch == _str[i])
				return i;
		}

		return npos;
	}

	friend ostream& operator<<(ostream& _cout, const String& str);

private:
	static const size_t npos;
	char* _str;
	size_t _size;
	size_t _capacity;

};

const size_t String::npos = -1;

ostream& operator<<(ostream& _cout, const String& str)
{
	for (const auto& ch : str)
	{
		_cout << ch << " ";
	}
	_cout << "end" << endl;
	return _cout;
}

void testString1()
{
	String str("hello");
	String str2("world");
	String copy(str);
	str2 = str;
}

void testString2()
{
	String str("hello");
	for (int i = 0; i < str.Size(); ++i)
	{
		str[i] = 'a';
		cout << str[i] << " ";
	}
	cout << endl;

	//const String str2("hello");
	//for (int i = 0; i < str2.Size(); ++i)
	//{
	//	//str2[i] = 'a';
	//	cout << str2[i] << " ";
	//}
	//cout << endl;

	//范围for： 底层通过迭代器实现
	//for (const auto& ch : str)
	//{
	//	cout << ch << " ";
	//}
	//cout << endl;

	//String::iterator sit = str.begin();
	//while (sit != str.end())
	//{
	//	*sit = 'c';
	//	cout << *sit << " ";
	//	++sit;
	//}
	//cout << endl;

	//String::const_iterator csit = str.cbegin();
	//while (csit != str.cend())
	//{
	//	//*csit = 'b';
	//	cout << *csit << " ";
	//	++csit;
	//}
	//cout << endl;
}

void testString3()
{
	String s("hello");
	s.push_back('w');
	s.Append("orld 1234567890");
	s += 'a';
	s.operator+=('b');
	s += "efg";
	String s2;
	s2 += s;
	cout << s.c_str() << endl;
}

void testString4()
{
	String s;  // ""  
	s.resize(5, 'a');  //"aaaaa"  sz > _capacity
	s.resize(10, 'b');  // "aaaaabbbbb"  sz > _capacity
	s += 'c';   // "aaaaabbbbbc"  _capacity : 20
	s.resize(17, 'd');    //  "aaaaabbbbbcdddddd" _capacity > sz > _size
	s.resize(5, 'e');  // "aaaaa"  sz < _size
	s.resize(10);    // "aaaaa\0\0\0\0\0\0"
	cout << s.c_str() << "end" << endl;
	cout << s << endl;

}

void testString5()
{
	//String s("456");  // 456
	//s.insert(1, 'a');  // 4a56
	//s.insert(4, 'b');  // 4a56b
	//s.insert(0, '0');  // 04a56b

	String s("45690"); 
	s.insert(3, "78");  // 4567890
	s.insert(7, "1112"); // 45678901112
	s.insert(0, "123"); // 12345678901112
	s.erase(5, 2);   //  123458901112
	s.erase(0, 3);  //  458901112
	s.erase(8, 10); // 45890111
	s.erase(5, 3);  // 45890
	s.erase(s.begin()); // 5890
	s.erase(s.end() - 1); // 589
}


void testString6()
{
	char* str1 = "abcdabcdef123";
	char* str2 = "abcde";
	char* ret = StrStr(str1, str2);

	String s("0123456789");
	size_t pos = s.find("345");
}
//int main()
//{
//	//testString1();
//	//testString2();
//	//testString3();
//	//testString4();
//	//testString5();
//	testString6();
//	return 0;
//}