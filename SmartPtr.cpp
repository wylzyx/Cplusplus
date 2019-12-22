//#include<iostream>
//using namespace std;
//
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr() 
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date()" << endl;
//	}
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//
//void func()
//{
//	SmartPtr<Date> sp(new Date);
//	sp->_year = 2019;
//	sp->_month = 12;
//	sp->_day = 21;
//	cout << sp->_year << "-" << sp->_month << "-" << sp->_day << endl;
//}
//
//int main()
//{
//	SmartPtr<int> sp1(new int);
//	*sp1 = 10;
//	cout << *sp1 << endl;
//
//	func();
//
//	system("pause");
//	return 0;
//}