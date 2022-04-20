#pragma once

template<typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();

	unsigned GetSize() { return size; }
	unsigned Find(T data);
	void Push_back(T data);
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
	void CreateNewNode(T data);

	void DeleteHead();
	void DeleteTail();
	void DeleteNode(unsigned index);

	void SearchFromTail(List<T>::Node<T>*& node, unsigned index);
	void SearchFromHead(List<T>::Node<T>*& node, unsigned index);

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
unsigned List<T>::Find(T data)
{
	unsigned index = 0;
	Node<T>* currentNode = head;

	while (currentNode != nullptr)
	{
		if (currentNode->data == data)
			break;
		currentNode = currentNode->pNext;
		index++;
	}
	return index;
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
	tail = head;
	size++;
}
template<typename T>
void List<T>::CreateNewNode(T data)
{
	tail->pNext = new Node<T>(data, nullptr, tail);
	tail = tail->pNext;
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
	if (index < size / 2)
	{
		SearchFromHead(toDelete, index);
	}
	else
	{
		SearchFromTail(toDelete, index);
	}

	toDelete->pPrev->pNext = toDelete->pNext;
	toDelete->pNext->pPrev = toDelete->pPrev;
	delete toDelete;

	size--;
}
template<typename T>
void List<T>::SearchFromHead(List<T>::Node<T>*& node, unsigned index)
{
	node = head;
	for (int i = 0; i < index && node != nullptr; i++)
		node = node->pNext;
}
template<typename T>
void List<T>::SearchFromTail(List<T>::Node<T>*& node, unsigned index)
{
	node = tail;
	for (int i = size - 1; i > index; i--)
		node = node->pPrev;
}

template<typename T>
T& List<T>::operator[](unsigned index)
{
	Node<T>* searchNode;
	T none = T();
	if (index < size / 2)
	{
		SearchFromHead(searchNode, index);
	}
	else
	{
		SearchFromTail(searchNode, index);
	}

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

