#include "Product.h"
#pragma once

template<typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();

	unsigned GetSize() { return size; }
	void Push_back(T data);
	void Insert(T data, unsigned index);
	void DeleteAt(unsigned index);
	void Clear();

	T& operator[](unsigned index);
	void operator=(const List<T>& other);

private:
	template<typename>
	struct Node
	{
		Node* pNext;
		Node* pPrev;

		T data;


		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->pNext = pNext;
			this->pPrev = pPrev;

			this->data = data;
		}
	};

	void CreateHead(T data);
	void CreateTail(T data);
	void CreateNewNode(T data, unsigned index);

	void DeleteHead();
	void DeleteTail();
	void DeleteNode(unsigned index);

	void SearchNode(List<T>::Node<T>*& node, unsigned index);

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
void List<T>::Insert(T data, unsigned index)
{
	if (index == 0)
		CreateHead(data);
	else if (index >= size)
		CreateTail(data);
	else
		CreateNewNode(data, index);

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
		CreateTail(data);
	}
}
template<typename T>
void List<T>::CreateHead(T data)
{
	head = new Node<T>(data);
	tail = head;
	size++;
}
template<typename T>
void List<T>::CreateTail(T data)
{
	tail->pNext = new Node<T>(data, nullptr, tail);
	tail = tail->pNext;
	size++;
}
template<typename T>
void List<T>::CreateNewNode(T data, unsigned index)
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
void List<T>::SearchNode(List<T>::Node<T>*& node, unsigned index)
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
T& List<T>::operator[](unsigned index)
{
	Node<T>* searchNode;
	T none = T();
	SearchNode(searchNode, index);

	return searchNode->data;
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

