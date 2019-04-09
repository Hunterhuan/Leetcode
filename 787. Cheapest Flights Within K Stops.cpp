/*我自己写的话，估计会用寻找最短路径的算法。
但是这道题有K次中转的限制。最短路径算法已经不能适用
但我还想就是分别对a和b进行k次转机的遍历。
然后看两次遍历中间相交的点。
但似乎也并不容易实现。*/



// 在网上看到别人用bellman-ford 算法


/*核心思想还是用的动态规划Dynamic Programming，最核心的部分就是松弛操作Relaxation，也就是DP的状态转移方程。
这里我们使用一个二维DP数组，其中dp[i][j]表示最多飞i次航班到达j位置时的最少价格，那么dp[0][src]初始化为0，因为飞0次航班的价格都为0，
转机K次，其实就是飞K+1次航班，我们开始遍历，i从1到K+1，每次dp[i][src]都初始化为0，因为在起点的价格也为0，然后即使遍历所有的航班x，
更新dp[i][x[1]]，表示最多飞i次航班到达航班x的目的地的最低价格，
用最多飞i-1次航班，到达航班x的起点的价格加上航班x的价格之和，二者中取较小值更新即可，*/



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(K + 2, vector<int>(n, 1e9));
        dp[0][src] = 0;
        for (int i = 1; i <= K + 1; ++i) {
            dp[i][src] = 0;
            for (auto x : flights) {
                dp[i][x[1]] = min(dp[i][x[1]], dp[i - 1][x[0]] + x[2]);
            }
        }
        return (dp[K + 1][dst] >= 1e9) ? -1 : dp[K + 1][dst];
    }
};



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dp(n, 1e9);
        dp[src] = 0;
        for (int i = 0; i <= K; ++i) {
            vector<int> t = dp;
            for (auto x : flights) {
                t[x[1]] = min(t[x[1]], dp[x[0]] + x[2]);
            }
            dp = t;
        }
        return (dp[dst] >= 1e9) ? -1 : dp[dst];
    }
};