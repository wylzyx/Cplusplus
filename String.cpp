#include <string>
#include <list>
#include <iostream>
using namespace std;
//typedef basic_string<char> string;
//����
/*
default (1)
string();
copy (2)
string (const string& str);
substring (3)
string (const string& str, size_t pos, size_t len = npos);
from c-string (4)
string (const char* s);
from sequence (5)
string (const char* s, size_t n);
fill (6)
string (size_t n, char c);
range (7)
template <class InputIterator>
string  (InputIterator first, InputIterator last);
*/
void testString1()
{
	string s;
	string s2("hello world");
	string copy(s2);
	string s3(s2, 0, 5);  // hello
	string s4("hello world", 2);  // he
	string s5(10, 'a'); // "aaaaaaaaaa"

	char str1[] = "china";
	char str2[] = "�й�";
	/*cout << sizeof(str1) << endl;
	cout << sizeof(str2) << endl;
	cout << str1 << endl;
	cout << str2 << endl;*/
	char str3[5];
	cout << str3 << endl;

	str3[0] = -42;
	str3[1] = -48;
	str3[2] = -71;
	str3[3] = -5;
	str3[4] = 0;
	cout << str3 << endl;
}

void testIterator()
{
	
	string s2("hello world");
	/*
	 ��������һ���������ݵķ��ʻ���, �ɶ���д�Ľӿ�
	 ʹ�÷�ʽ��������ָ���ʹ�÷�ʽ
	 begin�������� ָ�������ĵ�һ��Ԫ�ص�λ��
	 end�������� ָ�����������һ��Ԫ�ص���һ��λ��
	 ����ҿ��� [begin, end)
	*/
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		//*it = 'a';
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	//forѭ��
	for (int i = 0; i < s2.size(); ++i)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	//��Χfor
	for (const auto& ch : s2)
	{
		cout << ch << " ";
	}
	cout << endl;

	//const ������
	const string s3("hello");
	string::const_iterator s3it = s3.begin();
	while (s3it != s3.end())
	{
		//*s3it = 'a';
		cout << *s3it << " ";
		++s3it;
	}
	cout << endl;

	string::const_reverse_iterator s3rit = s3.rbegin();
	while (s3rit != s3.rend())
	{
		//*s3it = 'a';
		cout << *s3rit << " ";
		++s3rit;
	}
	cout << endl;



	/*list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	list<int>::iterator lit = l.begin();
	while (lit != l.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;*/
}
int main()
{
	//testString1();
	testIterator();
	return 0;
}