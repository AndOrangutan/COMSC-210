//Programmer: Von Mueller
//Programmer's ID: 1735441

class Array
{
private:
	 
	 int values[100];
	 int dummy = 0;

public:
	 Array();
	 int capacity() const;
	 int operator[](int) const; //get
	 int& operator[](int); //set

};


//Capacity not size
//default value
//instead of default
// calues[index] = 0;
//do values[index] = int();
