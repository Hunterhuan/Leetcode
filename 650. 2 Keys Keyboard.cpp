// dp的思路
// 这个思路也就是我能想到的最快的了
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1);
        dp[1] = 0;
        for(int i=2;i<=n;++i){
            dp[i] = i;
        }
        for (int i = 4; i <= n; ++i) {
            for (int j = i/2; j >= 2; --j) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j]+i/j);
                }
            }
        }
        return dp[n];
    }
};


// 这个效率奇高
// 但不是很懂
class Solution {
public:
    int minSteps(int n) {
        int ans = 0, d = 2;
        while(n>1){
            while(n%d==0){
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};