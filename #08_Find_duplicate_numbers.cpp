class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int a=nums[i];
            if(nums[i]<0)
                a=-nums[i];
            if(nums[a-1]<0)
                return a;
            nums[a-1]*=-1;
        }
        return 0;
    }
};
