#pragma once
#include <iostream>
#include <queue>
using namespace std;


struct Node
{
	Node** children; // Pointer to an array of Node pointers
	int* arr;
	int numKeys;
	int color;

	Node(int order)
	{
		numKeys = 0;
		arr = new int[order];
		children = new Node * [order];
		for (int i = 0; i < order; i++)
		{
			children[i] = nullptr;
		}
	}

};

class BTree
{
private:
	Node* root;
	int order;

public:
	BTree(int order)
	{
		this->order = order;
		root = nullptr;
	}

	Node* getRoot()
	{
		return root;
	}

	void splitChild(Node* parent, int childIndex, int order)
	{
		Node* fullChild = parent->children[childIndex];
		int midIndex = ceil((order - 1) / 2);

		// Create new nodes for the split
		Node* leftChild = new Node(order);
		Node* rightChild = new Node(order);

		// Copy left and right halves of keys from fullChild to the new nodes
		for (int i = 0; i < midIndex; i++)
		{
			leftChild->arr[i] = fullChild->arr[i];
		}
		for (int i = midIndex + 1; i < order - 1; i++)
		{
			rightChild->arr[i - midIndex - 1] = fullChild->arr[i];
		}

		if (fullChild->children[0] != nullptr)
		{
			for (int i = 0; i <= midIndex; i++)
			{
				leftChild->children[i] = fullChild->children[i];
			}
			for (int i = midIndex + 1; i < order; i++)
			{
				rightChild->children[i - midIndex - 1] = fullChild->children[i];
			}
		}

		// Insert middle key into the parent node
		for (int i = parent->numKeys; i > childIndex; i--)
		{
			parent->arr[i] = parent->arr[i - 1];
			parent->children[i + 1] = parent->children[i];
		}
		parent->arr[childIndex] = fullChild->arr[midIndex];
		parent->children[childIndex] = leftChild;
		parent->children[childIndex + 1] = rightChild;
		parent->numKeys++;

		delete fullChild;
	}


	void insertHelper(Node* current, int key, int order)
	{
		if (!current)
		{
			return;
		}

		bool isLeaf = true;
		for (int i = 0; i < order; i++) \
		{
			if (current->children[i] != nullptr)
			{
				isLeaf = false;
				break;
			}
		}

		if (isLeaf)
		{
			int i = current->numKeys - 1;
			while (i >= 0 && current->arr[i] > key)  // Inserting element at correct position
			{
				current->arr[i + 1] = current->arr[i];
				i--;
			}
			current->arr[i + 1] = key;
			current->numKeys++;
			return;
		}

		int i = 0;
		while (i < current->numKeys && key > current->arr[i])  // Which child to go to next
		{
			i++;
		}

		if (i < order && current->children[i])
		{
			insertHelper(current->children[i], key, order);

			if (current->children[i] && current->children[i]->numKeys == order)  // Max keys reached
			{
				splitChild(current, i, order); // Split the full child
			}
		}
	}



	void insert(int val)
	{
		// If empty Tree
		if (!root)
		{
			root = new Node(order);
			root->arr[0] = val;  // Inserting at 0th index as it is the first value
			root->numKeys = 1;
			return;
		}

		// If current array has less than order - 1 keys  // Then simply insert
		insertHelper(root, val, order);
	}

	void printTree(Node* root, int order)
	{
		if (!root)
		{
			cout << "Tree is empty" << endl;
			return;
		}

		queue<Node*> q;  // Level order traversal
		q.push(root);

		while (!q.empty())
		{
			int levelSize = q.size();

			// Process all nodes at the current level
			while (levelSize--)
			{
				Node* current = q.front();
				q.pop();

				// Print the keys in the current node
				cout << "[";
				for (int i = 0; i < current->numKeys; i++)
				{
					cout << current->arr[i];
					if (i < current->numKeys - 1)
						cout << ", ";
				}
				cout << "] ";

				// Enqueue all non-null children
				for (int i = 0; i < order; i++)
				{
					if (current->children[i])
					{
						q.push(current->children[i]);
					}
				}
			}

			// Newline after each level
			cout << std::endl;
		}
	}
};

int main()
{
	int order;
	cout << "Enter the order of the tree: ";
	cin >> order;
	BTree B1(order);

	B1.insert(1);
	B1.insert(2);
	B1.insert(3);

	B1.insert(4);

	B1.insert(5);	

	B1.printTree(B1.getRoot(), order);
	return 0;
}