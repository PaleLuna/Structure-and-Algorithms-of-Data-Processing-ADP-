#pragma once

template<typename T>
class ListStack
{
	template<typename>
	struct Node
	{
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	public:
		ListStack();
		~ListStack();

		void Push(const T& data);
		bool Pop(T& var);
		bool GetHead(T& var);

		bool IsEmpty();

		void Clear();

	private:
		Node<T>* head;
		bool DeleteHead();
};

template<typename T>
inline ListStack<T>::ListStack()
{
	this->head = nullptr;
}
template<typename T>
inline ListStack<T>::~ListStack()
{
	Clear();
}

template<typename T>
void ListStack<T>::Push(const T& data)
{
	this->head = new Node<T>(data, head);
}
template<typename T>
inline bool ListStack<T>::Pop(T& var)
{
	bool flag = !IsEmpty();
	if (flag)
	{
		var = head->data;
		DeleteHead();
	}

	return flag;
}
template<typename T>
inline bool ListStack<T>::DeleteHead()
{
	bool flag = !IsEmpty();
	if (flag)
	{
		Node<T>* temp = head;
		head = head->pNext;
		delete[] temp;
	}

	return flag;
}

template<typename T>
inline bool ListStack<T>::GetHead(T& var)
{
	bool flag = !IsEmpty();
	if (flag)
	{
		var = head->data;
	}

	return flag;
}

template<typename T>
inline bool ListStack<T>::IsEmpty()
{
	return head == nullptr;
}

template<typename T>
inline void ListStack<T>::Clear()
{
	while (DeleteHead());
}

