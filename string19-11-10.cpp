#include<iostream>
#include<string.h>
#include<assert.h>

class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	//����
	String(char* str = "")
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	String(const String& str)
		:_str(nullptr)
		,_size(0)
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

	//����
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	//const ���ã�ֻ���ӿ� 
	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}
	//�������һ��Ԫ�ص���һ��λ��
	iterator end()
	{

	}
	const iterator cbegin();
	const iterator cend();
	//����
	size_t Size() const
	{
		return _size;
	}
	size_t Capacity();
	void resize(size_t sz, );


	//�޸�
	void push_back(char c);

	void Append(const char*str);

	String& operator+=(char c);
	String& operator+=(const char* str);
	String& operator+=(const String& str);

	void insert(size_t pos, char c);
	void insert(size_t pos, const char* str);

	void erase();

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

void testString1()
{

}

void testString2()
{

}