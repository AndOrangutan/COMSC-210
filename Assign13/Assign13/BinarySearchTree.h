//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <queue>

template <typename K, typename V>
class BinarySearchTree
{
private:
	struct Node
	{
		K key;
		V value;
		Node* left;
		Node* right;
	};

	int siz;
	Node* rootNode;

	void keys(const Node* , std::queue<K>& ) const;
	void clear(Node* );
	void copyTree(Node*, const Node*);

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<K, V>&);
	~BinarySearchTree() { clear(); }
	BinarySearchTree<K, V>& operator=(const BinarySearchTree<K, V>&);
	std::queue<K> keys() const;
	void clear();	
	void deleteKey(const K& );
	bool containsKey(const K& ); // getter
	V operator[](const K& ) const; // getter
	V& operator[](const K& ); // setter
	
};

// Private ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename K, typename V>
void BinarySearchTree<K, V>::keys(const Node* p, std::queue<K>& q) const
{
	if (!p) return; // detect when the bottom of the tree is reached
	keys(p->left, q);
	q.push(p->key);
	keys(p->right, q);
}

template <typename K, typename V>
void BinarySearchTree<K, V>::clear(Node* p)
{
	if (!p) return; // detect when the bottom of the tree is reached
	clear(p->left);
	clear(p->right);
	delete p;	
}

template <typename K, typename V>
void BinarySearchTree<K, V>::copyTree(Node* p, const Node* copiedTree)
{
	if (!copiedTree) return; // to end the loop
	p->key = copiedTree->key;
	p->value = copiedTree->value;
	p->left = p->right = 0;
	if (copiedTree->left) copyTree(p->left = new Node, copiedTree->left);
	if (copiedTree->right) copyTree(p->right = new Node, copiedTree->right);
}

// Public ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename K, typename V>
BinarySearchTree<K, V>::BinarySearchTree() // default constructor
{
	siz = 0;
	rootNode = nullptr;
}

template <typename K, typename V>
BinarySearchTree<K, V>::BinarySearchTree(const BinarySearchTree<K, V>& original)
{
	rootNode = 0; // in case the copied tree is empty
	if (original.rootNode) copyTree(rootNode = new Node, original.rootNode);
	siz = original.siz;
}

template <typename K, typename V>
BinarySearchTree<K, V>& BinarySearchTree<K, V>::operator=(const BinarySearchTree<K, V>& original)
{
	if (this == &original) return *this;
	clear();

	rootNode = 0; // in case the copied tree is empty
	if (original.rootNode) copyTree(rootNode = new Node, original.rootNode);
	siz = original.siz;
}

template <typename K, typename V>
std::queue<K> BinarySearchTree<K, V>::keys() const
{
	queue<K> result;
	keys(rootNode, result); // calls the other version of the function.
	return result;
}

template <typename K, typename V>
void BinarySearchTree<K, V>::clear()
{
	clear(rootNode);
	rootNode = 0;
	siz = 0;
}

template <typename K, typename V>
void BinarySearchTree<K, V>::deleteKey(const K& key)
{
	Node* p = rootNode;
	Node* prev = 0;
	while (p)
	{
		if (p->key == key) 
			break; // found it!
		prev = p; // save p's old position before advancing it
		if (p->key < key) 
			p = p->right; 
		else 
			p = p->left;
	}

	if (p == nullptr) //  "p" is zero: no match found -- nothing to do
	{
		break; // do nothing
	}
	else if (p->left == nullptr && p->right == nullptr && prev == nullptr) // p->left, p->right, and prev are all zero -- deallocate the root and set root to zero
	{
		delete p;
		rootNode = 0;
		--siz;
	}
	else if (p->left == nullptr && p->right == nullptr) // p->left and p->right are both zero -- deallocate p, set prev's left or right to zero 
	{
		delete p;
		if (prev->left == p) prev->left = 0;
		else prev->right = 0;
		--siz;
	}
	else if (p->left == nullptr) // p->left is zero, seek a right descendent to promote to "p"
	{
		Node* pSave = p; // promote to this node
		prev = p;
		p = p->right; // the "right" step
		while (p->left) // left-left-left
		{
			prev = p; // follow p around...
			p = p->left;
		}
		pSave->key = p->key;
		pSave->value = p->value;
		if (prev->left == p)
			prev->left = p->right;
		else
			prev->right = p->right; // in case there were no left-left-left steps
		delete p;
		--siz;
	}
	else //seek a left descendent to promote to "p"
	{
		Node* pSave = p; // promote to this node
		prev = p;
		p = p->left; // the "left" step
		while (p->right) // right-right-right
		{
			prev = p; // follow p around...
			p = p->right;
		}
		pSave->key = p->key;
		pSave->value = p->value;
		if (prev->right == p) prev->right = p->left;
		else prev->left = p->left; // in case there were no right-right-right steps
		delete p;
		--siz;
	}


}

template <typename K, typename V>
bool BinarySearchTree<K, V>::containsKey(const K& key)
{
	Node* p = rootNode;
	while (p)
	{
		if (p->key == key) break; // found it!
		if (p->key < key) p = p->right; else p = p->left;
	}
	return p != 0; // not found if the above loop exits because p gets to zer
}

template <typename K, typename V>
V BinarySearchTree<K, V>::operator[](const K& key) const
{
	Node* p = rootNode;
	while (p)
	{
		if (p->key == key) break; // found it!
		if (p->key < key) p = p->right; else p = p->left;
	}
	if (p) return p->value;
	return V();
}

template <typename K, typename V>
V& BinarySearchTree<K, V>::operator[](const K& key)
{
	Node* p = rootNode;
	Node* prev = 0;
	while (p)
	{
		if (p->key == key) break; // found it! just return p->value; 
		prev = p; // save p's old position before advancing it
		if (p->key < key) p = p->right; else p = p->left;
	}

	if (rootNode == nullptr) // rootNode is zero: empty tree -- create a new node as the root
	{
		siz++;
		rootNode = new Node{ key, V() };
		return rootNode->value;
	}
	else if (p != nullptr) // p not equals to zero: exited with the if-break -- p points to the matching node
	{
		return p->value;
	}
	else // there's no match, and prev is to be the parent of a new node
	{
		siz++;
		p = new Node;
		p->key = key;
		p->value = V();
		p->left = p->right = 0;

		if (prev->key < key) prev->right = p;
		else prev->left = p;
		return p->value;
	}
}

