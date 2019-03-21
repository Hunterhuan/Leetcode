// dp 存下来，跟自己的思路完全一样
class Solution {
public:
    int numTrees(int n) {
        vector<int> cache(n+1,0);
        cache[0] = 1;
        cache[1] = 1;
        for(int i=2;i<=n;++i){
            for(int j=0;j<=i-1;++j){
                cache[i] += cache[j]*cache[i-1-j];
            }
        }
        return cache[n];
    }
};