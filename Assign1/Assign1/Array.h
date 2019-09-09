#ifndef ARRAY_H
#define ARRAY_H

class Array
{
private:
	 
	 int values[100];
	 int dummy;

public:
	 Array();
	 int capacity() const;
	 int operator[](int) const; //get
	 int& operator[](int); //set

};

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
}


#endif 


//Capacity not size
//default value
//instead of default
// calues[index] = 0;
//do values[index] = int();
