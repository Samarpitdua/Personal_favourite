class Solution {
public:
    int merge(vector<int>& nums,int low,int high,int mid)
    {
        int ct = 0;
        int j = mid+1;
        for(int i = low;i <= mid;i++)
        {
            
            while(j <= high and (nums[i]>(2ll*nums[j])))
                j++;
            ct += (j-(mid+1));
        }
       
        int left = low, right = mid+1;
         vector<int> temp(high-low+1);
        int k = 0;
            while(left <= mid and right <= high)
            {
                if(nums[left] < nums[right])
                    temp[k++] = nums[left++];
                else
                    temp[k++] = nums[right++];
            } 
        while(left <= mid)
            temp[k++] = nums[left++];
        while(right <= high)
            temp[k++] = nums[right++];
        for(int i = low;i <= high;i++)
            nums[i] = temp[i-low];
        return ct;
    }
    
    
    int mergeSort(vector<int>& nums,int left,int right)
    {
        int ct = 0;
        if(left < right)
        {
            int mid = (left + right)/2;
            ct += mergeSort(nums,left,mid);
            ct += mergeSort(nums,mid+1,right);
            ct += merge(nums,left,right,mid);
            
        }
        return ct;
    }
    
    int reversePairs(vector<int>& nums) 
    {
       return mergeSort(nums,0,nums.size()-1);
    }
};
