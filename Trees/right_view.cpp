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