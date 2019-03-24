// 老的代码已经不能支持 负数 了
// 这是新版本的代码。

#include <bitset>
class Solution {
public:
    int getSum(int a, int b) {
        int res=0;
        int sign=1;
        if (a<0 && b<0) {
            sign = -1;
            a = -a;
            b = -b;
        }        
        while (b!=0) {
            res = a^b;
            b = (a&b & (~(1<<31)))<<1;
            a = res;
        }
        return res*sign;
    }
};