// BINARY SEARCH TREE : create, display, delete
// TRAVERSAL METHOD... not recursion
#include <iostream>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
	{
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int key)
{
    if (root == NULL)
	{
        return new TreeNode(key);
    }
	else
	{
        if (key < root->val)
		{
            root->left = insert(root->left, key);
        }
		else
		{
            root->right = insert(root->right, key);
        }
    }
    return root;
}

void inorderTraversal(TreeNode* root)
{
    if (root)
	{
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode* root)
{
    if (root)
	{
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root)
{
    if (root)
	{
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }
}

int main()
{
    TreeNode* root = NULL;
    int num;
    cout << "Enter integers to insert into the BST (enter -1 to finish):" << endl;
    while (true)
	{
        cin >> num;
        if (num == -1)
		{
            break;
        }
        root = insert(root, num);
    }

    cout << "Inorder Traversal:" << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal:" << endl;
    postorderTraversal(root);
    cout << endl;

    return 0;
}


