class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct=1;
        int temp=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==temp)
                ct++;
            else
                ct--;
            if(ct==0)
                ct=1,temp=nums[i];
            //cout<<temp<<" "<<ct<<"\n";
        }
        return temp;
    }
    
};
