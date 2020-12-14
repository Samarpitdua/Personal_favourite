#include <bits/stdc++.h>
using namespace std;
class tree
{
    public:
    int data;
    tree *left, *right;
    tree();
   tree(int);
    tree *insert(tree *, int);
    void inorder(tree *);
};
 tree::tree(int value)
{
    data = value;
    left = right = NULL;
}

tree * tree::insert(tree *root, int value)
{
    if (!root)
        return new tree(value);

    if (value > root->data)
        root->right = insert(root->right, value);
    else
    {
        root->left = insert(root->left, value);
    }
    return root;
}
 void tree::inorder(tree *root)
{
    cout<<"\n";
    if (root == 0)
        return;
    else
    {

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
// void deletion()
// {
// }
int main()
{

    tree t;
    tree * root=NULL;
    root=t.insert(root,1);
    root=t.insert(root,20);
    t.inorder(root);
    root=t.insert(root,2);
    root=t.insert(root,6);
    root=t.insert(root,7);
    t.inorder(root);
    root=t.insert(root,3);
    root=t.insert(root,5);
    t.inorder(root);
    root=t.insert(root,9);
    t.inorder(root);
 //  cout << "Enter nodes to insert ";
}