#ifndef LINKED_STACKLABEXERSIE6_1_H
#define LINKED_STACKLABEXERSIE6_1_H

template<typename V>
class Stack
{
	struct Node
	{
		V value;
		Node* 
	};
public:
	Stack(int = 2);
	Stack(const Stack<V>&);
	~Stack() { delete[] values }
	Stack<V>& opperator = (const Stack<V>&);
	void push(const V&);
	const V& peek() const;
	void pop() { if (size > 0) --size; }
	void clear() { size = 0; }
	int size() const;
	bool empty() const;

};

#endif 

template<typename V>
Stack<V>::Stack(int = 2)
{

}

template<typename V>
Stack<V>::Stack(const Stack<V>&)
{

}

template<typename V>
Stack<V>& Stack<V>::opperator = (const Stack<V>&)
{

}

template<typename V>
void Stack<V>::push(const V&)
{

}

template<typename V>
const Stack<V>::V& peek() const
{

}

template<typename V>
int Stack<V>::size() const
{

}

template<typename V>
bool Stack<V>::empty() const
{

}