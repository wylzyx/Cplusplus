#define  _CRT_SECURE_NO_WARNINGS
//#pragma pack(1)
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
//namespace N1
//{
//	int a;
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//}
//
////�����ռ��Ƕ��
//namespace N2
//{
//	int b;
//	int sub(int a, int b)
//	{
//		return a - b;
//	}
//	namespace N3
//	{
//		int b;
//		int sub(int a, int b)
//		{
//			return a - b;
//		}
//	}
//}
//
////�����ռ�ķֶζ���
//namespace N1
//{
//	int b;
//	int sub(int a, int b)
//	{
//		return a - b;
//	}
//}
//
////�����ռ��Ա���ʷ�ʽ�� 
////                 1 �������ռ����� +  ���� + ������
////                 2 ��using + �����ռ����� +  ���� + ������ --> ʹ��ʱ����Ҫ���������޶���
////                 3 : using namespace + �����ռ����� --> ���еĳ�Աȫ����¶��ȫ������-->���Ƽ�-->����������ռ���Ⱦ
//using N1::a;
//using N1::add;
////using namespace N1;
////using namespace N2;
//void test1()
//{
//	//�����ռ��Ա���ʷ�ʽ�� �����ռ����� +  ���� + ������
//	//N1::a = 10;
//	a = 20;
//	//N1::sub(10, 5);
//	N1::sub(10, 5);
//	//Ƕ��
//	//N2::N3::b = 20;
//	N1::b = 30;
//	add(100, 200);
//}
////C++ ��������� <iostream>,  std
//using namespace std;
//void testIO()
//{
//	printf("hello world\n");
//	int a = 10;
//	printf("%d\n", a);
//	double d = 4.2;
//	/*std::cout << a;
//	std::cout << "\n";
//	std::cout << d;
//	std::cout << "\n";*/
//	/*std::cin >> a;
//	std::cout << "\n";
//	std::cout << a;
//	scanf_s("%d", &a);
//	std::cout << a;*/
//	//�����������˳�򣺴�����
//	cin >> a >> d;
//	cout << a << " " << d << endl;
//	
//}
//
//int main()
//{
//	testIO();
//	return 0;
//}


//void fun1(int a, int b)
//{
//	cout << a << b << endl;
//}
//ȱʡ����: 
//����ʹ��ʱ��
//       �����Σ� ʹ��ȱʡֵ
//        ���Σ� ʹ��ʵ��ֵ

//ȫȱʡ
//void fun1(int a = 100, int b = 0)
//{
//	cout << a << b << endl;
//}
//��ȱʡ
//void fun1(int a, int b = 0)
//{
//	cout << a << b << endl;
//}
////��ȱʡ�� ȱʡֵ������ҵ���������ֵ
//void fun2(int a, int b = 0, int c = 1)
//{
//	cout << a << b << c << endl;
//}
////ȱʡֵ��ֻ����һ���ط����壬 �������߶���
//void fun3(int a);
//
//void fun3(int a = 100)
//{
//	cout << a << endl;
//}
//
//
//int main()
//{
//	//fun1(10, 20);
//	/*fun1(1);
//	fun1(1, 2);
//	fun2(-1);
//	fun2(-1, 100);
//	fun2(-1, 100, 1000);*/
//	fun3();
//	return 0;
//}
//��ǰ�᣺ ��������ͬһ��������
//�������أ� ��������ͬ��������Ϣ��ͬ�����ͣ� ������˳��
// ������Ϣ�� �������Ͳ�ͬ
// �ͺ����ķ���ֵ�޹أ� ����ֵ�����Ͳ������ֺ���

//int add(int a, int b)
//{
//	return a + b;
//}
//
//float add(float a, float b)
//{
//	return a + b;
//}
////��ͬ�������򲻹�������
//namespace N1
//{
//	float add(int a, float b)
//	{
//		return a + b;
//	}
//}
//
//// ������Ϣ�� ����������ͬ
//
//int add(int a, int b, int c)
//{
//	return a + b + c;
//}
////������Ϣ�� ��������˳��ͬ
//void Print(int a, char c)
//{
//	cout << a << " " << c << endl;
//}
//
//void Print(char c, int a)
//{
//	cout << c << " " << a << endl;
//}
////����ֵ���Ͳ�ͬ����������
////int Print(char c, int a)
////{
////	cout << c << " " << a << endl;
////	return a;
////}
//extern "C"  //����C���ԵĹ������  sub������---> �ײ�: _ +  ������
//{
//	int sub(float a, int b);
//}
//
////int sub(float a, int b);
//
//
//int main()
//{
//	/*add(1, 2);
//	float a = 1.0, b = 2.0;
//	add(a, b);
//	add(1, 2, 3);*/
//	/*Print(10, 'a');
//	Print('a', 10);*/
//	sub(10, 5);
//	return 0;
//}

void testRef()
{
	int a = 10;
	int b = 20;
	//int�������� ra --> a ������ ra --> a ������
	// ���� --> �����ı���
	int& ra = a; 
	int& ra1 = a;
	int& ra2 = a;
	//�������ͱ����ʼ��
	//int& ra3;
	int copya = a;

	ra = 100;  //  a --> 100
	ra = b; // ra, a, ra1, ra2 --> 20
	copya = 1000;  // a --> 100  ra ---> 100

	//������
	int c = 10;
	const int& rc = 10;
	const int d = 10;
	const int& rd = d;
	float f = 2.0;
	c = f;
	const int& rf = f;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//����������ֵ������ʵ����������� > ��������������
int& SelfAdd(int& a)
{
	a++;
	return a;
}

//int main()
//{
//	//testRef();
//	int a = 1, b = 2;
//	//Swap(&a, &b);  // a = 2, b =1
//	//Swap(a, b);  // a = 1, b = 2
//	int& ra = SelfAdd(a);
//	cout << "ra: " << ra << endl;
//	cout << "hello world" << endl;
//	int c = a + b;
//	cout <<"ra: "<< ra << endl;
//	return 0;
//}

//struct SA
//{
//	int arr[10000];
//};
//
//SA sa;
//
//void funSAValue(SA sa)
//{}
//
//void funSARef(SA& sa)
//{}
//
//
//SA funSAValueReturn()
//{
//	return sa;
//}
//
//SA& funSARefReturn()
//{
//	return sa;
//}
//
//
//
//void testRefValue(int n)
//{
//	size_t begin = clock();
//	for (int i = 0; i < n; ++i)
//		//funSAValue(sa);
//		funSAValueReturn();
//	size_t end = clock();
//	cout <<"Value:"<<  end - begin << endl;
//
//}
//
//void testRefRef(int n)
//{
//	size_t begin = clock();
//	for (int i = 0; i < n; ++i)
//		//funSARef(sa);
//		funSARefReturn();
//	size_t end = clock();
//	cout <<"Ref: "<< end - begin << endl;
//}
//
//void testRef2()
//{
//	int a = 10;
//	//�ײ�ʵ���ϣ� ����ͨ��ָ��ʵ��
//	//���ã� ����* const
//	int& ra = a;
//	ra = 100;
//	++ra;
//	sizeof(ra);
//	//int& rra;
//	//int& ---> int* const
//
//
//	int* pa = &a;
//	int* const cpa = &a;
//	int b = 20;
//	//cpa = &b;
//	++(*cpa) = 200;
//	sizeof(cpa);
//	int* pa1;
//}
//
////int main()
////{
////	int n;
////	cin >> n;
////	testRefValue(n);
////	testRefRef(n);
////	return 0;
////}
//
//int main()
//{
//	testRef2();
//	return 0;
//}

#define Fun(a, b) (a) * (b)
//inline������һ����չ��������������ݴ���ĸ��ӳ̶�����չ��
//inline int Mul(int a, int b)
//{
//	return a * b;
//}
#include "test2.h"

//inline int Mul(int a, int b);
//
//inline int Mul(int a, int b)
//{
//	return a * b;
//}

//int main()
//{
//	//int c = Fun(2, 3);  // 2 * 3
//	//cout << Fun(2 + 1, 3) << endl;
//	int d = Mul(2, 3);  // 2 * 3  call  Mul
//	d = Mul(2 + 1, 3);
//	return 0;
//}
//auto�������ڶ������
//void fun(auto a)
//{}
//
//int main()
//{
//	//auto: ����ռλ��
//	//auto��������������ʼ��
//	//      ��������ʵ������ͨ����ʼ�����ʽȷ��
//	auto a = 10;
//	auto b = 2.0;
//
//	//auto c;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//
//	//ָ������
//	auto pa = &a;
//	auto* ppa = &a;
//	cout << typeid(pa).name() << endl;
//	cout << typeid(ppa).name() << endl;
//
//	//����
//	auto& ra = a;
//	cout << typeid(ra).name() << endl;
//	
//
//	auto rra = a;
//	cout << typeid(rra).name() << endl;
//
//	ra = 1000;
//	int& rrra = a;
//	int copya = a;
//
//	auto e = 1, f = 2;
//
//	//auto�������ڶ�������
//	int ar[] = { 1, 2, 3 };
//	//auto arr[] = { 1, 3, 3 };
//	
// 
//	return 0;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6 };
//	int* arr = (int*)malloc(sizeof(int)* 10);
//	int num = sizeof(arr) / sizeof(arr[0]); // num 1
//	/*for (int i = 0; i <= sizeof(a) / sizeof(a[0]); ++i)
//	{
//	cout << a[i] << endl;
//	}*/
//	//  ��ǰ��������Ԫ��ֵ  :  �����ķ�Χ
//	for (int e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (const auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto& e : a)
//	{
//		e *= 2;
//	}
//	cout << endl;
//
//	for (const auto& e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//
//
//	return 0;
//
//}

//void fun(int a)
//{
//	cout << "fun(int a)" << endl;
//}
//
//void fun(int* a)
//{
//	cout << "fun(int* a)" << endl;
//}

//int main()
//{
//	int* p = NULL;
//	int* p2 = 0;
//	//nullptr ���ͣ� nullptr_t
//	//nullptr���Խ�����ʽ����ת���� ת���������͵�ָ���ֵ
//	int* p3 = nullptr;
//	
//	fun(NULL);
//	fun((int*)NULL);
//	fun(nullptr);
//	cout << typeid(nullptr).name() << endl;
//	return 0;
//}
/*
struct ����
{};
*/
// struct�����ࣺĬ�Ϸ���Ȩ�ޣ�����
struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};

/*
class ����
{};
*/
// class�����ࣺĬ�Ϸ���Ȩ�ޣ�˽��
class Student2
{
//public, private, protected�� ֻ��������ķ���Ȩ��
public:  // ��Ա������ɼ�
	//��Ա����
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
private:  //��Ա�����ⲻ�ɼ�
	//��Ա����: �����ڲ�����ȫ�����ԣ��κεط������Է��ʵ�
	//         �ͷ����޶����޹أ��Ͷ����λ��Ҳû�й�ϵ
	char _name[20];
	char _gender[3];
protected: // ��Ա�����ⲻ�ɼ�
	int _age;

};

//�������
class Student3
{
	
public:
	//��Ա����
	void SetStudentInfo(const char* name, const char* gender, int age);
	void PrintStudentInfo();
private:  
	char _name[20];
	char _gender[3];
	int _age;

};

//��ĳ�Ա�����Ķ��壺 ��Ҫ�����������
void Student3::SetStudentInfo(const char* name, const char* gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
//��ͨ������ ���ܷ������˽�г�Ա
//void SetStudentInfo(const char* name, const char* gender, int age)
//{
//	strcpy(_name, name);
//	strcpy(_gender, gender);
//	_age = age;
//}

void Student3::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}

//public, private, protected

//int main()
//{
//	//struct, class �������Ψһ��������ǳ�Ա��Ĭ�Ϸ���Ȩ�޲�ͬ
//	//���ʵ������ ����һ�������͵ı���
//	//�����͵ı��� : ��Ķ���
//	Student st;
//	st._age = 18;
//	st.SetStudentInfo("helo", "man", 18);
//	st.PrintStudentInfo();
//
//	Student2 st2;
//	st2.SetStudentInfo("helo", "man", 10);
//	st2.PrintStudentInfo();
//	return 0;
//}

class A
{
	int a;
};

class B
{
	int b;
	void fun(int a, int b)
	{
		int c = a + b;
	}
};
class C
{

};

class D
{
public:
	char c;
	double d;
	int a;
};

//int main()
//{
//	//�����Ĵ�С�ͽṹ���С���������ͬ
//	//A a;
//	//B b;
//	//C c;
//	////������ֻ��ų�Ա����
//	//int sz = sizeof(a);
//	////��Ա����������ڶ�����
//	//sz = sizeof(b);
//	////����Ĵ�СΪ1
//	//sz = sizeof(c);
//	D d;
//	int sz = sizeof(d);
//	cout << ((char*)&d.a - (char*)&d) << endl;
//	return 0;
//}

union F
{
	int a;
	char c;
};
int main()
{
	F f;
	f.a = 1;
	int b = 1;
	char c = b;
	int* pb = &b;
	char* pbb = (char*)pb;
	if (f.c == 0)
	{
		cout << "big end" << endl;
	}
	else
	{
		cout << "little end" << endl;
	}

	if (*pbb == 0)
	{
		cout << "big end" << endl;
	}
	else
	{
		cout << "little end" << endl;
	}

	return 0;
}


