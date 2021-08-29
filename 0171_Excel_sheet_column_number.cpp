class Solution {
public:
    int titleToNumber(string s) {
        long long ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int y=s[i]-'A'+1;
            ans*=26;
            ans+=y;
        }
        return ans;
    }
};
