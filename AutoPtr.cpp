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
//	// һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ��    
//	// �����ͽ����һ��ռ䱻�������ʹ�ö���ɳ���������
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = nullptr;
//	}
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		// ����Ƿ�Ϊ�Լ����Լ���ֵ
//		if (this != &ap)
//		{
//			// �ͷŵ�ǰ��������Դ 
//			if (_ptr)
//			{
//				delete _ptr;
//			}
//			// ת��ap����Դ����ǰ������ 
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
//		//�����󿽱����߸�ֵ��ǰ��Ķ��������
//		//ap->_year = 2019;
//		//cout << ap->_year << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
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