// 我用前缀和。最后发现爆表了。之后发现length的范围是30000,
// N方的复杂度接受不了。只能用余数记录
// 如果余数相等，就说明两个的差能整除K
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int len = A.size();
        vector<int> sum(len+1);
        sum[0] = 0;
        for(int i=1;i<len+1;++i)
            sum[i] = sum[i-1] + A[i-1];
        int res = 0;
        vector<int> count(K,0);
        for(auto x:sum)
            count[(x%K+K)%K]++;
        for(auto v:count)
            res += v*(v-1)/2;
        return res;
    }
};