#ifndef ASSOCIATIVEARRAY_LABEXERCISE8_H
#define ASSOCIATIVEARRAY_LABEXERCISE8_H

template <typename K, typename V>
class AssociativeArray //linked-list implementation
{
	class Node
	{
	public:
		K keys;
		V value;
		node* next;
	};

	Node*	firstNode;
	int siz;

public:
	AssociativeArray() { firstNode = 0; siz = 0; }
	AssociativeArray(const AssociativeArray&); //copy construct
	AssociativeArray<K, V>& operator=(const AssociativeArray<K, V>&); // assignment operator
	~AssociativeArray(); // deconstructor
	V operator[] (const K)

};

#endif // !ASSOCIATIVEARRAY_LABEXERCISE8_H

