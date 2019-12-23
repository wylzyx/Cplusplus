#include <thread> 
#include <mutex>

template <class T> 
class SharedPtr
{
public:    
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)  
	{}

	~SharedPtr() 
	{ 
		Release(); 
	}

	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)   
	{
		AddRefCount();
	}

	// sp1 = sp2   
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)    
	{      
		//if (this != &sp)  
		if (_ptr != sp._ptr)
		{
			// �ͷŹ���ľ���Դ   
			Release();

			// ��������¶������Դ�����������ü���       
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
		
			AddRefCount();
		}
		return *this;  
	}

	T& operator*() 
	{ 
		return *_ptr; 
	}   
	T* operator->() 
	{ 
		return _ptr; 
	}


	int UseCount() 
	{
		return *_pRefCount;
	}   
	T* Get()
	{ 
		return _ptr;
	}

void AddRefCount()  
{     
	// ��������ʹ�ü�1��ԭ�Ӳ���     
	_pMutex->lock();   
	++(*_pRefCount);   
	_pMutex->unlock();   
}
private:  
	void Release()  
	{
	
		bool deleteflag = false;
			// ���ü�����1���������0�����ͷ���Դ   
		_pMutex.lock();     
		if (--(*_pRefCount) == 0)  
		{          
			delete _ptr;    
			delete _pRefCount;       
			deleteflag = true;      
		}     
		_pMutex.unlock();          
		if(deleteflag == true)     
			delete _pMutex; 
	} 
private:    
	int* _pRefCount; // ���ü��� 
	T*   _ptr;       // ָ�������Դ��ָ��    
	mutex* _pMutex;      // ������ 
};

			
int main() {
	SharedPtr<int> sp1(new int(10));    
	SharedPtr<int> sp2(sp1);   
	*sp2 = 20;    
	cout << sp1.UseCount() << endl;   
	cout << sp2.UseCount() << endl;

	SharedPtr<int> sp3(new int(10));   
	sp2 = sp3;    
	cout << sp1.UseCount() << endl;  
	cout << sp2.UseCount() << endl;  
	cout << sp3.UseCount() << endl;

	sp1 = sp3;   
	cout << sp1.UseCount() << endl;   
	cout << sp2.UseCount() << endl;    
	cout << sp3.UseCount() << endl;

	return 0;
}