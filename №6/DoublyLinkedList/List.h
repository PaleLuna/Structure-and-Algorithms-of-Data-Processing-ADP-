#include "Product.h"
#pragma once

template<typename T>
class List
{
	template<typename T>
	struct Node
	{
		Node* pNext;
		Node* pPrev;

		T data;


		Node(T& data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->pNext = pNext;
			this->pPrev = pPrev;

			this->data = data;
		}
	};

	public:
		List();
		List(const List<T>& other);
		~List();

		unsigned GetSize() { return size; }

		void Push_back(T& data);
		void Push_front(T& data);
		void Insert(T& data, unsigned index);
		void MoveToFront(Node<T>* node);

		void DeleteAt(unsigned index);
		void Clear();

		Node<T>* GetNode(unsigned index);
		T& operator[](unsigned index);
		void operator=(const List<T>& other);

	private:
		void CreateHead(T& data);
		void CreateTail(T& data);
		void CreateNewHead(T& data);
		void CreateNewNode(T& data, unsigned index);

		void DeleteHead();
		void DeleteTail();
		void DeleteNode(unsigned index);

		void SearchNode(Node<T>*& node, unsigned index);

		unsigned size;

		Node<T>* head;
		Node<T>* tail;
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template<typename T>
List<T>::List(const List<T>& other)
{
	size = other.size;
	this->head = new Node<T>(other.head->data);

	Node<T>* currentNode = this->head;
	Node<T>* otherCurrentNode = other.head->pNext;
	while (otherCurrentNode != nullptr)
	{
		currentNode->pNext = new Node<T>(otherCurrentNode->data, nullptr, currentNode);

		currentNode = currentNode->pNext;
		otherCurrentNode = otherCurrentNode->pNext;
	}
	tail = currentNode;
}
template<typename T>
List<T>::~List()
{
	Clear();
}


template<typename T>
void List<T>::Insert(T& data, unsigned index)
{
	if (index == 0)
		CreateNewHead(data);
	else if (index >= size)
		CreateTail(data);
	else
		CreateNewNode(data, index);

}
template<typename T>
void List<T>::MoveToFront(Node<T>* node)
{
	if (node->pNext == nullptr)
	{
		node->pPrev->pNext = nullptr;
		tail = node->pPrev;
	}
	else if (node->pPrev != nullptr)
	{
		node->pNext->pPrev = node->pPrev;
		node->pPrev->pNext = node->pNext;
	}

	node->pNext = head;
	head->pPrev = node;
	node->pPrev = nullptr;
	head = node;
}
template<typename T>
void List<T>::Push_back(T& data)
{
	if (head == nullptr)
		CreateHead(data);
	else
		CreateTail(data);
}
template<typename T>
void List<T>::Push_front(T& data)
{
	if (head == nullptr)
		CreateHead(data);
	else
		CreateNewHead(data);
}

template<typename T>
void List<T>::CreateHead(T& data)
{
	head = new Node<T>(data);
	tail = head;
	size++;
}
template<typename T>
void List<T>::CreateTail(T& data)
{
	tail->pNext = new Node<T>(data, nullptr, tail);
	tail = tail->pNext;
	size++;
}
template<typename T>
void List<T>::CreateNewHead(T& data)
{
	head->pPrev = new Node<T>(data, head);
	head = head->pPrev;

	size++;
}
template<typename T>
void List<T>::CreateNewNode(T& data, unsigned index)
{
	Node<T>* currentNode;
	SearchNode(currentNode, index);
	
	currentNode->pPrev->pNext = new Node<T>(data, currentNode, currentNode->pPrev);
	currentNode->pPrev = currentNode->pPrev->pNext;

	size++;
}


template<typename T>
void List<T>::Clear()
{
	while (size)
		DeleteHead();
}
template<typename T>
void List<T>::DeleteAt(unsigned index)
{
	unsigned currentIndex = 0;
	Node<T>* currentNode = head;
	if (index == 0)
	{
		DeleteHead();
	}
	else if (index == size - 1)
	{
		DeleteTail();
	}
	else
	{
		DeleteNode(index);
	}
}
template<typename T>
void List<T>::DeleteHead()
{
	Node<T>* temp = head;
	head = head->pNext;
	if(head != nullptr)
		head->pPrev = nullptr;
	delete temp;

	size--;
}
template<typename T>
void List<T>::DeleteTail()
{
	Node<T>* temp = tail;
	tail = tail->pPrev;
	delete temp;

	size--;
}
template<typename T>
void List<T>::DeleteNode(unsigned index)
{
	Node<T>* toDelete; 
	SearchNode(toDelete, index);

	toDelete->pPrev->pNext = toDelete->pNext;
	toDelete->pNext->pPrev = toDelete->pPrev;
	delete toDelete;

	size--;
}


template<typename T>
List<T>::Node<T>* List<T>::GetNode(unsigned index)
{
	Node<T>* searchNode;
	SearchNode(searchNode, index);
	return searchNode;
}
template<typename T>
T& List<T>::operator[](unsigned index)
{
	Node<T>* searchNode;
	SearchNode(searchNode, index);

	return searchNode->data;
}
template<typename T>
void List<T>::SearchNode(Node<T>*& node, unsigned index)
{
	if (index < size / 2)
	{
		node = head;
		for (int i = 0; i < index && node != nullptr; i++)
			node = node->pNext;
	}
	else
	{
		node = tail;
		for (int i = size - 1; i > index; i--)
			node = node->pPrev;
	}
}


template<typename T>
void List<T>::operator=(const List<T>& other)
{
	this->Clear();

	size = other.size;
	this->head = new Node<T>(other.head->data);

	Node<T>* currentNode = this->head;
	Node<T>* otherCurrentNode = other.head->pNext;
	while (otherCurrentNode != nullptr)
	{
		currentNode->pNext = new Node<T>(otherCurrentNode->data, nullptr, currentNode);

		currentNode = currentNode->pNext;
		otherCurrentNode = otherCurrentNode->pNext;
	}
	tail = currentNode;
}

