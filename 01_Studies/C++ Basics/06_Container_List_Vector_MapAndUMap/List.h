#pragma once

template<typename T>
struct Node
{
	Node() {}
	Node(T data)
	{
		this->data = data;
	}

	T data = 0;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
};


template<typename T>
class List
{
public:

	class Iterator
	{
	public:
		Iterator() : nodePtr(nullptr) {}
		Iterator(Node<T>* otherPtr) : nodePtr(otherPtr) {}

		// 복사대입생성자
		Iterator(const Iterator& other) { nodePtr = other.nodePtr; }

		// 복사대입연산자
		Iterator& operator=(const Iterator& other) { nodePtr = other.nodePtr; return *this; }

		// != 비교연산자
		bool operator!=(const Iterator& other) { return nodePtr != other.nodePtr; }
		bool operator==(const Iterator& other) { return nodePtr == other.nodePtr; }

		// ++ 증감연산자
		Iterator& operator++()
		{
			nodePtr = nodePtr->next;

			return *this;
		}

		Iterator operator++(int)
		{
			Iterator result = *this;
			nodePtr = nodePtr->next;

			return result;
		}

		// * 간접연산자
		T& operator*()
		{
			return (*nodePtr).data;
		}

	private:
		Node<T>* nodePtr;
	};


	List()
		: _size(0)
	{
		_head = new Node<T>();
		_head->next = _head;
		_head->prev = _head;
	}

	void PushBack(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* nextNode = _head;
		Node<T>* prevNode = _head->prev;

		newNode->next = nextNode;
		nextNode->prev = newNode;

		newNode->prev = prevNode;
		prevNode->next = newNode;

		_size++;
	}

	void PushFront(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = _head;
		Node<T>* nextNode = _head->next;

		newNode->prev = prevNode;
		newNode->next = nextNode;

		prevNode->next = newNode;
		nextNode->prev = newNode;

		_size++;
	}

	Node<T>* FindNode(int index)
	{
		Node<T>* curNode = _head->next;
		for (int i = 0; i < index; i++)
		{
			curNode = curNode->next;
		}

		return curNode;
	}

	void Insert(const T& value, Node<T>* prev)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = prev;
		Node<T>* nextNode = prev->next;

		newNode->prev = prevNode;
		newNode->next = nextNode;

		prevNode->next = newNode;
		nextNode->prev = newNode;

		_size++;
	}

	void PopBack()
	{
		if (_size == 0)
			return;
		Node<T>* deleteNode = _head->prev;
		Node<T>* lastNode = deleteNode->prev;
		lastNode->next = _head;
		_head->prev = lastNode;

		delete deleteNode;

		_size--;
	}

	void PopFront()
	{
		if (_size == 0)
			return;
		Node<T>* deleteNode = _head->next;
		Node<T>* firstNode = deleteNode->next;
		firstNode->prev = _head;
		_head->next = firstNode;

		delete deleteNode;

		_size--;
	}

	void Clear()
	{
		Node<T>* curNode = _head;
		for (int i = 0; i < _size - 1; i++)
		{
			PopBack();
		}
	}

	const T& operator[](int index)
	{
		return FindNode(index)->data;
	}

	int Size()
	{
		return _size;
	}

	List<T>::Iterator begin() { return List<T>::Iterator(_head->next); }
	List<T>::Iterator end() { return List<T>::Iterator(_head); }

private:
	int _size;
	Node<T>* _head;
};