    public:
    int maxLen(vector<int>&A, int n)
    {   
        int sum = 0, ans = 0;
        map<int,int>mp;
        mp[0]=0;
        for(int i = 0;i < n;i++)
        {
            sum+=A[i];
            if(sum == 0)
            ans=max(ans,i+1);
            if(mp[sum]!=0)
            {
                ans=max(ans,i-mp[sum]+1);
            }
            else
            mp[sum]=i+1;
         //   cout<<sum<<" ";
        }
        return ans;
        // Your code here
    }
