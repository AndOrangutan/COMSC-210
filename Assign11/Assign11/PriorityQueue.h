template <typename V>
class PriorityQueue
{
	V* values;
	int cap;
	int siz;
	void capacity(int);

public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue<V>&);
	~PriorityQueue() { delete[] values; }
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
PriorityQueue<V>::PriorityQueue()
{
	cap = 2;
	values = new V[2];

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
		siz = input.siz;

	}
	return *this;
}

template <typename V>
void PriorityQueue<V>::push(const V& input)
{
	siz++; // Just doing this before the break
	if (siz >= cap)
		capacity(cap * 2);

	std::cout << siz;
	values[siz-1] = input;
	int index = siz;
	
	while (index != 0)
	{
		int parent = ((index + 1) / 2 - 1); // create a parent variable that is the parent of "int index;"
		if (values[parent] < values[index]) // if parent is lesser than child, swap values
		{
			V temp = values[index];
			values[index] = values[parent];
			values[parent] = temp;

			index = parent;
		}
		else // you should be sorted :/
			break;
	}

}

template <typename V>
void PriorityQueue<V>::pop()
{
	values[0] = V(); // "delete" head
	
	if (siz == 0) 
		return;

	// Fill the hole implementation
	values[0] = values[siz-1];
	
	int index = 0;

	// loop 1: fill the top position
	while (index < siz)
	{
		int leftIndex = 2 * index + 1; // calc left childs index
		int rightIndex = 2 * index + 2; // calc right childs index

		if (leftIndex >= siz) // if there is no left child, break from the loop -- we reached the bottom of the heap
			break;
		//std::cout << rightIndex << " " << leftIndex << " " << siz << " " << cap << std::endl;
		if (rightIndex == siz) // if there's no right child, copy the VALUE at the left child index to the VALUE at index and set index to the left child index
		{
			values[index] = values[leftIndex];
			index = leftIndex;
		}
		else if(values[rightIndex] < values[leftIndex]) // else if the VALUE at the right child index < the VALUE at the left child index, copy the value at the left child index to the value at index and set index to the left child index
		{
			values[index] = values[leftIndex];
			index = leftIndex;
		}
		else
		{
			values[index] = values[rightIndex];
			index = rightIndex;
		}
	}
	siz--;
	values[index] = values[siz];

	// loop 2: The grand promotion
	while (index > 0) // breaks if index == 0
	{
		int parent = ((index + 1) / 2 - 1); // create a parent variable that is the parent of "int index;"
		if (values[index] < values[parent])
			break;

		V temp = values[index];
		values[index] = values[parent];
		values[parent] = temp;

		index = parent;
	}

}

