Node* cons(int post[],int sz,int l,int r,int& ptr)
{
    
    if(l>r or ptr<0)
    return NULL;
    if(l>post[ptr] or r<post[ptr])
    return NULL;
    Node* root=new Node(post[ptr]);
    int x=post[ptr];
    ptr--;
    root->right=cons(post,sz,x+1,r,ptr);
    root->left=cons(post,sz,l,x-1,ptr);
    return root;
}
Node *constructTree (int post[], int size)
{
    int ptr=size-1;
    return cons(post,size,INT_MIN,INT_MAX,ptr);
//code here
}
