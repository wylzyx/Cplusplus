#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

//void testDate()
//{
//	Date d; //实例化
//	// this指针 --> d
//	d.SetDate(2019, 10, 22);
//	d.Display();  
//
//	Date d2;
//	// this指针 --> d2
//	d2.SetDate(2019, 10, 23);
//	d2.Display();  
//}
//
//int main()
//{
//	testDate();
//	return 0;
//}

//class A
//{
//public:
//	//this是否可以为空：
//	//    可以为空：不进行解引用
//	//    不可以为空：进行解引用
//	void PrintA()
//	{
//		cout << this->_a << endl;
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = NULL;
//	//p->PrintA();
//	p->Show();
//}


void testConstruct()
{
	//构造函数在实例化时编译器自动调用，整个生命周期只调用一次
	//无参构造函数后面无需加括号
	//Date d;
	//下面是一个函数声明
	//Date d3(); 
	//d.SetDate(2019, 10, 25);

	Date d2(2019, 10);
	//拷贝构造
	Date d3(d2);
	Date d4 = d3;
	/*Date d5 = Date(2018, 10, 23);*/
	cout << d3.Equal(d4) << endl;
	//operator==(d3, d2);
	d3.operator==(d2);

	d3 == d4;
	int a = 10, b = 20;
	cout << (a == b) << endl;
	
	
}



void testString()
{
	String s("hello");
	String copy(s);
}

int main()
{
	testConstruct();
	//testString();
	return 0;
}

