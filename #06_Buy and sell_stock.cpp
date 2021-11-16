class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,maxi=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]-maxi>ans)
                ans=prices[i]-maxi;
            if(prices[i]<maxi)
                maxi=prices[i];
        }
        return ans;
        
    }
};
