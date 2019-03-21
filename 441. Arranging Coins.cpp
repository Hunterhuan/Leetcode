class Solution {
public:
    int arrangeCoins(int n) {
        int cnt = 0;
        while(n >= 0){
            ++cnt;
            n = n - cnt;
        }
        return cnt - 1;
    }
};

// 或者直接计算？
#include <math>
class Solution {
public:
    int arrangeCoins(int n) {
        int res = int(sqrt(n*2));
        for(int i=res; i>=0; --i){
            if(i*(1+i)/2 <= n)
                return i;
        }
        return res;
    }
};