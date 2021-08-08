class Solution {
public:
    //In approach 2 , we will optimize to complexity of log n.
    // So we will use Binary Search
    //We will find the break point
    //at left of break point all elements appears twice and on the right we start fro an element which appared only once.
    //We can observe that on right side (for the elements that are appearing twice) their 
    //first instance is on odd index and second instance is on even index, that's opposite for left part
    //We will calculate mid and check if elemen t belongs to left half or right half
    //if left half, low=mid+1 else high=mid-1
    //After it low will be pointing at single element and high at low-1
    //keep high at second last index ...ye ratlo...ye tab kaam ayega..jab single element last me ayega
    
    int singleNonDuplicate(vector<int>& a) {
        int low=0,high=a.size()-2;
        while(low<=high)
        {
            int mid=(high+low)/2;
            int temp=a[mid];
            if(mid%2!=0)
            {
                if(a[mid]==a[mid+1])
                    high=mid-1;
                else 
                    low=mid+1;
            }
            else
            {
                if(a[mid]==a[mid+1])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return a[low];
    }
};
