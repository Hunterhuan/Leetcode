// 做了这么多次还出错。
// 但bug很傻逼
// INT_MIN 改成INT_MAX 会溢出

class Solution {
public:
    double myPow(double x, int n) {
        long m = n;
        if (n < 0)
            return 1.0 / power(x,-m);
        else
            return power(x, m);
    }
    
private:
    double power(double x, long n)
    {
        if (n == 0)
            return 1;
        double ans = power(x, n / 2);
        if(n % 2 == 0)//n为偶数
            return ans * ans;
        else//n为奇数
            return ans * ans * x;
    }
};