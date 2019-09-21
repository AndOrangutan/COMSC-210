//Programmer: Von Mueller
//Programmer's ID: 1735441

#ifndef DYNAMICARRAY_LABEXERCISE4_2_H
#define DYNAMICARRAY_LABEXERCISE4_2_H

#include <algorithm>

template<typename T>
class DynamicArray
{
private:
	T* values; //T datatype CAP capacity
	int cap;
	T dummy = T();

public:
	DynamicArray(int = 2);//Constructor //default = 2
	DynamicArray(const DynamicArray<T>&); //Copy constructor
	~DynamicArray(); //Deconstructor
	DynamicArray<T>& operator=(const DynamicArray<T>&); //Assignment Operator
	int capacity() const; //getter
	void capacity(int); //setter
	T operator[] (int) const; //getter
	T& operator[] (int); //setter
};
#endif

template<typename T>
DynamicArray<T>::DynamicArray(int input)//Constructor //default = 2
{
	this->cap = input;
	values = new T[cap];

	for (int i = 0; i < cap; i++)
		values[i] = T();
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original) //Copy constructor
{
	cap = original.cap; //still just a copy
	values = new T[cap]; //not a copy -- new object gets its own array.

	for (int i = 0; i < cap; i++) //copy the contents of the orginal array
		values[i] = original.values[i]; //...to the copy
	dummy = original.dummy;
}

template<typename T>
DynamicArray<T>::~DynamicArray() 
{ delete[] values; }

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original) //Assignment Operator
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
int DynamicArray<T>::capacity() const //getter
{
	return this->cap;
}

template<typename T>
void DynamicArray<T>::capacity(int input) //setter
{
	// allowcate a new array with the new capacity	
	T* temp = new T[input];

	// get the lesser of the new and old capacities
	int limit = min(input, this->cap); //requires C++ "algorithm" library
	
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
T DynamicArray<T>::operator[] (int input) const //getter
{
	if (index < 0 || index >= cap)
		return T();
	return value[index];
}

template <typename T>
T& DynamicArray<T>::operator[] (int index) //setter
{
	if (index < 0) 
		return dummy;
	if (index >= cap) 
		capacity(2 * index); // more than enough to include this index 
}