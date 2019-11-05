#include<iostream>
#include<string>
using namespace std;
class String {
public:
	////无参构造
	//String()
	//	:_str(new char[1])
	//{
	//	*_str = '\0';
	//}
	////带参构造
	//String(char* str)
	//	:_str(new char[strlen(str) + 1])
	//{
	//	strcpy(_str, str);
	//}
	//缺省参数
	String(char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	
	~String(){
		if (_str) {
			delete[] _str;
		}
	}
	
	String(const String& str) 
		:_str(new char[strlen(str._str) + 1])
	{
		strcpy(_str, str._str);
	}
	String(const String& str) {
		String tmp(str._str);
		swap(_str,tmp._str);
	}
	
	String& operator=(const String& str) {
		if (this != &str) {
			delete[] _str;
			_str = new char(strlen(str._str) + 1);
			strcpy(_str, str._str);
 		}
		return *this;
	}
	
	const char* c_str() const {
		return _str;
	}
private:
	char* _str;
};

void testString1() {
	String s;
	char* str = new char[10];
	strcpy(str, "hello");
	String s3(str);
	delete[] str;

}

void testString2() {
	String s1("hello");
	String s2 = s1;
}

int main() {
	testString1();
	return 0;
}