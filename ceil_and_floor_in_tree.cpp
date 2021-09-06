class Solution
{
    public:
    void findfloor(Node* root,int k,int& ans)
    {
        
        if(!root)
        return;
        while(1)
        {
            if(!root)
            break;
            if(root->data==k)
            {
                ans=k;
                break;
            }
            else if(root->data>k)
            {
                
                root=root->left;
            }
            else
            {
                ans=root->data;
                root=root->right;
            }
        }
    }
    void findceil(Node* root,int k,int& ans)
    {
        
        if(!root)
        return;
        while(1)
        {
            if(!root)
            break;
            if(root->data==k)
            {
                ans=k;
                break;
            }
            else if(root->data>k)
            {
                ans=root->data;
                root=root->left;
            }
            else
            {
                root=root->right;
            }
        }
    }
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int k)
    {
        int ans=INT_MAX,ans2=INT_MAX;
        findceil(root,k,ans2);
        ans2=abs(k-ans2);
        ans=min(ans,ans2);
        
        ans2=INT_MAX;
        findfloor(root,k,ans2);
        ans2=abs(k-ans2);
        ans=min(ans,ans2);
        
        return ans;
        //Your code here
    }
};
