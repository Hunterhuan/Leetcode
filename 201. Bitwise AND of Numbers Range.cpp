// 终于自己做出来一道题了。感动。
// 因为是中间所有的数的and
// 所以从高位向低位，只要相同，就保留，不相同就说明存在0 and 1，那这位就一定是0
// 后面的也都是0.
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for(int i=31;i>=0;--i){
            if((m>>i&1)==(n>>i&1))
                res = (res | (m>>i<<i));
            else
                break;
        }
        return res;
    }
};