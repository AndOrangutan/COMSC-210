//Programmer: Von Mueller
//Programmer's ID: 1735441

#ifndef STATICARRAY_H
#define STATICARRAY_H

template<typename T, int CAP>
class StaticArray
{
private:

	T values[CAP];
	T dummy = T();

public:
	StaticArray();
	int capacity() const;
	T operator[](int) const; //get
	T& operator[](int); //set

};

template<typename T, int CAP>
StaticArray<T, CAP>::StaticArray()
{
	for (int i = 0; i < CAP; i++)
		values[i] = T();
}

template<typename T, int CAP>
int StaticArray<T, CAP>::capacity() const
{
	return CAP;
}

template<typename T, int CAP>
T StaticArray<T, CAP>::operator[](int index) const
{
	if (index < 0)
		return dummy;
	if (index >= CAP)
		return dummy;
	return values[index];
}

template<typename T, int CAP>
T& StaticArray<T, CAP>::operator[](int index)
{
	if (index < 0) return
		dummy;
	if (index >= CAP) return
		dummy;
	return values[index];
}

#endif