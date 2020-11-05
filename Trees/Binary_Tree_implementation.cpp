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