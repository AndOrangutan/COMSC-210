//Programmer: Von Mueller
//Programmer's ID: 1735441

#ifndef QUEUE_LABEXERCISE6_2_H
#define QUEUE_LABEXERCISE6_2_H

template <typename V>
class Queue
{
	class Node
	{
	public:
		V value;
		Node* next;
	};
	int siz;
	Node* first;
	Node* last;
	V dummy = V();

public:
	Queue();
	Queue(const Queue&); 
	Queue<V>& operator=(const Queue<V>&);
	~Queue();
	void push(const V&);
	const V& front() const;
	const V& back() const;
	void pop();
	int size() const { return siz; }
	bool empty() const { return !siz; }
	void clear();	
};

template <typename V>
Queue<V>::Queue()
{
	first = nullptr;
	last = nullptr;
	siz = 0;
}

template <typename V>
Queue<V>::Queue(const Queue& input)
{
	first = nullptr;
	last = nullptr;
	siz = input.size();
	for (Node* p = input.firstNode; p; p = p->next)
	{
		Node* temp = new Node;
		temp->value = p->value;
		temp->next = nullptr;
		if (last) last->next = temp;
		else first = temp;
		last = temp;
	}
}

template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& input)
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
		last = nullptr;
		siz = input.size();
		for (Node* p = input.firstNode; p; p = p->next)
		{
			Node* temp = new Node;
			temp->value = p->value;
			temp->next = nullptr;
			if (last) last->next = temp;
			else first = temp;
			last = temp;
		}
		siz = input.size();
	}
	return *this;
}

template <typename V>
Queue<V>::~Queue()
{
	while (first)
	{
		Node* p = first;
		firstNode = first->next;
		delete p;
	}
}

template <typename V>
void Queue<V>::push(const V& input)
{
	Node* temp = new Node{ input };
	if (last) last->next = temp;
	else first = temp;
	last = temp;
	siz++
}

template <typename V>
const V& Queue<V>::front() const
{
	if (first)
		return first->value;
	return dummy;
}

template <typename V>
const V& Queue<V>::back() const
{
	if (last)
		return last->value;
	return dummy;
}

template <typename V>
void Queue<V>::pop()
{
	if (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		--siz;
	}
	if (size == 0)
		last = nullptr;
}

template <typename V>
void Queue<V>::clear()
{
	while (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		--siz;
	}
	if (size == 0)
		last = nullptr;
}



#endif