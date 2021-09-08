void count(Node* root,int l,int h,int& ct)
{
    
    if(!root)
    return ;
    if(root->data>=l and root->data<=h)
    ct++;
    count(root->left,l,h,ct);
    count(root->right,l,h,ct);
}
//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
    int ct=0;
     count(root,l,h,ct);
     return ct;
  // your code goes here   
}
