//geeksforgeeks
//first convert into vector taking all the values and then do the simple inorder
class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node *root,vector<int>&v)
    {
        if(!root)return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    void convert(Node *root,vector<int>& v,int& i)
    {
        if(!root)return;
        convert(root->left,v,i);
        root->data=v[i];
        i++;
        convert(root->right,v,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end());
        int i=0;
        convert(root,v,i);
        return root;
        //Your code goes here
    }
};
