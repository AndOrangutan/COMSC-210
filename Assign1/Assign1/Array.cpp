//Programmer: Von Mueller
//Programmer's ID: 1735441

#include "Array.h"

Array::Array()
{
	for (int i = 0; i < 100; i++)
		values[i] = int();
}

int Array::capacity() const
{
	return 100;
}

int Array::operator[](int index) const
{
	if (index < 0)
		return dummy;
	if (index >= 100)
		return dummy;
	return values[index];
}

int& Array::operator[](int index)
{
	if (index < 0) return
		dummy;
	if (index >= 100) return
		dummy;
	return values[index];
}"