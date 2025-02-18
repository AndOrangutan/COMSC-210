//Programmer: Von Mueller
//Programmer's ID: 1735441

template<typename T, int CAP>
class Array
{
private:

	T values[CAP];
	T dummy = T();

public:
	Array();
	int capacity() const;
	T operator[](int) const; //get
	T& operator[](int); //set

};

template<typename T, int CAP>
Array<T, CAP>::Array()
{
	for (int i = 0; i < CAP; i++)
		values[i] = T();
}

template<typename T, int CAP>
int Array<T, CAP>::capacity() const
{
	return CAP;
}

template<typename T, int CAP>
T Array<T, CAP>::operator[](int index) const
{
	if (index < 0)
		return dummy;
	if (index >= CAP)
		return dummy;
	return values[index];
}

template<typename T, int CAP>
T& Array<T, CAP>::operator[](int index)
{
	if (index < 0) return
		dummy;
	if (index >= CAP) return
		dummy;
	return values[index];
}
