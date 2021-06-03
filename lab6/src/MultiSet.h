#pragma once
#include <iterator>
#include <exception>

template<class keyType>
class MultiSet {
private:
	struct Node {
		keyType key;
		int number;
		Node* rightChild; //bigger
		Node* leftChild;  //smaller
		Node(keyType key, int number = 1, Node* rightChild = nullptr, Node* leftChild = nullptr) : key(key) {
			this->number = number;
			this->rightChild = rightChild;
			this->leftChild = leftChild;
		}
	};
	Node* root;
	int size;
	void clear(Node* n) {
		if (n->leftChild != nullptr) {
			clear(n->leftChild);
		}
		if (n->rightChild != nullptr) {
			clear(n->rightChild);
		}
		delete n;
	}
	void copyNode(Node& newNode, Node& oldNode) { //used only for recursion in BST constructor and operator=
		if (oldNode.rightChild != nullptr) {
			newNode.rightChild = new Node(oldNode.rightChild->key, oldNode.rightChild->number);
			copyNode(*newNode.rightChild, *oldNode.rightChild);
		}
		if (oldNode.leftChild != nullptr) {
			newNode.leftChild = new Node(oldNode.leftChild->key, oldNode.leftChild->number);
			copyNode(*newNode.leftChild, *oldNode.leftChild);
		}
	}
	Node* next(Node* node) {  //return default key value, if haven't found bigger value
		keyType key = node->key;
		Node* requiredPtr = nullptr;
		Node* ptr = root;
		while (ptr != nullptr) {
			if (ptr->key <= key) {
				ptr = ptr->rightChild;
			}
			else if (ptr->key > key) {
				requiredPtr = ptr;
				ptr = ptr->leftChild;
			}
		}
		return requiredPtr;
	}
	Node* previous(Node* node) {
		keyType key = node->key;
		Node* requiredPtr = nullptr;
		Node* ptr = root;
		while (ptr != nullptr) {
			if (ptr->key >= key) {
				ptr = ptr->leftChild;
			}
			else if (ptr->key < key) {
				requiredPtr = ptr;
				ptr = ptr->rightChild;
			}
		}
		return requiredPtr;
	}
	Node* minimum(int value) {
		Node* ptr = root;
		if (ptr != nullptr) {
			while (ptr->leftChild != nullptr) {
				ptr = ptr->leftChild;
			}
		}
		return ptr;
	}
	Node* maximum(int value) {
		Node* ptr = root;
		if (ptr != nullptr) {
			while (ptr->rightChild != nullptr) {
				ptr = ptr->rightChild;
			}
		}
		return ptr;
	}
public:
	MultiSet() {
		root = nullptr;
		size = 0;
	}
	MultiSet(keyType key) {
		root = new Node(key);
		size = 1;
	}
	MultiSet(const MultiSet& bst) {
		this->size = bst.size;
		if (bst.size == 0) {
			root = nullptr;
			return;
		}
		root = new Node(bst.root->key, bst.root->number);
		Node* bstPtr = bst.root;
		Node* ptr = root;
		copyNode(*root, *bst.root);
	}
	MultiSet& operator=(const MultiSet& bst) {
		this->size = bst.size;
		if (bst.size == 0) {
			root = nullptr;
			return *this;
		}
		root = new Node(bst.root->key, bst.root->number);
		Node* bstPtr = bst.root;
		Node* ptr = root;
		copyNode(*root, *bst.root);
		return *this;
	}
private:
	void countLeaves(Node* n, int& counter) {
		if (n->rightChild == nullptr && n->leftChild == nullptr) {
			counter++;
		}
		if (n->rightChild != nullptr) {
			countLeaves(n->rightChild, counter);
		}
		if (n->leftChild != nullptr) {
			countLeaves(n->leftChild, counter);
		}
	}
public:
	int numberOfLeaves() {
		int counter = 0;
		if (root != nullptr) {
			countLeaves(root, counter);
		}
		return counter;
	}
	class Iterator : std::iterator< std::bidirectional_iterator_tag, Node> {
	private:
		Node* ptr;
		MultiSet* bst;
	public:
		Iterator(Node* ptr, MultiSet* bst) {
			this->ptr = ptr;
			this->bst = bst;
		}
		Iterator(const Iterator& it) {
			this->ptr = it.ptr;
			this->bst = it.bst;
		}
		Iterator& operator=(const Iterator& it) {
			this->ptr = it.ptr;
			this->bst = it.bst;
			return *this;
		}
		Iterator& operator++() {
			ptr = bst->next(ptr);
			return *this;
		}
		Iterator& operator--() {
			ptr = bst->previous(ptr);
			return *this;
		}
		Iterator operator++(int) {
			Iterator temp = *this;
			ptr = bst->next(ptr);
			return temp;
		}
		Iterator operator--(int) {
			Iterator temp = *this;
			ptr = bst->previous(ptr);
			return temp;
		}
		bool operator==(const Iterator& it) {
			return (ptr == it.ptr && bst == it.bst);
		}
		bool operator!=(const Iterator& it) {
			return (ptr != it.ptr || bst != it.bst);
		}
		std::pair<const keyType, int> operator*() {
			return std::make_pair(ptr->key, ptr->number);
		}
	};
	void insert(keyType key) {
		bool placed = false;
		Node* ptr = root;
		if (ptr == nullptr) {
			root = new Node(key);
			size = 1;
			placed = true;
		}
		while (!placed) {
			if (ptr->key == key) {
				ptr->number++;
				break;
			}
			if (ptr->key < key) {
				if (ptr->rightChild != nullptr) {
					ptr = ptr->rightChild;
				}
				else {
					ptr->rightChild = new Node(key);
					placed = true;
					size++;
				}
			}
			else {
				if (ptr->leftChild != nullptr) {
					ptr = ptr->leftChild;
				}
				else {
					ptr->leftChild = new Node(key);
					placed = true;
					size++;
				}
			}
		}
	}
	void erase(keyType key) {
		bool erased = false;
		Node* ptr = root;
		Node* ptrParent = nullptr;
		if (ptr == nullptr) {
			return;
		}
		while (!erased) {
			if (ptr->key == key) {
				erased = true;
				ptr->number--;
				if (ptr->number > 0) {
					break;
				}
				size--;
				if (ptrParent == nullptr) {
					if (ptr->rightChild == nullptr && ptr->leftChild == nullptr) {
						delete ptr;
						root = nullptr;
					}
					else if (ptr->rightChild == nullptr && ptr->leftChild != nullptr) {
						root = ptr->leftChild;
						delete ptr;
					}
					else if (ptr->rightChild != nullptr && ptr->leftChild == nullptr) {
						root = ptr->rightChild;
						delete ptr;
					}
					else {
						Node* startingNode = root;
						Node* requiredNode = nullptr;
						Node* requiredNodeParent = root;
						startingNode = startingNode->rightChild;  //can go right only once
						if (startingNode->leftChild == nullptr) {
							requiredNode = startingNode;
						}
						else {
							do {
								requiredNodeParent = startingNode;
								startingNode = startingNode->leftChild;
								requiredNode = startingNode;
							} while (startingNode->leftChild != nullptr);
						}
						if (requiredNodeParent->rightChild == requiredNode) {
							requiredNodeParent->rightChild = requiredNode->rightChild; //there is no left child in required Node
						}
						else {
							requiredNodeParent->leftChild = requiredNode->rightChild;
						}
						requiredNode->leftChild = root->leftChild;
						requiredNode->rightChild = root->rightChild;
						root = requiredNode;
						delete ptr;
					}
				}
				else {
					if (ptr->rightChild == nullptr && ptr->leftChild == nullptr) {
						if (ptrParent->rightChild == ptr) {
							ptrParent->rightChild = nullptr;
						}
						else {
							ptrParent->leftChild = nullptr;
						}
						delete ptr;
					}
					else if (ptr->rightChild == nullptr && ptr->leftChild != nullptr) {
						if (ptrParent->rightChild == ptr) {
							ptrParent->rightChild = ptr->leftChild;
						}
						else {
							ptrParent->leftChild = ptr->leftChild;
						}
						delete ptr;
					}
					else if (ptr->rightChild != nullptr && ptr->leftChild == nullptr) {
						if (ptrParent->rightChild == ptr) {
							ptrParent->rightChild = ptr->rightChild;
						}
						else {
							ptrParent->leftChild = ptr->rightChild;
						}
						delete ptr;
					}
					else {
						Node* startingNode = ptr;
						Node* requiredNode = nullptr;
						Node* requiredNodeParent = ptr;
						startingNode = startingNode->rightChild;  //can go right only once
						if (startingNode->leftChild == nullptr) {
							requiredNode = startingNode;
						}
						else {
							do {
								requiredNodeParent = startingNode;
								startingNode = startingNode->leftChild;
								requiredNode = startingNode;
							} while (startingNode->leftChild != nullptr);
						}
						if (requiredNodeParent->rightChild == requiredNode) {
							requiredNodeParent->rightChild = requiredNode->rightChild; //there is no left child in required Node
						}
						else {
							requiredNodeParent->leftChild = requiredNode->rightChild;
						}
						if (ptrParent->rightChild == ptr) {
							ptrParent->rightChild = requiredNode;
						}
						else {
							ptrParent->leftChild = requiredNode;
						}
						requiredNode->leftChild = ptr->leftChild;
						requiredNode->rightChild = ptr->rightChild;
						delete ptr;
					}
				}
			}
			else if (ptr->key < key) {
				ptrParent = ptr;
				if (ptr->rightChild != nullptr) {
					ptr = ptr->rightChild;
				}
				else {
					erased = true;
				}
			}
			else {
				ptrParent = ptr;
				if (ptr->leftChild != nullptr) {
					ptr = ptr->leftChild;
				}
				else {
					erased = true;
				}
			}
		}
	}
	void clear() {
		size = 0;
		clear(root);
		root = nullptr;
	}
	bool find(keyType key) {
		bool found = false;
		Node* ptr = root;
		while (!found) {
			if (ptr->key == key) {
				found = true;
			}
			else if (ptr->key < key) {
				if (ptr->rightChild != nullptr) {
					ptr = ptr->rightChild;
				}
				else {
					found = false;
					break;
				}
			}
			else {
				if (ptr->leftChild != nullptr) {
					ptr = ptr->leftChild;
				}
				else {
					found = false;
					break;
				}
			}
		}
		return found;
	}
	int Size() {
		return size;
	}
	bool empty() {
		bool isEmpty = false;
		if (size == 0) {
			isEmpty = true;
		}
		return isEmpty;
	}
	keyType next(keyType key) {  //return default key value, if haven't found bigger value
		keyType requiredKey = keyType();
		Node* ptr = root;
		while (ptr != nullptr) {
			if (ptr->key <= key) {
				ptr = ptr->rightChild;
			}
			else if (ptr->key > key) {
				requiredKey = ptr->key;
				ptr = ptr->leftChild;
			}
		}
		return requiredKey;
	}
	keyType previous(keyType key) {
		keyType requiredKey = keyType();
		Node* ptr = root;
		while (ptr != nullptr) {
			if (ptr->key >= key) {
				ptr = ptr->leftChild;
			}
			else if (ptr->key < key) {
				requiredKey = ptr->key;
				ptr = ptr->rightChild;
			}
		}
		return requiredKey;
	}
	keyType minimum() {
		Node* ptr = root;
		if (ptr != nullptr) {
			while (ptr->leftChild != nullptr) {
				ptr = ptr->leftChild;
			}
		}
		return ptr->key;
	}
	keyType maximum() {
		Node* ptr = root;
		if (ptr != nullptr) {
			while (ptr->rightChild != nullptr) {
				ptr = ptr->rightChild;
			}
		}
		return ptr->key;
	}
	Iterator begin() {
		Iterator it(minimum(0), this);
		return it;
	}
	Iterator end() {
		Iterator it(maximum(0), this);
		return it;
	}
	~MultiSet() {
		if (root != nullptr) {
			clear();
			delete root;
		}
	}
};