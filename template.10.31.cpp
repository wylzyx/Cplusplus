#include <iostream>
using namespace std;
template <typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T add(const T& a, const T& b)
{
	return a + b;
}

template <typename T, class T2>
T add(const T& a, const T2& b)
{
	return a + b;
}


int add(const int& a, const int& b)
{
	return a + b;
}

//template <class T>
//void swap(T* a, T* b)
//{
//
//}
class A
{
public:
	A(int a = 0)
		:_a(a)
	{}
private:
	int _a;
};

//int main()
//{
//	int a = 1, b = 2;
//	char c = 'a', d = 'b';
//	double e = 1.1, f = 2.2;
//	//��ʽʵ����
//	swap(a, b);  // swap(int, int)
//	swap(c, d);  // swap(char, char)
//	swap(e, f); // swap(double, double)
//	A ao = 10;
//	A bo = 20;
//	swap(ao, bo); // swap(A, A)
//	
//	//double& rd = a;
//	add((double)a, e);
//	add(a, (int)e);
//	//��ʽʵ����
//	add<int>(a, e);
//	add<double>(a, e);
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2;
//	//��ģ�庯����ģ�庯�����棬����ƥ���ģ�庯��
//	add(a, b);
//	double c = 1.2;
//	//��ģ�庯����ģ�庯�����棬����ƥ���ģ�庯��, 
//	//���������ȫƥ�䣬ʵ�����������ɸ���ƥ��ĺ���������ʵ����
//	add(a, c);
//	//���������ʽʵ������һ�������ʵ����
//	add<int>(a, b);
//	return 0;
//}

//typedef int DataType;
template <class DataType>
class SeqList
{
public:
	SeqList(int num = 10)
		:_data(new DataType[num])
		, _size(num)
		, _capacity(num)
	{
	}
	//ǳ����
	SeqList<DataType>& operator=(const SeqList<DataType>& sq)
	{
		if (this != &sq)
		{
			_data = sq._data;
			_size = sq._size;
			_capacity = sq._capacity;
		}
		return *this;
	}

	void Display()
	{
		for (int i = 0; i < _size; ++i)
		{
			cout << _data[i] << endl;
		}
	}
	// a[i]
	DataType& operator[](size_t pos);
	/*{
		return _data[pos];
	}*/

	~SeqList()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	size_t Size()
	{
		return _size;
	}

private:
	DataType* _data;
	size_t _size;
	size_t _capacity;
};

template <class DataType>
DataType& SeqList<DataType>::operator[](size_t pos)
{
	return _data[pos];
}

//int main()
//{
//	//��ģ�壺 
//	// ���� != ����
//	// ����    ����<����>
//	SeqList<int> sl;
//	SeqList<int> sl2;
//	SeqList<char> sc;
//	SeqList<float> sf;
//	for (int i = 0; i < sl.Size(); ++i)
//	{
//		//sl[i] <---> sl.operator[](i)
//		sl[i] = i;
//		sl.operator[](i) = i;
//		cout << sl[i] << endl;
//	}
//	sl2 = sl;
//	return 0;
//}
