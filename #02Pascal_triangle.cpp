class Solution {
public:
    //As we proceed at each row we get equal number of elements
    //If you want to find a value at a particualar row and column , the formula is-> r-1^C^c-1
    //---->O(n)complexity
    //Let's suppose you want to find any full row then observe the pattern
    //res*=(n-i),res/=(i+1);
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int n=1;
        vector<int>v(n);
        v[0]=1;
        ans.push_back(v);
        numRows--;
        while(numRows--)
        {
            n++;
            vector<int>v2(n);
            v2[0]=1;
            for(int i=0;i<v.size()-1;i++)
            {
                v2[i+1]=v[i]+v[i+1];
            }
            v2[n-1]=1;
            
            ans.push_back(v2);
            v.resize(n);
            v=v2;
        }
        return ans;
    }
};
