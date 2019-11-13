template <typename V>
class PriorityQueue
{
	V* values;
	int cap;
	int siz;
	void capacity(int);

public:
	PriorityQueue(int = 0);
	PriorityQueue(const PriorityQueue<V>&);
	PriorityQueue() { delete[] values; }
	PriorityQueue<V>& operator=(const PriorityQueue<V>&);

	void push(const V&);
	void pop();
	V top() const { return siz == 0 ? V() : values[0]; }
	int size() const { return siz; }
	bool empty() const { return siz == 0 ? true : false; }
	void clear() { siz = 0; }
};

template <typename V>
void PriorityQueue<V>::capacity(int input)
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

template <typename V>
PriorityQueue<V>::PriorityQueue(int input)
{
	this->cap = input;
	siz = input;
	values = new V[cap];

	for (int i = 0; i < cap; i++)
		values[i] = V();
}

template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& input)
{
	cap = input.cap; //still just a copy
	values = new V[cap]; //not a copy -- new object gets its own array.

	for (int i = 0; i < cap; i++) //copy the contents of the orginal array
		values[i] = input.values[i]; //...to the copy
	siz = input.siz;
}

template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& input)
{
	if (this != &input)
	{
		//do what destructor does
		delete[] values;

		//do what the copy constructor does
		cap = input.cap; //still just a copy
		values = new V[cap]; //not a copy -- new object gets its own array.

		for (int i = 0; i < cap; i++) //copy the contents of the orginal array
			values[i] = input.values[i]; //...to the copy
		siz = original.siz;

	}
	return *this;
}

template <typename V>
void PriorityQueue<V>::push(const V& input)
{

}

template <typename V>
void PriorityQueue<V>::pop()
{

}

