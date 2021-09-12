void inorder(Node* root,vector<int>& v)
{
    if(!root)return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
float findMedian(struct Node *root)
{
    vector<int>v;
    inorder(root,v);
    int n=v.size();
    if(n%2==1)
    return (float)v[n/2];
    else
    {
        float q,r;
        q=(float)(v[n/2])+(float)(v[(n-1)/2]);
        r=(q)/(float)2;
        return r;
    }
      //Code here
}

