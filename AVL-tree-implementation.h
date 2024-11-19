#include <iostream>
#include <queue>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	int height;

	Node() : data(0), left(nullptr), right(nullptr), height(0) {}
	Node(int data) : data(data), left(nullptr), right(nullptr), height(0) {}
};

class AVL
{
private:
	Node* root;
public:
	//Q1
	AVL()
	{
		root = nullptr;
	}

	Node* getRoot()
	{
		return root;
	}

	Node* insert(Node* node, int val)
	{
		if (!node)
			return new Node(val);

		// Regular BST insertion
		if (val < node->data)
			node->left = insert(node->left, val);
		else if (val > node->data)
			node->right = insert(node->right, val);
		else
			return node;  // Duplicate value


		// Update height of ancestor node
		node->height = 1 + max(height(node->left), height(node->right));

		int balance = getBalance(node);

		// Left Left (LL) Case
		if (balance > 1 && val < node->left->data)
			return rightRotate(node);

		// Right Right (RR) Case
		if (balance < -1 && val > node->right->data)
			return leftRotate(node);

		// Left Right (LR) Case
		if (balance > 1 && val > node->left->data)
		{
			leftRightRotate(node);
		}

		// Right Left (RL) Case
		if (balance < -1 && val < node->right->data)
		{
			rightLeftRotate(node);
		}

		return node;
	}


	void insert(int val)
	{
		root = insert(root, val);
	}

	int height(Node* node)
	{
		if (node == nullptr)
			return -1;
		return node->height;
	}

	int getBalance(Node* node)
	{
		if (!node) return 0;
		return height(node->left) - height(node->right);
	}

	Node* rightRotate(Node* y)
	{
		Node* left_child = y->left;
		Node* T2 = left_child->right;

		// Perform rotation
		left_child->right = y;
		y->left = T2;

		// Update heights
		y->height = 1 + max(height(y->left), height(y->right));
		left_child->height = 1 + max(height(left_child->left), height(left_child->right));

		// Return new root
		return left_child;
	}

	Node* leftRotate(Node* x)
	{
		Node* right_child = x->right;
		Node* T2 = right_child->left;

		// Perform rotation
		right_child->left = x;
		x->right = T2;

		// Update heights
		x->height = 1 + max(height(x->left), height(x->right));
		right_child->height = 1 + max(height(right_child->left), height(right_child->right));

		// Return new root
		return right_child;
	}

	Node* leftRightRotate(Node* node)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	Node* rightLeftRotate(Node* node)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	bool search(int Data)
	{
		if (root->data == Data)
		{
			cout << root->data;
			return 1;
		}

		Node* temp = root;

		while (temp)
		{
			if (Data == temp->data)
			{
				cout << temp->data;
				return 1;
			}
			if (Data > temp->data)
			{
				temp = temp->right;
			}
			else if (Data < temp->data)
			{
				temp = temp->left;
			}
		}
		return 0;
	}

	Node* getSuccessor(Node* curr)
	{
		curr = curr->right;
		while (curr != NULL && curr->left != NULL)
			curr = curr->left;
		return curr;
	}

	Node* deleteNode(Node* root, int removeItem)
	{
		if (root == NULL)
			return root;

		if (root->data > removeItem)
		{
			root->left = deleteNode(root->left, removeItem);
		}
		else if (root->data < removeItem)
		{
			root->right = deleteNode(root->right, removeItem);
		}
		else // Node found with the value to delete
		{
			if (root->left == NULL) // Node with only right child or no child
			{
				Node* temp = root;
				temp = temp->right;
				delete root;
				return temp;
			}
			if (root->right == NULL) // Node with only left child
			{
				Node* temp = root;
				temp = temp->left;
				delete root;
				return temp;
			}
			else {
				// Node with two children: Get the inorder successor
				Node* succ = getSuccessor(root);
				root->data = succ->data;
				root->right = deleteNode(root->right, succ->data); // Delete successor
			}

		}

		// Update height of the current node
		//root->height = 1 + max(height(root->left), height(root->right));

		//// Get balance factor to check if the node became unbalanced
		//int balance = getBalance(root);

		//// Perform rotations based on balance factor

		//// Left Left Case
		//if (balance > 1 && getBalance(root->left) >= 0)
		//	return rightRotate(root);

		//// Right Right Case
		//if (balance < -1 && getBalance(root->right) <= 0)
		//	return leftRotate(root);

		//// Left Right Case
		//if (balance > 1 && getBalance(root->left) < 0)
		//{
		//	root->left = leftRotate(root->left);
		//	return rightRotate(root);
		//}

		//// Right Left Case
		//if (balance < -1 && getBalance(root->right) > 0)
		//{
		//	root->right = rightRotate(root->right);
		//	return leftRotate(root);
		//}

		return root;
	}


	void remove(int removeItem)
	{
		deleteNode(root, removeItem);
	}

	void LT(Node* root)
	{
		if (root == nullptr) return;

		queue<Node*> q1;
		q1.push(root);

		while (!q1.empty())
		{
			int levelSize = q1.size();

			for (int i = 0; i < levelSize; ++i)
			{
				Node* temp = q1.front();
				q1.pop();
				cout << temp->data << " ";

				if (temp->left) q1.push(temp->left);
				if (temp->right) q1.push(temp->right);
			}

			cout << endl;
		}
	}

	void levelorderTraversal()
	{
		LT(root);
		cout << '\n';
	}

	void IT(Node* root)
	{
		if (!root)
		{
			return;
		}
		IT(root->left);
		cout << root->data << ' ';
		IT(root->right);
	}

	void inorderTraversal()
	{
		IT(root);
		cout << '\n';
	}

	void PreT(Node* root)
	{
		if (!root)
		{
			return;
		}
		cout << root->data << ' ';
		PreT(root->left);
		PreT(root->right);
	}

	void preorderTraversal()
	{
		PreT(root);
		cout << '\n';
	}

	void PostT(Node* root)
	{
		if (!root)
		{
			return;
		}
		PostT(root->left);
		PostT(root->right);
		cout << root->data << ' ';
	}

	void postorderTraversal()
	{
		PostT(root);
		cout << '\n';
	}

	int findLargest()
	{
		Node* temp = root;

		while (temp->right)
		{
			temp = temp->right;
		}

		return temp->data;
	}

	int findSmallest()
	{
		Node* temp = root;

		while (temp->left)
		{
			temp = temp->left;
		}

		return temp->data;
	}

	void splitAVL(Node* node, int k, AVL& TreeA, AVL& TreeB) {
		if (node == nullptr) return;
		if (node->data <= k)
		{
			TreeA.insert(node->data);
			splitAVL(node->left, k, TreeA, TreeB);
			splitAVL(node->right, k, TreeA, TreeB);
		}
		else
		{
			TreeB.insert(node->data);
			splitAVL(node->left, k, TreeA, TreeB);
			splitAVL(node->right, k, TreeA, TreeB);
		}
	}

};