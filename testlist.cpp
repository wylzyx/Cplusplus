
#include <list>
#include <iostream>
using namespace std;

void testList1()
{
	list<int> l;
	list<int> l2(10, 2);
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	list<int> l3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	list<int> copy(l2);
	list<int> l4(l3.begin(), l3.end());

	list<int>::iterator lit = l3.begin();
	while (lit != l3.end())
	{
		cout << *lit << " ";
		*lit = 1;
		++lit;
	}
	cout << endl;

	for (const auto& e : l3)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << " reverse iterator: " << endl;
	list<int>::reverse_iterator rit = l3.rbegin();
	while (rit != l3.rend())
	{
		cout << *rit << " ";
		*rit = 3;
		++rit;
	}
	cout << endl;

	int& ret = l3.front();
	ret = 0;
	int& ret2 = l3.back();
	ret2 = 100;

	l3.assign(5, 5);
	cout << " const reverse iterator: " << endl;
	list<int>::const_reverse_iterator crit = l3.crbegin();
	while (crit != l3.crend())
	{
		cout << *crit << " ";
		//*crit = 10;
		++crit;
	}
	cout << endl;

	list<char> cl;
	cout << cl.max_size() << endl;
}

class A
{
public:
	explicit  A(int a = 0)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}

	A(int a, int b)
		:_a(a)
	{
		cout << "A(int, int)" << endl;
	}

	A(const A& a)
		:_a(a._a)
	{
		cout << "A(const A&)" << endl;
	}

//private:
public:
	int _a;
};

void testList2()
{
	list<int> lst;
	lst.push_front(1);
	lst.push_front(0);
	lst.push_front(-1);
	lst.push_back(2);
	lst.push_back(3);
	for (const auto& e : lst)
	{
		cout << e << " ";  // -1, 0, 1,2,3
	}
	cout << endl;

	lst.pop_front();
	for (const auto& e : lst)
	{
		cout << e << " ";  // 0, 1,2,3
	}
	cout << endl;

	lst.pop_back();
	for (const auto& e : lst)
	{
		cout << e << " ";  // 0, 1,2
	}
	cout << endl;

	
}

void testList3()
{
	list<A> lst;
	A a(10);
	lst.push_back(a);
	cout << "emplace_back: " << endl;
	lst.emplace_back(20);
	cout << "front: " << endl;
	lst.push_front(A(30));
	cout << "emplace_front: " << endl;
	lst.emplace_front(40);
	lst.emplace_back(1, 2);
	lst.emplace_front(3, 4);


}

void testList4()
{
	list<A> lst;
	//插入不会导致迭代器失效
	lst.insert(lst.begin(), A(1));
	list<A>::iterator lit = lst.begin();
	cout << lit->_a << endl;
	cout << (*lit)._a << endl;
	cout << "emplace: " << endl;
	lst.emplace(lst.begin(), 0);
	lst.insert(lst.end(), A(2, 3));
	cout << "emplace: " << endl;
	lst.emplace(lst.end(), 3, 4);
	cout << lit->_a << endl;
	cout << (*lit)._a << endl;

	for (const auto& oa : lst)
	{
		cout << oa._a << " ";  // 0, 1,2 3
	}
	cout << endl;
	lit = lst.begin();
	cout << "erase before: " << endl;
	cout << (*lit)._a << endl;
	//删除回导致迭代器失效，空间已经被释放，指向的空间无效
	//删除之后，需要获取erase的返回值： 被删除元素的下一个位置
	lit = lst.erase(lst.begin());
	cout << "erase after: " << endl;
	cout << (*lit)._a << endl;
	lst.erase(--lst.end());
	lst.erase(lst.begin(), --lst.end());
	for (const auto& oa : lst)
	{
		cout << oa._a << " ";  // 0, 1,2 3
	}
	cout << endl;
	cout << "resize(10): " << endl;
	lst.resize(10, A(3));
	for (const auto& oa : lst)
	{
		cout << oa._a << " ";  // 0, 1,2 3
	}
	cout << endl;
}

void testList5()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_back(1);
	lst.push_back(5);

	//lst.sort();

	list<int> lst2;
	lst2.push_back(19);
	lst2.push_back(9);
	lst2.push_back(1);
	//lst2.sort();
	//merge: list必须有序, 被合并的list变为空
	/*lst.merge(lst2);
	for (const auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << lst2.size() << endl;*/

	/*
	void splice( const_iterator pos, list& other );
	(1)
	void splice( const_iterator pos, list&& other );
	(1)	(C++11 起)
	void splice( const_iterator pos, list& other, const_iterator it );
	(2)
	void splice( const_iterator pos, list&& other, const_iterator it );
	(2)	(C++11 起)
	void splice( const_iterator pos, list& other,
	const_iterator first, const_iterator last);
	(3)
	void splice( const_iterator pos, list&& other,
	const_iterator first, const_iterator last );
	*/
	cout << "lst" << endl;
	for (const auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "lst2" << endl;
	for (const auto& e : lst2)
	{
		cout << e << " ";
	}
	cout << endl;
	lst.splice(lst.begin(), lst2);  //拼接lst2的所有内容
	//lst.splice(lst.begin(), lst2, ++lst2.begin());  拼接lst2指定迭代器位置的内容
	//lst.splice(lst.begin(), lst2, ++lst2.begin(), lst2.end()); //拼接lst2的区间[++begin, end)
	for (const auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << lst2.size() << endl;
	//cout << "remove(1): " << endl;
	/*lst.remove(1);
	for (const auto& e : lst)
	{
	cout << e << " ";
	}
	cout << endl;
	cout << "remove(1000): " << endl;
	lst.remove(1000);
	for (const auto& e : lst)
	{
	cout << e << " ";
	}
	cout << endl;*/
	lst.sort();
	lst.unique();
	cout << "unique: " << endl;
	for (const auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
}
//int main()
//{
//	//testList1();
//	//testList2();
//	//testList3();
//	//testList4();
//	testList5();
//	return 0;
//}