#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};
node *create()
{
    int x;
    node *newnode;
    newnode = new node;
    cout << "\nEnter the data for node";
    cin >> x;
    if (x == -1)
        return 0;
    newnode->data = x;
    cout << "\nEnter left child of node of " << x;

    newnode->left = create();
    cout << "\nEnter right child of node of " << x;

    newnode->right = create();
    return newnode;
}
void preorder(node *root)
{
    if (root == 0)
        return;
    else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
node* deleteNode(node* root, int k)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->key > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else {
 
        Node* succParent = root;
 
        // Find successor
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->key = succ->key;
 
        // Delete Successor and return root
        delete succ;
        return root;
    }
}
 
void inorder(node *root)
{
    if (root == 0)
        return;
    else
    {

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void postorder(node *root)
{
    if (root == 0)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    node *k = 0;
    k = create();
    preorder(k);
    return 0;
}