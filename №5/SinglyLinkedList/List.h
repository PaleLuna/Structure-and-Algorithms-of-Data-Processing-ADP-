#pragma once

using namespace std;

template<typename T>
class List
{
	public:
		List();
		~List();

		unsigned GetSize() { return size; }
		void Push_back(T data);

	private:
		template<typename T>
		struct Node
		{
				Node* pNext;
				T data;

				Node(T data = T(), Node* pNext = nullptr)
				{
					this->pNext = pNext;
					this->data = data;
				}
		};

		void CreateHead(T data);
		void CreateNewNode(T data);

		unsigned size;
		Node<T> *head;
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
};
template<typename T>
inline List<T>::~List()
{
}

template<typename T>
void List<T>::Push_back(T data)
{
	if (head == nullptr)
	{
		CreateHead(data);
	}
	else
	{
		CreateNewNode(data);
	}
}
template<typename T>
void List<T>::CreateHead(T data)
{
	head = new Node<T>(data);
	size++;
}
template<typename T>
void List<T>::CreateNewNode(T data)
{
	Node<T>* currentNode = head;
	while (currentNode->pNext != nullptr)
		currentNode = currentNode->pNext;

	currentNode->pNext = new Node<T>(data);
	size++;
}