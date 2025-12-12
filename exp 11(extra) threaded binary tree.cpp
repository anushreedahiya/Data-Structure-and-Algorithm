// Assignment: threaded binary tree
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool isThreaded;

    Node(int value) : data(value), left(NULL), right(NULL), isThreaded(false) {}
};

class ThreadedBinaryTree
{
private:
    Node* root;

Node* insertHelper(Node* node, int value)
{
    if (!node)
	{
        return new Node(value);
    }
    if (value < node->data)
	{
        node->left = insertHelper(node->left, value);
    }
	else if (value > node->data)
	{
        if (!node->right)
		{
            Node* temp = insertHelper(NULL, value);
            temp->right = node->right;
            temp->isThreaded = true;
            node->right = temp;
        }
		else
		{  
            node->right = insertHelper(node->right, value);
        }
    }
    return node;
}

void inOrderTraversal(Node* node)
{
    if (!node) return;
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

public:
    ThreadedBinaryTree() : root(NULL) {}
    void insert(int value)
	{
        root = insertHelper(root, value);
    }
    void display()
	{
        cout << "Threaded Binary Tree: ";
        inOrderTraversal(root);
        cout << endl;
    }
};

int main()
{
    ThreadedBinaryTree threadedTree;
    int numValues;
    cout << "Enter the number of values: ";
    cin >> numValues;
    for (int i = 0; i < numValues; ++i)
	{
        int value;
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        threadedTree.insert(value);
    }
    threadedTree.display();
    return 0;
}


