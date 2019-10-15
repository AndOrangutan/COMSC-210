//Programmer: Von Mueller
//Programmer's ID: 1735441

#ifndef STACK_H
#define STACK_H

template <typename V>
class Stack
{


	class Node // I know I could use a struct, I like to use all class or struct
	{
	public:
		V value; // value stored in node
		Node* next; // pointer to next node in the linked list, picture a chain.
	};

	Node* firstNode; // the head pointer
	int siz = 0;
	V dummy = V(); //!!! try to make due without this, and comment it out in the end

public:
	Stack(); // main construct
	Stack(const Stack<V>&); // copy constructor
	~Stack(); // destructor
	Stack<V>& operator=(const Stack<V>&); // assignment operator overload
	void push(const V&); // add a new item to the stack
	const V& peek() const; // return top value without popping it
	void pop(); // set siz to siz-1
	void clear(); // set siz to 0
	int size() const; // return size
	bool empty() const; // return true if empty
};


template <typename V>
Stack<V>::Stack()
{
	firstNode = nullptr;
	siz = 0;
}

template <typename V>
Stack<V>::Stack(const Stack<V>& input)
{
	firstNode = nullptr;
	Node* lastnode = nullptr;
	siz = input.size();
	for (Node* p = input.firstNode; p; p = p->next)
	{
		Node* temp = new Node;
		temp->value = p->value;
		temp->next = nullptr;
		if (lastnode) lastnode->next = temp;
		else firstNode = temp;
		lastnode = temp;
	}
}

template <typename V>
Stack<V>::~Stack()
{
	while (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
	}
}

template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& input)
{
	if (this != &input)
	{
		// deallocate existing list
		while (firstNode)
		{
			Node* p = firstNode;
			firstNode = firstNode->next;
			delete p;
		}

		//build new queue
		Node* lastnode = nullptr;
		siz = input.size();
		for (Node* p = input.firstNode; p; p = p->next)
		{
			Node* temp = new Node;
			temp->value = p->value;
			temp->next = nullptr;
			if (lastnode) lastnode->next = temp;
			else firstNode = temp;
			lastnode = temp;
		}
		siz = input.size();
	}
	return *this;
}

template <typename V>
void Stack<V>::push(const V& input)
{
	
	Node* temp = new Node;
	temp->value = input;
	temp->next = firstNode;
   firstNode = temp;
	siz++;
	
}

template <typename V>
const V& Stack<V>::peek() const
{
	if (firstNode == nullptr) return dummy;
	else return firstNode->value;
}

template <typename V>
void Stack<V>::pop()
{
	if (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		--siz;
	}
}

template <typename V>
void Stack<V>::clear()
{
	while (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		--siz;
	}
}


template <typename V>
int Stack<V>::size() const
{
	return siz;
}

template <typename V>
bool Stack<V>::empty() const
{
	if (firstNode == nullptr)
		return true;
	else
		return false;
}

#endif