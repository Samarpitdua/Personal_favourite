struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void getleft(Node* root,vector<int>& v)
    {
        if(!root)
        return;
        while(1)
        {
            if(!root->left and !root->right)
            break;
            v.push_back(root->data);
            
            if(root->left)
            {
                root=(root->left);
            }
            else if(root->right)
            {
                root=(root->right);
            }
        }
    }
    void getright(Node* root,vector<int>& y)
    {
        if(!root)
        return;
        while(1)
        {
            if(!root->left and !root->right)
            break;
            y.push_back(root->data);
            
            if(root->right)
            root=root->right;
            else if(root->left)
            root=root->left;
        }
    }
    void inorder(Node* root,vector<int>& v)
    {
        if(!root)
        return;
        if(root->left)inorder(root->left,v);
        if(root->left==NULL and root->right==NULL)
        v.push_back(root->data);
        if(root->right)inorder(root->right,v);
    }
    vector <int> printBoundary(Node *root)
    {
        vector<int>v,y;
        if(!root)
        return v;
        v.push_back(root->data);
        getleft(root->left,v);
        inorder(root,v);
        getright(root->right,y);
        reverse(y.begin(),y.end());
        for(auto l:y)
        v.push_back(l);
        return v;
        //Your code here
    }
};
