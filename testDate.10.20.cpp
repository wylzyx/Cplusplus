#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

//void testDate()
//{
//	Date d; //ʵ����
//	// thisָ�� --> d
//	d.SetDate(2019, 10, 22);
//	d.Display();  
//
//	Date d2;
//	// thisָ�� --> d2
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
//	//this�Ƿ����Ϊ�գ�
//	//    ����Ϊ�գ������н�����
//	//    ������Ϊ�գ����н�����
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
	//���캯����ʵ����ʱ�������Զ����ã�������������ֻ����һ��
	//�޲ι��캯���������������
	//Date d;
	//������һ����������
	//Date d3(); 
	//d.SetDate(2019, 10, 25);

	Date d2(2019, 10);
	//��������
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

