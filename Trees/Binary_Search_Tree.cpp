// #include <bits/stdc++.h>
// using namespace std;
// class tree
// {
//     public:
//     int data;
//     tree *left, *right;
//     tree();
//    tree(int);
//     tree *insert(tree *, int);
//     void inorder(tree *);
// };
//  tree::tree(int value)
// {
//     data = value;
//     left = right = NULL;
// }

// tree * tree::insert(tree *root, int value)
// {
//     if (!root)
//         return new tree(value);

//     if (value > root->data)
//         root->right = insert(root->right, value);
//     else
//     {
//         root->left = insert(root->left, value);
//     }
//     return root;
// }
//  void tree::inorder(tree *root)
// {
//     cout<<"\n";
//     if (root == 0)
//         return;
//     else
//     {

//         inorder(root->left);
//         cout << root->data << " ";
//         inorder(root->right);
//     }
// }
// // void deletion()
// // {
// // }
// int main()
// {

//     tree t;
//     tree * root=NULL;
//     root=t.insert(root,1);
//     root=t.insert(root,20);
//     t.inorder(root);
//     root=t.insert(root,2);
//     root=t.insert(root,6);
//     root=t.insert(root,7);
//     t.inorder(root);
//     root=t.insert(root,3);
//     root=t.insert(root,5);
//     t.inorder(root);
//     root=t.insert(root,9);
//     t.inorder(root);
//  //  cout << "Enter nodes to insert ";
// }
#include <stdio.h>
#include <stdlib.h>
struct tree
{
    struct tree *lchild;
    char data[10];
    struct tree *rchild;
};
typedef struct tree node;
int ctr;
node *tree[100];
node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("\n Enter Data: ");
    scanf("%s", temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}
void create_fbinarytree()
{
    int j, i = 0;
    printf("\n How many nodes you want: ");
    scanf("%d", &ctr);
    tree[0] = getnode();
    j = ctr;
    j--;
    do
    {
        if (j > 0) /* left child */
        {
            tree[i * 2 + 1] = getnode();
            tree[i]->lchild = tree[i * 2 + 1];
            j--;
        }
        if (j > 0) /* right child */
        {
            tree[i * 2 + 2] = getnode();
            j--;
            tree[i]->rchild = tree[i * 2 + 2];
        }
        i++;
    } while (j > 0);
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%3s", root->data);
        inorder(root->rchild);
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%3s", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%3s", root->data);
    }
}
void levelorder()
{
    int j;
    for (j = 0; j < ctr; j++)
    {
        if (tree[j] != NULL)
            printf("%3s", tree[j]->data);
    }
}
void print_leaf(node *root)
{
    if (root != NULL)
    {
        if (root->lchild == NULL && root->rchild == NULL)
            printf("%3s ", root->data);
        print_leaf(root->lchild);
        print_leaf(root->rchild);
    }
}
// void height(node *root)
// {
// if(root == NULL)
//  {
//  return 0;
//  }
// //Lecture Notes 15 1 Dept. of Information Technology
// if(root->lchild == NULL && root->rchild == NULL)
//  return 0;
//  else
// {
//   int ans;
//   height(root->lchild) > height(root->rchild) ? cout<< height(root->lchild) : cout<< (height(root->rchild));

//   return (ans+1);}
// }
void main()
{
    int i;
    create_fbinarytree();
    printf("\n Inorder Traversal: ");
    inorder(tree[0]);
    printf("\n Preorder Traversal: ");
    preorder(tree[0]);
    printf("\n Postorder Traversal: ");
    postorder(tree[0]);
    printf("\n Level Order Traversal: ");
    levelorder();
    printf("\n Leaf Nodes: ");
    print_leaf(tree[0]);
    //printf("\n Height of Tree: %d ", height(tree[0]));
    //height(tree[0]);
}