//Programmer: Von Mueller
//Programmer's ID: 1735441

// Recent changes
	// added sort
	// optimized a few sections of code
	//	removed built in size since i wasn't keeping track of it properly and it really isn't needed.


#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

#include <cstdlib>


template<typename T>
class SortableArray
{
private:
	T* values; //T datatype CAP capacity
	int cap;
	T dummy = T();
	

public:
	SortableArray(int = 2);//Constructor //default = 2
	SortableArray(const SortableArray<T>&); //Copy constructor
	~SortableArray(); //Deconstructor
	SortableArray<T>& operator=(const SortableArray<T>&); //Assignment Operator

	int capacity() const; //getter
	void capacity(int); //setter
	const T& operator[] (int) const; //getter
	T& operator[] (int); //setter

	void sort(int);
};


template<typename T>
SortableArray<T>::SortableArray(int input)//Constructor //default = 2
{
	this->cap = input;
	values = new T[cap];

	for (int i = 0; i < cap; i++)
		values[i] = T();
}

template<typename T>
SortableArray<T>::SortableArray(const SortableArray<T>& original) //Copy constructor
{
	cap = original.cap; //still just a copy
	values = new T[cap]; //not a copy -- new object gets its own array.

	for (int i = 0; i < cap; i++) //copy the contents of the orginal array
		values[i] = original.values[i]; //...to the copy
	dummy = original.dummy;
}

template<typename T>
SortableArray<T>::~SortableArray()
{
	delete[] values;
}

template<typename T>
SortableArray<T>& SortableArray<T>::operator=(const SortableArray<T>& original) //Assignment Operator
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

template<typename T>
int SortableArray<T>::capacity() const //getter
{
	return cap;
}

template<typename T>
void SortableArray<T>::capacity(int input) //setter
{
	// allowcate a new array with the new capacity	
	T* temp = new T[input];

	// get the lesser of the new and old capacities
	int limit = (cap < this->cap ? cap : this->cap);

	//copy the contents
	for (int i = 0; i < limit; i++)
		temp[i] = values[i];

	// set added values to their default
	for (int i = limit; i < input; i++)
		temp[i] = T();

	// deallowcate original array
	delete[] values;

	// switch newly allowcated array into the object
	values = temp;

	//update the capacity
	this->cap = input;
}

template<typename T>
const T& SortableArray<T>::operator[] (int index) const //getter
{
	if (index < 0 || index >= cap)
		return T();
	return values[index];
}

template <typename T>
T& SortableArray<T>::operator[] (int index) //setter
{
	if (index < 0)
		return dummy;
	if (index >= cap)
		capacity(2 * index);
	return values[index];
}

template<typename T>
void SortableArray<T>::sort(int fillLine)
{
	double* temp = new double[fillLine];
	for (int delta = 1; delta < fillLine; delta *= 2)
	{
		int index = 0;
		for (int i = 0; i < fillLine; i++) 
			temp[i] = values[i];
		for (int i = 0; i < fillLine; i += 2 * delta)
		{
			int left = i;
			int leftMax, rightMax;
			//int leftMax = std::min(left + delta, fillLine);
			if (left + delta < fillLine)
				leftMax = left + delta;
			else
				leftMax = fillLine;
			int right = leftMax;
			//int rightMax = std::min(right + delta, fillLine);
			if (right + delta < fillLine)
				rightMax = right + delta;
			else
				rightMax = fillLine;

			while (true)
			{
				if (left == leftMax && right == rightMax) 
					break;
				if (left == leftMax) 
					values[index++] = temp[right++];
				else if (right == rightMax) 
					values[index++] = temp[left++];
				else if (temp[right] < temp[left]) 
					values[index++] = temp[right++];
				else 
					values[index++] = temp[left++];
			}
		}
	}
	delete[] temp;
}

#endif//Programmer: Von Mueller
//Programmer's ID: 1735441

// Recent changes
	// added sort
	// optimized a few sections of code
	//	removed built in size since i wasn't keeping track of it properly and it really isn't needed.


#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

#include <cstdlib>


template<typename T>
class SortableArray
{
private:
	T* values; //T datatype CAP capacity
	int cap;
	T dummy = T();
	

public:
	SortableArray(int = 2);//Constructor //default = 2
	SortableArray(const SortableArray<T>&); //Copy constructor
	~SortableArray(); //Deconstructor
	SortableArray<T>& operator=(const SortableArray<T>&); //Assignment Operator

	int capacity() const; //getter
	void capacity(int); //setter
	const T& operator[] (int) const; //getter
	T& operator[] (int); //setter

	void sort(int);
};


template<typename T>
SortableArray<T>::SortableArray(int input)//Constructor //default = 2
{
	this->cap = input;
	values = new T[cap];

	for (int i = 0; i < cap; i++)
		values[i] = T();
}

template<typename T>
SortableArray<T>::SortableArray(const SortableArray<T>& original) //Copy constructor
{
	cap = original.cap; //still just a copy
	values = new T[cap]; //not a copy -- new object gets its own array.

	for (int i = 0; i < cap; i++) //copy the contents of the orginal array
		values[i] = original.values[i]; //...to the copy
	dummy = original.dummy;
}

template<typename T>
SortableArray<T>::~SortableArray()
{
	delete[] values;
}

template<typename T>
SortableArray<T>& SortableArray<T>::operator=(const SortableArray<T>& original) //Assignment Operator
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

template<typename T>
int SortableArray<T>::capacity() const //getter
{
	return cap;
}

template<typename T>
void SortableArray<T>::capacity(int input) //setter
{
	// allowcate a new array with the new capacity	
	T* temp = new T[input];

	// get the lesser of the new and old capacities
	int limit = (cap < this->cap ? cap : this->cap);

	//copy the contents
	for (int i = 0; i < limit; i++)
		temp[i] = values[i];

	// set added values to their default
	for (int i = limit; i < input; i++)
		temp[i] = T();

	// deallowcate original array
	delete[] values;

	// switch newly allowcated array into the object
	values = temp;

	//update the capacity
	this->cap = input;
}

template<typename T>
const T& SortableArray<T>::operator[] (int index) const //getter
{
	if (index < 0 || index >= cap)
		return T();
	return values[index];
}

template <typename T>
T& SortableArray<T>::operator[] (int index) //setter
{
	if (index < 0)
		return dummy;
	if (index >= cap)
		capacity(2 * index);
	return values[index];
}

template<typename T>
void SortableArray<T>::sort(int fillLine)
{
	double* temp = new double[fillLine];
	for (int delta = 1; delta < fillLine; delta *= 2)
	{
		int index = 0;
		for (int i = 0; i < fillLine; i++) 
			temp[i] = values[i];
		for (int i = 0; i < fillLine; i += 2 * delta)
		{
			int left = i;
			int leftMax, rightMax;
			//int leftMax = std::min(left + delta, fillLine);
			if (left + delta < fillLine)
				leftMax = left + delta;
			else
				leftMax = fillLine;
			int right = leftMax;
			//int rightMax = std::min(right + delta, fillLine);
			if (right + delta < fillLine)
				rightMax = right + delta;
			else
				rightMax = fillLine;

			while (true)
			{
				if (left == leftMax && right == rightMax) 
					break;
				if (left == leftMax) 
					values[index++] = temp[right++];
				else if (right == rightMax) 
					values[index++] = temp[left++];
				else if (temp[right] < temp[left]) 
					values[index++] = temp[right++];
				else 
					values[index++] = temp[left++];
			}
		}
	}
	delete[] temp;
}

#endif