// 这道题很明显就是一道dp的问题。动态规划。不知道和二分法有什么关系。
// 很久没接触了，这么不是很难的题仍然看了很久。以后遇到dp的题应该动手去看公式
// dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
// 我本来是想从正向去推，发现有问题，这道题只能从逆向推。先从目标点，一点点扩展到出发点。得到最好结果。
// 建立一个二维数组dp，其中dp[i][j]用来表示当前位置 (i, j) 出发的起始血量，最先处理的是公主所在的房间的起始生命值，然后慢慢向第一个房间扩散，不断的得到各个位置的最优的生命值。逆向推正是本题的精髓所在啊，仔细想想也是，如果从起始位置开始遍历，我们并不知道初始时应该初始化的血量，但是到达公主房间后，我们知道血量至少不能小于1，如果公主房间还需要掉血的话，那么掉血后剩1才能保证起始位置的血量最小。


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        // 这个很重要，看看如何才能create一个二维vector
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};

// 对于优化成一维的一直不是很懂。
// 我们可以对空间进行优化，使用一个一维的dp数组，并且不停的覆盖原有的值，参见代码如下：
// 不懂，应该标记tag一下
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0];
    }
};