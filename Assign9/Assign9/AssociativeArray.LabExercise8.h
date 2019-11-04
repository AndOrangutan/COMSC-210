#ifndef ASSOCIATIVEARRAY_LABEXERCISE8_H
#define ASSOCIATIVEARRAY_LABEXERCISE8_H

#include <queue>

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
	const V& operator[](const K&) const; // getter
	V& operator[] (const K&); // setter
	bool containsKey(const K&); //getter
	void deleteKey(const K&); // setter
	std::queue<K> keys() const;
	int size() { return siz; }
	void clear();
};

//AssociativeArray() { firstNode = 0; siz = 0; }

template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray& input)
{

}

template <typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& input)
{

}

template <typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray()
{

}

template <typename K, typename V>
const V& AssociativeArray<K, V>::operator[](const K& input) const
{
	for (Node* p = firstNode; p; p = p->next)
		if (p->key == key)
			return p->value;
}

template <typename K, typename V>
V& AssociativeArray<K, V>::operator[] (const K& input)
{

}

template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& input)
{

}

template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& input)
{

}

template <typename K, typename V>
std::queue<K> AssociativeArray<K, V>::keys() const
{

}

//int size() { return siz; }

template <typename K, typename V>
void AssociativeArray<K,V>::clear()
{

}

#endif // !ASSOCIATIVEARRAY_LABEXERCISE8_H