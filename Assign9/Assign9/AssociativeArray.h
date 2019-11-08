//Programmer: Von Mueller
//Programmer's ID: 1735441
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
		Node* next;
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
	firstNode = nullptr;
	siz = 0;
}

template <typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& input)
{
	if (this != &input)
	{
		// deallocate existing list
		while (firstNode)
		{
			Node* p = firstNode;
			firstNode = firstNode->next;
			delete p;
		}

		//build new queue
		Node* lastnode = nullptr;
		siz = input.size();
		for (Node* p = input.firstNode; p; p = p->next)
		{
			Node* temp = new Node;
			temp->value = p->value;
			temp->next = nullptr;
			if (lastnode) lastnode->next = temp;
			else firstNode = temp;
			lastnode = temp;
		}
		siz = input.size();
	}
	return *this;
}

template <typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray()
{
	while (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
	}
}

template <typename K, typename V>
const V& AssociativeArray<K, V>::operator[](const K& input) const
{
	for (Node* p = firstNode; p; p = p->next)
		if (p->key == input)
			return p->value;
	return V();
}

template <typename K, typename V>
V& AssociativeArray<K, V>::operator[] (const K& input)
{
	for (Node* p = firstNode; p; p = p->next)
		if (p->key == input)
			return p->value;

	Node* temp = new Node;
	temp->key = input;
	temp->value = V();
	temp->next = firstNode;
	firstNode = temp;
	++siz;
	return firstNode->value;



}

template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& input)
{
	for (Node* p = firstNode; p; p = p->next)
		if (p->key == input)
			return true;
	return false;
}

template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& input)
{
	Node* p, *prev; // declare above loop so that it survives below the loop
	for (p = firstNode, prev = 0; p; prev = p, p = p->next)
		if (p->key == input)
			break;
	
	// if found (that is, p did not run off the end of the list)
	if (p)
	{
		--siz;
		if (prev) prev->next = p->next;
		else firstNode = p->next;
		delete p;
	}
}

template <typename K, typename V>
std::queue<K> AssociativeArray<K, V>::keys() const
{
	std::queue<K> q;
	for (Node* p = firstNode; p; p = p->next)
		q.push(p->key);
	return q;

}

//int size() { return siz; }

template <typename K, typename V>
void AssociativeArray<K,V>::clear()
{
	while (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		--siz;
	}
}

#endif // !ASSOCIATIVEARRAY_LABEXERCISE8_H