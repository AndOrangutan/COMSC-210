#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <queue>
#include <list>

template <typename K, typename V, int CAP>
class HashTable
{
	class Node
	{
	public:
		K key;
		V value;
	};

	std::list<Node> data[CAP]; // chaining
	int(*hashCode)(const K&); // ptr to hashCode function // alias for hash code function
	int siz; // occupied elements in array
	

public:
	HashTable(int(*hashCode)(const K&)=0); // =0 for a "default contructor
	double loadfactor() const { return 1.0 * siz / CAP; }
	V operator[](const K&) const; // getter
	V& operator[](const K&); // setter
	bool containsKey(const K&); // getter
	void deleteKey(const K&); // setter
	std::queue<K> keys() const;
	int size() const { return siz; }
	void clear();
};

template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable(int(*hashCode)(const K&))
{
	this->hashCode = hashCode;
	siz = 0;
}

template <typename K, typename V, int CAP>
V HashTable<K, V, CAP>::operator[](const K& key) const
{
	// get index hashing
	int index = hashCode(key) % CAP;
	if (index < 0) index += CAP;

	// search key loop
	typename list<Node>::iterator it;
	for (it = data[index].begin(); it != data[index].end(); it++)
		if (it->key == key)
			return it->value; // found and return
}

template <typename K , typename V, int CAP>
V& HashTable<K, V, CAP>::operator[](const K& key)
{
	// get index hashing
	int index = hashCode(key) % CAP;
	if (index < 0) index += CAP;
	
	// search key loop
	typename list<Node>::iterator it;
	for (it = data[index].begin(); it != data[index].end(); it++)
		if (it->key == key)
			return it->value; // found and return

	// create new Node to list
	if (data[index].empty()) siz++;
	Node temp;
	temp.key = key;
	temp.value = V();
	data[index].push_back(temp);
	return data[index].back().value;
}

template <typename K, typename V, int CAP>
bool HashTable<K, V, CAP>::containsKey(const K& key)
{
	int index = hashCode(key) % CAP;
	if (index < 0) index += CAP;
	typename list<Node>::const_iterator it; // getters need to use const_iterator
	for (it = data[index].begin(); it != data[index].end(); it++)
		if (it->key == key)
			break;
	if (it == data[index].end())
		return false;
	return true;
}

template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::deleteKey(const K& key)
{
	int index = hashCode(key) % CAP;
	if (index < 0) index += CAP;

	typename list<Node>::const_iterator it; // getters need to use const_iterator
	for(it = data[index].begin(); it != data[index].end(); it++)
		if (it->key == key)
		{
			data[index].erase(it);
			break;
		}

	if (data[index].empsty()) siz--;
}

template <typename K, typename V, int CAP>
std::queue<K> HashTable<K, V, CAP>::keys() const
{
	queue<K> keys;
	for (int i = 0; i < CAP; i++)
	{
		typename list<Node>::const_iterator it;
		for (it = data[i].begin(); it != data[i].end(); it++)
			keys.push(it->key);
	}
	return keys;
}

template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::clear()
{
	for (int i = 0; i < CAP; i++)
		data[i].clear();
	siz = 0;
}

#endif