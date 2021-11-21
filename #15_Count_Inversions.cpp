class Solution{ 
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long int arr[],long long int left,long long int right,long long int mid,long long N)
{
    long long inv_count=0;
    long long int i=left,j=mid+1,k=left;
    long long temp2[N];
    while(i<=mid and j<=right)
    {
        if(arr[i]<=arr[j])
        temp2[k++]=arr[i++];
        else
        {
            temp2[k++]=arr[j++];
            inv_count+=(mid-i+1);
        }
    }
    while(i<=mid)
    temp2[k++]=arr[i++];
    while(j<=right)
    {
        temp2[k++]=arr[j++];
    }
    for(int i=left;i<=right;i++)
    arr[i]=temp2[i];
    return inv_count;
}
long long mergeSort(long long arr[],long long left,long long right,long long N)
{
    long long inv_count=0;
    if(right>left)
    {
        long long mid = (left+right)/2;
        inv_count+= mergeSort(arr,left,mid,N);
        inv_count+=mergeSort(arr,mid+1,right,N);
        inv_count+=merge(arr,left,right,mid,N);
    }
    return inv_count;
}
long long int inversionCount(long long arr[], long long N)
{
    long long left=0 ,right=N-1;
    long long ans=mergeSort(arr,left,right,N);
    return ans;
    // Your Code Here
}

};
