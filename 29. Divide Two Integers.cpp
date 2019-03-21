// 很垃圾的题，不建议再做
class Solution {
public:
    int divide(int u, int d) {
        if(u == INT_MIN && d == -1) return INT_MAX;   
        int k = (u < 0 == d < 0) ? 1 : -1;
        if(u >= 0) u = -u;  //make everything negative to avoid -INT_MIN overflow
        if(d > 0) d = -d;
        return k > 0 ? -helper(u, d) : helper(u, d); 
    }
    
    int helper(int u, int d)
    {
        if(u > d) return 0;
        if(u - d > d) return -1; 
        int res = -1, t = d; 
        while(u - t <= t)
        {
            res += res;  
            t += t;
        }
        return res + helper(u - t, d);  
    }
};