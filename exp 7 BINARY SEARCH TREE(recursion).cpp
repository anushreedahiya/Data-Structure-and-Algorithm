// BINARY SEARCH TREE : create, display, delete, search
// RECURSIVE METHOD
#include <iostream>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }
	else {
        if (key < root->val) {
            root->left = insert(root->left, key);
        }
		else {
            root->right = insert(root->right, key);
        }
    }
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root)
	{
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode* root) {
    if (root)
	{
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
	else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
	else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
		else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

TreeNode* search(TreeNode* root, int key) {
    if (root == NULL || root->val == key) {
        return root;
    }
    if (root->val < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

int main() {
    TreeNode* root = NULL;
    int num;

    cout << "Enter integers to insert into the BST (enter -1 to finish):" << endl;
    while (true) {
        cin >> num;
        if (num == -1) {
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

    int choice;
    while (true) {
        cout << "Choose an operation:" << endl;
        cout << "1. Delete a value" << endl;
        cout << "2. Search for a value" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        if (choice == 3) {
            break;
        }
        switch (choice) {
            case 1:
			{
                cout << "Enter a value to delete from the BST: ";
                cin >> num;
                root = deleteNode(root, num);
                cout << "Inorder Traversal after deleting " << num << ":" << endl;
                inorderTraversal(root);
                cout << endl;
                break;
            }
            case 2:
            {	
                cout << "Enter a value to search for in the BST: ";
                cin >> num;
                TreeNode* result = search(root, num);
                if (result != NULL) {
                    cout << num << " found in the BST." << endl;
                }
				else {
                    cout << num << " not found in the BST." << endl;
                }
                break;
			}
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}



