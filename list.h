
template <class T>
struct ListNode
{
	T _data;
	ListNode<T>* _prev;
	ListNode<T>* _next;

	ListNode(const T& value = T())
		:_data(value)
		, _prev(nullptr)
		, _next(nullptr)
	{
	}
};

//List����������List�Ľڵ����������ָ��Ĺ���
//template <class T>
//struct ListIterator
//{
//	typedef ListNode<T> Node;
//	typedef ListNode<T>* pNode;
//	typedef ListIterator<T> Self;
//
//	pNode _node;
//
//	ListIterator(pNode node)
//		:_node(node)
//	{}
//
//	//�����ã� �ɶ���д
//	T& operator*()
//	{
//		return _node->_data;
//	}
//	// ptr->_year; ���Կ�д
//	T* operator->()
//	{
//		return &operator*();
//		//return &_node->_data;
//	}
//
//	//������ǰ��++
//	Self& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	Self operator++(int)
//	{
//		Self tmp(*this);
//		_node = _node->_next;
//		return tmp;
//	}
//
//	Self& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//
//	Self operator--(int)
//	{
//		Self tmp(*this);
//		_node = _node->_prev;
//		return tmp;
//	}
//
//	//!= 
//	bool operator!=(const Self& it)
//	{
//		return _node != it._node;
//	}
//
//	bool operator==(const Self& it)
//	{
//		return _node == it._node;
//		//return !*this != it;
//	}
//};
//
//template <class T>
//struct ListConstIterator
//{
//	typedef ListNode<T> Node;
//	typedef ListNode<T>* pNode;
//	typedef ListConstIterator<T> Self;
//
//	pNode _node;
//
//	ListConstIterator(pNode node)
//		:_node(node)
//	{}
//
//	//�����ã� ֻ��
//	const T& operator*()
//	{
//		return _node->_data;
//	}
//	// ptr->_year; ֻ��
//	const T* operator->()
//	{
//		return &operator*();
//		//return &_node->_data;
//	}
//
//	//������ǰ��++
//	Self& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	Self operator++(int)
//	{
//		Self tmp(*this);
//		_node = _node->_next;
//		return tmp;
//	}
//
//	Self& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//
//	Self operator--(int)
//	{
//		Self tmp(*this);
//		_node = _node->_prev;
//		return tmp;
//	}
//
//	//!= 
//	bool operator!=(const Self& it)
//	{
//		return _node != it._node;
//	}
//
//	bool operator==(const Self& it)
//	{
//		return _node == it._node;
//		//return !*this != it;
//	}
//};

template <class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr> Self;

	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}

	//�����ã� �ɶ���д
	Ref operator*()
	{
		return _node->_data;
	}
	// ptr->_year; ���Կ�д
	Ptr operator->()
	{
		return &operator*();
		//return &_node->_data;
	}

	//������ǰ��++
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	//!= 
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
		//return !*this != it;
	}
};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;

	List()
	{
		CreatHead();
	}

	void CreatHead()
	{
		_head = new Node;
		_head->_prev = _head;
		_head->_next = _head;
	}

	void PushBack(const T& value)
	{
		/*pNode newNode = new Node(value);
		pNode tail = _head->_prev;

		tail->_next = newNode;
		newNode->_prev = tail;
		newNode->_next = _head;
		_head->_prev = newNode;*/
		Insert(end(), value);
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		/*iterator it(head);
		return it;*/
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}

	void PushFront(const T& value)
	{
		Insert(begin(), value);
	}

	void PopBack()
	{
		Erase(--end());
	}
	void PopFront()
	{
		Erase(begin());
	}

	void Insert(iterator pos, const T& value)
	{
		//pos-> node
		//prev -->  node -> next
		pNode cur = pos._node;
		pNode newNode = new Node(value);
		pNode prev = cur->_prev;
		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = cur;
		cur->_prev = newNode;
	}

	iterator Erase(iterator pos)
	{
		//ͷ�ڵ㲻��ɾ
		if (pos != end())
		{
			//prev  --> curNode --> next
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			delete cur;
			cur = nullptr;
			prev->_next = next;
			next->_prev = prev;
			//���µ�������ָ����һ��Ԫ�ص�λ�ã���ֹ������ʧЧ
			pos = iterator(next);
		}
		return pos;
	}

	void Clear()
	{
		if (!Empty())
		{
			/*pNode cur = _head->_next;
			while (cur != _head)
			{
				pNode next = cur->_next;
				delete cur;
				cur = next;
			}

			_head->_next = _head;
			_head->_prev = _head;*/

			iterator it = begin();
			while (it != end())
			{
				it = Erase(it);
			}
		}
	}

	template <class InputIterator>
	List(InputIterator first, InputIterator last)
	{
		CreatHead();
		while (first != last)
		{
			PushBack(*first);
			++first;
		}
	}
	
	//���
	List(const List<T>& lst)
	{
		CreatHead();
		for (const auto& e : lst)
		{
			PushBack(e);
		}
	}

	List<T>& operator=(List<T> lst)
	{
		swap(_head, lst._head);
		return *this;
	}

	bool Empty()
	{
		return _head == _head->_next;
	}

	size_t Size()
	{
		size_t sz = 0;
		for (const auto& e : *this)
			++sz;
		return sz;
	}

	~List()
	{
		Clear();
		if (_head)
		{
			delete _head;
			_head = nullptr;
		}
	}
private:
	pNode _head;
};