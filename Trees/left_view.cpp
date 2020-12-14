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
void leftViewImp(node *root, int level, int *max_level)
{
    if(root==NULL)
    return;
    if(*max_level<level)
    {
        cout << root->data<<" ";
        *max_level = level;

    }
    leftViewImp(root->left, level + 1, max_level);
    leftViewImp(root->right, level + 1, max_level);
} 
void leftView(node *root)
{
    int max_level = 0;
    leftViewImp(root, 1, &max_level);
}
int main()
{
    node *k = 0;
    k = create();
    leftView(k);
    
    return 0;
}