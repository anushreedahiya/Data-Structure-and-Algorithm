// BINARY TREE : create, display by pre post and in order
//RECURSION
// traverse inorder, preorder and postorder
// general binary tree not binary search tree
#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
    friend class BinaryTree;
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == NULL)
		{
            return new TreeNode(value);
        }

        char ans;
        cout << "Where do you want to add the element, left or right (l/r) of " << node->data << "? ";
        cin >> ans;

        if (ans == 'l')
		{
            node->left = insert(node->left, value);
        }
		else
		{
            node->right = insert(node->right, value);
        }
        return node;
    }

    void inorder(TreeNode* node)
	{
        if (node != NULL)
		{
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(TreeNode* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void traverse(int type) {
        switch (type) {
            case 1:
                cout << "Preorder Traversal:" << endl;
                preorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Inorder Traversal:" << endl;
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal:" << endl;
                postorder(root);
                cout << endl;
                break;
            default:
                cout << "Invalid traversal type" << endl;
                break;
        }
    }
};

int main()
{
    BinaryTree tree;
    int numNodes, inputValue;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    if (numNodes <= 0) {
        cout << "Invalid number of nodes. Exiting." << endl;
        return 0;
    }

    cout << "Enter values for each node:" << endl;

    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << (i + 1) << ": ";
        cin >> inputValue;
        tree.insert(inputValue);
    }

    cout << "Choose a traversal type:" << endl;
    cout << "1. Preorder" << endl;
    cout << "2. Inorder" << endl;
    cout << "3. Postorder" << endl;

    int traversalType;
    cin >> traversalType;

    tree.traverse(traversalType);

    return 0;
}

