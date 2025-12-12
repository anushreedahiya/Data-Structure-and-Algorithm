#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int n) : data(n), left(NULL), right(NULL) {}
    friend class BinaryTree;
};

class BinaryTree {
private:
    TreeNode* root;

    void preorder(TreeNode* currentnode);
    void inorder(TreeNode* currentnode);
    void postorder(TreeNode* currentnode);

public:
    BinaryTree() {
        root = NULL;
    }

    void create();
    void preorder();
    void inorder();
    void postorder();
    void insert(int n);
    void copy(BinaryTree &t);
    TreeNode* copy(TreeNode* root1);
    void mirror(BinaryTree &t);
    TreeNode* mirror(TreeNode* root1);
    int totalnodes();
    int leafnodes();
};

void BinaryTree::preorder() {
    preorder(root);
    cout << endl;
}

void BinaryTree::preorder(TreeNode* currentnode) {
    if (currentnode != NULL) {
        cout << currentnode->data << " "; /* D */
        preorder(currentnode->left); /* L */
        preorder(currentnode->right); /* R */
    }
}

void BinaryTree::inorder() {
    inorder(root);
    cout << endl;
}

void BinaryTree::inorder(TreeNode* currentnode) {
    if (currentnode != NULL) {
        inorder(currentnode->left); /* L */
        cout << currentnode->data << " "; /* D */
        inorder(currentnode->right); /* R */
    }
}

void BinaryTree::postorder() {
    postorder(root);
    cout << endl;
}

void BinaryTree::postorder(TreeNode* currentnode) {
    if (currentnode != NULL) {
        postorder(currentnode->left); /* L */
        postorder(currentnode->right); /* R */
        cout << currentnode->data << " "; /* D */
    }
}

void BinaryTree::create() {
    char choice;
    do {
        int n;
        cout << "Enter the element to be attached: ";
        cin >> n;
        insert(n);
        cout << "Any more nodes (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void BinaryTree::insert(int n) 
{
    if (root == NULL) 
	{
        root = new TreeNode(n);
    } 
	else 
	{
        TreeNode* temp = root;
        char ans;
        while (true) {
            cout << "Left or right (l/r) of " << temp->data << "? ";
            cin >> ans;
            if (ans == 'l')
			{
                if (temp->left == NULL)
				{
                    temp->left = new TreeNode(n);
                    break;
                }
				else
				{
                    temp = temp->left;
                }
            }
			else
			{
                if (temp->right == NULL) 
				{
                    temp->right = new TreeNode(n);
                    break;
                } 
				else
				{
                    temp = temp->right;
                }
            }
        }
    }
}

void BinaryTree::copy(BinaryTree &t) {
    t.root = copy(root);
}

TreeNode* BinaryTree::copy(TreeNode* root1) {
    if (root1 == NULL) {
        return NULL;
    }
    TreeNode* newRoot = new TreeNode(root1->data);
    newRoot->left = copy(root1->left);
    newRoot->right = copy(root1->right);
    return newRoot;
}

void BinaryTree::mirror(BinaryTree &t) {
    t.root = mirror(root);
}

TreeNode* BinaryTree::mirror(TreeNode* root1) {
    if (root1 == NULL) {
        return NULL;
    }
    TreeNode* newRoot = new TreeNode(root1->data);
    newRoot->left = mirror(root1->right);
    newRoot->right = mirror(root1->left);
    return newRoot;
}

int BinaryTree::totalnodes()
{
    return countnodes(root);
}

int BinaryTree::countnodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countnodes(root->left) + countnodes(root->right);
}

int BinaryTree::leafnodes() {
    return countleafnodes(root);
}

int BinaryTree::countleafnodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countleafnodes(root->left) + countleafnodes(root->right);
}

int main() {
    BinaryTree tree;
    tree.create();
    
    cout << "Original tree - Preorder: ";
    tree.preorder();

    BinaryTree copiedTree;
    tree.copy(copiedTree);
    cout << "Copied tree - Preorder: ";
    copiedTree.preorder();

    BinaryTree mirroredTree;
    tree.mirror(mirroredTree);
    cout << "Mirrored tree - Preorder: ";
    mirroredTree.preorder();

    cout << "Total nodes in the original tree: " << tree.totalnodes() << endl;
    cout << "Total leaf nodes in the original tree: " << tree.leafnodes() << endl;

    return 0;
}



