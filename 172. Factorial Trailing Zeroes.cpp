#include<cmath>
class Solution {
public:
    int trailingZeroes(int n) {
        int k;
        for (k = 0; ; k ++)
        {
            if (pow(5, k) > n)
                break;
        }
        
        int cnt = 0;
        for (int i = 1; i < k; i ++)
            cnt += n / (pow(5, i));
        
        return cnt;
    }
};