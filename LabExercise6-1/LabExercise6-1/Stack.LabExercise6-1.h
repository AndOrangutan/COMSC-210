#ifndef STACKLABEXERSIE6_1
#define STACKLABEXERSIE6_1

template<typename V>
class Stack
{
	V* values;
	int cap;
	int size;
	void capacity(int);

public:
	Stack(int = 2);
	Stack(const Stack<V>&);
	~Stack() { delete[] values }
	Stack<V>& opperator=(const Stack<V>&);
	void push(const V&);
	const V& peek() const;
	void pop() { if (size > 0) --size; }
	void clear() { size = 0; }
	int size() const;
	bool empty() const;

};

#endif // !STACKLABEXERSIE6_1

template<typename V>
void Stack<V>::capacity(int input)
{
	// allowcate a new array with the new capacity	
	V* temp = new V[input];

	// get the lesser of the new and old capacities
	int limit = (cap < this->cap ? cap : this->cap);

	//copy the contents
	for (int i = 0; i < limit; i++)
		temp[i] = values[i];

	// set added values to their default
	for (int i = limit; i < input; i++)
		temp[i] = V();

	// deallowcate original array
	delete[] values;

	// switch newly allowcated array into the object
	values = temp;

	//update the capacity
	this->cap = input;
}


template<typename V>
Stack<V>::Stack(int input)
{
	this->cap = input;
	values = new V[cap];

	for (int i = 0; i < cap; i++)
		values[i] = V();
}

template<typename V>
Stack<V>::Stack(const Stack<V>& original)
{
	cap = original.cap; //still just a copy
	values = new V[cap]; //not a copy -- new object gets its own array.

	for (int i = 0; i < cap; i++) //copy the contents of the orginal array
		values[i] = original.values[i]; //...to the copy
	dummy = original.dummy;
}

template<typename V>
Stack<V>& Stack<V>::opperator= (const Stack<V>& original)
{
	if (this != &original)
	{
		//do what destructor does
		delete[] values;

		//do what the copy constructor does
		cap = original.cap; //still just a copy
		values = new T[cap]; //not a copy -- new object gets its own array.

		for (int i = 0; i < cap; i++) //copy the contents of the orginal array
			values[i] = original.values[i]; //...to the copy
		dummy = original.dummy;

	}
	return *this;

}

template<typename V>
void Stack<V>::push(const V& input)
{
	if (size >= cap)
		capacity(cap*2);
	values[size++] = input;
}

template<typename V>
const V& Stack<V>::peek() const
{
	return &values[size];
}

template<typename V>
int Stack<V>::size() const
{
	return size;
}

template<typename V>
bool Stack<V>::empty() const
{
	return !size;
}