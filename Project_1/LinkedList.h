#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>


//#include "leaker.h"

using namespace std;

template <typename T>
class LinkedList
{

public:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;

	public:
		Node(T value);
	};

	LinkedList();

	void AddHead(const T& data);
	void AddTail(const T& data);
	unsigned int NodeCount() const;
	void PrintForward() const;
	void PrintReverse() const;
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);

	~LinkedList();
	LinkedList(const LinkedList& otherList);
	LinkedList<T>& operator=(const LinkedList& otherList);

	void FindAll(vector<LinkedList<T>::Node*>& finds, T val) const;
	LinkedList<T>::Node* Find(const T val);
	const LinkedList<T>::Node* Find(const T val) const;
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;
	Node* GetNode(unsigned int index);
	const Node* GetNode(unsigned int index) const;
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);
	bool operator==(const LinkedList<T>& rhs) const;


	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(unsigned int index);
	void Clear();
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;


private:
	Node* head;
	Node* tail;
	unsigned int totalNodes;

};

template <typename T>
LinkedList<T>::LinkedList()
{
	totalNodes = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void LinkedList<T>::AddHead(const T& data)
{
	if (head != nullptr)
	{
		Node* newHead = new Node(data);
		newHead->next = head;
		head->prev = newHead;
		head = newHead;
		totalNodes++;
		//delete newHead;
	}
	else {
		head = new Node(data);
		tail = head;
		totalNodes++;
	}
}

template <typename T>
void LinkedList<T>::AddTail(const T& data)
{
	if (tail != nullptr)
	{
		Node* newTail = new Node(data);
		newTail->prev = tail;
		tail->next = newTail;
		tail = newTail;
		totalNodes++;
		//delete newHead;
	}
	else {
		tail = new Node(data);
		head = tail;
		totalNodes++;
	}
}

template <typename T>
LinkedList<T>::Node::Node(T value)
{
	data = value;
	next = nullptr;
	prev = nullptr;
	//totalNodes++;
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const
{
	/*int totNodes = 0;
	Node* aNode = head;
	while (aNode->nextNode != nullptr) {
		totNodes++;
	}
	return totNodes;*/
	return totalNodes;
}

template <typename T>
void LinkedList<T>::PrintForward() const
{
	Node* aNode = head;
	for (unsigned int i = 0; i < totalNodes; i++)
	{
		cout << aNode->data << endl;
		aNode = aNode->next;
	}
	//delete aNode;
}

template <typename T>
void LinkedList<T>::PrintReverse() const
{
	Node* aNode = tail;
	for (unsigned int i = 0; i < totalNodes; i++)
	{
		cout << aNode->data << endl;
		aNode = aNode->prev;
	}
	//delete aNode;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	for (unsigned int i = count; i > 0; i--)
	{
		AddHead(data[i - 1]);
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		AddTail(data[i]);
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node* aNode = head;
	Node* anothNode;
	for (unsigned int i = 0; i < totalNodes; i++)
	{
		anothNode = aNode->next;
		delete aNode;
		aNode = anothNode;
	}
	//delete aNode;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& otherList)
{
	this->head = new Node(otherList.head->data);
	this->tail = this->head;
	this->totalNodes = otherList.totalNodes;
	Node* aNode = this->head;
	Node* anothNode = otherList.head->next;
	Node* newTail = nullptr;
	for (unsigned int i = 1; i < totalNodes; i++)
	{
		newTail = new Node(anothNode->data);
		newTail->prev = this->tail;
		aNode->next = newTail;
		this->tail = newTail;
		aNode = aNode->next;
		anothNode = anothNode->next;
	}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& otherList)
{
	Node* aNode = head;
	Node* anothNode;
	for (unsigned int i = 0; i < totalNodes; i++)
	{
		anothNode = aNode->next;
		delete aNode;
		aNode = anothNode;
	}
	this->head = new Node(otherList.head->data);
	this->tail = this->head;
	this->totalNodes = otherList.totalNodes;
	aNode = this->head;
	anothNode = otherList.head->next;
	Node* newTail = nullptr;
	for (unsigned int i = 1; i < totalNodes; i++)
	{
		newTail = new Node(anothNode->data);
		newTail->prev = this->tail;
		aNode->next = newTail;
		this->tail = newTail;
		aNode = aNode->next;
		anothNode = anothNode->next;
	}
	return *this;
}

template<typename T>
void LinkedList<T>::FindAll(vector<LinkedList<T>::Node*>& finds, T val) const
{
	Node* aNode = head;
	for (unsigned int i = 0; i < totalNodes; i++)
	{
		if (aNode->data == val)
		{
			finds.push_back(aNode);
		}
		aNode = aNode->next;
	}
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T val)
{
	Node* aNode = head;
	for (unsigned int i = 0; i < totalNodes; i++)
	{
		if (aNode->data == val)
		{
			return aNode;
		}
		aNode = aNode->next;
	}
	return nullptr;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T val) const
{
	Node* aNode = head;
	for (unsigned int i = 0; i < totalNodes; i++)
	{
		if (aNode->data == val)
		{
			return aNode;
		}
		aNode = aNode->next;
	}
	return nullptr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return head;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const
{
	return head;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return tail;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const
{
	return tail;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
	if (index >= totalNodes)
	{
		throw out_of_range("index out of bounds");
	}
	else
	{
		Node* aNode = head;
		for (unsigned int i = 0; i < index; i++)
		{
			aNode = aNode->next;
		}
		return aNode;
	}
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
{
	if (index >= totalNodes)
	{
		throw out_of_range("index out of bounds");
	}
	else
	{
		Node* aNode = head;
		for (unsigned int i = 0; i < index; i++)
		{
			aNode = aNode->next;
		}
		return aNode;
	}
}

template<typename T>
T& LinkedList<T>::operator[](unsigned int index)
{
	return GetNode(index)->data;
}

template<typename T>
const T& LinkedList<T>::operator[](unsigned int index) const
{
	return GetNode(index)->data;
}

template<typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	if (node == tail)
	{
		AddTail(data);
	}
	else
	{
		if (node != nullptr)
		{
			Node* newNode = new Node(data);
			newNode->next = node->next;
			node->next->prev = newNode;
			node->next = newNode;
			newNode->prev = node;
			totalNodes++;
		}
	}
}

template<typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	if (node == head)
	{
		AddHead(data);
	}
	else
	{
		if (node != nullptr)
		{
			Node* newNode = new Node(data);
			newNode->next = node;
			newNode->prev = node->prev;
			if (node->prev != nullptr)
			{
				node->prev->next = newNode;

			}
			node->prev = newNode;
			totalNodes++;
		}
	}
}

template<typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
	if (index > totalNodes)
	{
		throw out_of_range("index out of bounds");
	}
	else
	{
		Node* aNode = head;
		if (index < totalNodes)
		{
			for (unsigned int i = 0; i < index; i++)
			{
				aNode = aNode->next;
			}
			InsertBefore(aNode, data);
		}
		else
		{
			for (unsigned int i = 0; i < (index - 1); i++)
			{
				aNode = aNode->next;
			}
			InsertAfter(aNode, data);
		}
	}
}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
	if (totalNodes != rhs.totalNodes)
	{
		return false;
	}
	Node* aNode = head;
	Node* anothNode = rhs.head;
	for (unsigned int i = 0; i < totalNodes; i++)
	{
		if (aNode->data != anothNode->data)
		{
			return false;
		}
		aNode = aNode->next;
		anothNode = anothNode->next;
	}
	return true;
}

template<typename T>
bool LinkedList<T>::RemoveHead()
{
	if (head == nullptr)
	{
		return false;
	}
	else
	{
		Node* temp = head->next;
		delete head;
		head = temp;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		totalNodes--;
		return true;
	}
}

template<typename T>
bool LinkedList<T>::RemoveTail()
{
	if (tail == nullptr)
	{
		return false;
	}
	else
	{
		Node* temp = tail->prev;
		delete tail;
		tail = temp;
		if (tail != nullptr)
		{
			tail->next = nullptr;
		}
		else
		{
			head = nullptr;
		}
		totalNodes--;
		return true;
	}
}

template<typename T>
unsigned int LinkedList<T>::Remove(const T& data)
{
	unsigned int total = 0;
	Node* anNode = head;
	Node* anothNode = nullptr;
	unsigned int i = 0;
	while (anNode != nullptr)
	{
		if (anNode->data == data)
		{
			anothNode = anNode->next;
			RemoveAt(i);
			anNode = anothNode;
			total++;
		}
		else
		{
			anNode = anNode->next;
			i++;
		}
	}
	
	return total;
}

template<typename T>
bool LinkedList<T>::RemoveAt(unsigned int index)
{
	if (index >= totalNodes)
	{
		return false;
	}
	Node* aNode = head;
	for (unsigned int i = 0; i < index; i++)
	{
		aNode = aNode->next;
	}

	if (aNode->prev != nullptr)
	{
		aNode->prev->next = aNode->next;
	}
	if (aNode->next != nullptr)
	{
		aNode->next->prev = aNode->prev;
	}
	delete aNode;
	
	totalNodes--;
	return true;
}

template<typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const
{
	if (node != nullptr)
	{
		cout << node->data << endl;
	}
	if (node->next != nullptr)
	{
		PrintForwardRecursive(node->next);
	}
}

template<typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const
{
	if (node != nullptr)
	{
		cout << node->data << endl;
	}
	if (node->prev != nullptr)
	{
		PrintReverseRecursive(node->prev);
	}
}

template<typename T>
void LinkedList<T>::Clear()
{
	Node* aNode = head;
	Node* anothNode = head;
	for (unsigned int i = 0; i < totalNodes; i++)
	{
		aNode = anothNode;
		if (aNode->next != nullptr)
		{
			anothNode = aNode->next;

		}
		delete aNode;
	}
	head = nullptr;
	tail = nullptr;
	totalNodes = 0;
}