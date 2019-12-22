//#include<iostream>
//using namespace std;
//
//template<class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//	~UniquePtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
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
//private:
//	UniquePtr(UniquePtr<T>const &) = delete;
//	UniquePtr& operator=(UniquePtr<T>const &) = delete;
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
//	UniquePtr<Date> sp(new Date);
//	sp->_year = 2019;
//	cout << sp->_year << endl;
//	//��������Ҳ���ǲ��ÿ����͸�ֵ
//	//UniquePtr<Date> copy(sp);
//}
//
//int main()
//{
//	func();
//	system("pause");
//	return 0;
//}