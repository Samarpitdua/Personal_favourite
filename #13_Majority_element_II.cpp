class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> v;
        int x =INT_MIN, y = INT_MIN , ct = 0, ct2 = 0, n = nums.size();
        for(int i=0;i<n;i++)
        {
            
            if(nums[i]==x)
                ct++;
            else if(nums[i]==y)
                ct2++;
            else if(ct==0)
            {
                x=nums[i];
                ct++;
            }
            else if(ct2==0)
            {
                y=nums[i];
                ct2++;
            }
            
            else
            {
                ct--,ct2--;
            }
           // cout<<x<<":"<<ct<<" "<<y<<":"<<ct2<<"\n";
            
        }
        //cout<<x<<" "<<y<<endl;
        ct=0,ct2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==x)ct++;
            if(nums[i]==y)ct2++;
            
        }
        if(ct>(n/3))
            v.push_back(x);
        if(ct2>(n/3))
            v.push_back(y);
        return v;
    }
};
