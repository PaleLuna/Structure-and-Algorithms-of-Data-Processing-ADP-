#pragma once
using namespace std;

template<typename T>
class List
{
	public:
		List();
		List(const List<T>& other);
		~List();

		unsigned GetSize() { return size; }
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
				T data;

				Node(T data = T(), Node* pNext = nullptr)
				{
					this->pNext = pNext;
					this->data = data;
				}
		};

		void CreateHead(T data);
		void CreateNewNode(T data);

		void DeleteHead();
		void DeleteNode(unsigned index);

		unsigned size;
		Node<T> *head;
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
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
		currentNode->pNext = new Node<T>(otherCurrentNode->data);
		currentNode = currentNode->pNext;
		otherCurrentNode = otherCurrentNode->pNext;
	}
}
template<typename T>
List<T>::~List()
{
	Clear();
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

template<typename T>
void List<T>::Clear()
{
	while (size)
		DeleteHead();
	size = 0;
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
	delete temp;

	size--;
}
template<typename T>
void List<T>::DeleteNode(unsigned index)
{
	Node<T>* previous = head;
	for (unsigned i = 0; i < index - 1; i++)
		previous = previous->pNext;
	
	Node<T>* toDelete = previous->pNext;
	previous->pNext = toDelete->pNext;
	delete toDelete;

	size--;
}

template<typename T>
T& List<T>::operator[](unsigned index)
{
	unsigned currentIndex = 0;
	T none = T();
	Node<T>* currentNode = head;

	while (currentNode != nullptr)
	{
		if (currentIndex == index)
		{
			return currentNode->data;
		}
		currentNode = currentNode->pNext;
		currentIndex++;
	}

	return none;
}
template<typename T>
void List<T>::operator=(const List<T>& other)
{
	this->Clear();

	this->size = other.size;
	this->head = new Node<T>(other.head->data);

	Node<T>* currentNode = this->head;
	Node<T>* otherCurrentNode = other.head->pNext;
	while (otherCurrentNode != nullptr)
	{
		currentNode->pNext = new Node<T>(otherCurrentNode->data);
		currentNode = currentNode->pNext;
		otherCurrentNode = otherCurrentNode->pNext;
	}
}