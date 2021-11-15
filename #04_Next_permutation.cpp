class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Approach :1 This is the one-liner solution but interviewer will not like it :)
        
     //   next_permutation(nums.begin(),nums.end());
      
      //Approach 2:
        //the main solution will consist of 4 steps :
        //Start loop from end and find first element that is smaller than the element               to it's right
        //Now from this element start iterating towards end and stop when you get the           element just greater than it
        //swap both indexes
        //reverse i+1 to end
        int n=nums.size();
        int ans=-1,ans2=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                ans=i-1;
                break;
            }
        }
        if(ans==-1)
        {
            reverse(nums.begin(),nums.end());
         //   cout<<"a "<<nums[0]<<endl;
            return;
        }
        for(int i=n-1;i>ans;i--)
        {
            if(nums[i]>nums[ans])
            {
                ans2=i;
                break;
            }
        }
        swap(nums[ans],nums[ans2]);
        reverse(nums.begin()+ans+1,nums.end());
    }
};
