//#include<iostream>
//using namespace std;
//
//template<class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//	~AutoPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//		}
//	}
//	// 一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系，    
//	// 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = nullptr;
//	}
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		// 检测是否为自己给自己赋值
//		if (this != &ap)
//		{
//			// 释放当前对象中资源 
//			if (_ptr)
//			{
//				delete _ptr;
//			}
//			// 转移ap中资源到当前对象中 
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//		return *this;
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
//	try
//	{
//		AutoPtr<Date> ap(new Date);
//		AutoPtr<Date> copy(ap);
//
//		copy->_year = 2019;
//		cout << copy->_year << endl;
//
//		//当对象拷贝或者赋值后，前面的对象就悬空
//		//ap->_year = 2019;
//		//cout << ap->_year << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//	//cout << copy>_year << endl;
//}
//
//int main()
//{
//	func();
//	system("pause");
//	return 0;
//}