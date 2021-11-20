class Solution {
public:
    //If n is odd simply reduce the power to even by subtracting 1 and multiplying value of x to the answer
    //else take square of that number and reduce the power by half
    double myPow(double x, int n1) {
        double ans = 1;
        long long n = n1;
        int temp = n;
        if(n<0)
            n = -n;
        while(n > 0)
        {
            if(n & 1)
                ans *= x,n--;
            else
            {
                x *= x;
                n /= 2.0;
            }
            
        }
        if(temp < 0)
        {
            ans = (double)1/ (double)ans;
        }
        return ans;
        
    }
};
