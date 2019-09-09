//Programmer: Von Mueller
//Programmer's ID: 1735441

template<typename TYPE, int CAP>
class Array
{
private:

	TYPE values[CAP];
	TYPE dummy = TYPE();

public:
	Array();
	int capacity() const;
	TYPE operator[](int) const; //get
	TYPE& operator[](int); //set

};

template<typename TYPE, int CAP>
Array<TYPE, CAP>::Array()
{
	for (int i = 0; i < CAP; i++)
		values[i] = TYPE();
}

template<typename TYPE, int CAP>
int Array<TYPE, CAP>::capacity() const
{
	return CAP;
}

template<typename TYPE, int CAP>
TYPE Array<TYPE, CAP>::operator[](int index) const
{
	if (index < 0)
		return dummy;
	if (index >= CAP)
		return dummy;
	return values[index];
}

template<typename TYPE, int CAP>
TYPE& Array<TYPE, CAP>::operator[](int index)
{
	if (index < 0) return
		dummy;
	if (index >= CAP) return
		dummy;
	return values[index];
}
