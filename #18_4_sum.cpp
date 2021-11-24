class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //Approach :2
        //3 pointer + binary search
        long long size = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        vector<vector<int>>ans2;
        for(long long int i = 0;i < size;i++)
        {
            for(long long int j= i+1; j<size;j++)
            {
                long long int sum = nums[i]+nums[j];
                long long int k = j+1;
                long long int l = size-1;
                while(k<l)
                {
                    if(sum+nums[k]+nums[l]<target)
                        k++;
                    else if(sum+nums[k]+nums[l]>target)
                        l--;
                    else
                    {
                        vector<int>v(4);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[k];
                        v[3]=nums[l];
                        ans.insert(v);
                        while(k<l and v[2] == nums[k])
                            k++;
                        while(k<l and v[3] == nums[l])
                            l--;
                    }
                    
                }
                while(j<(size-1) and nums[j] == nums[j+1])
                j++;

            }
        }
        for(auto x:ans)
            ans2.push_back(x);
        return ans2;
    }
};
