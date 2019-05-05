// 动态规划。不会。
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int l = nums.size() - k + 1;
        
        int sums[20000];
        for (int i = 0; i < l; ++i) sums[i] = 0;
        for (int i = 0; i < l; ++i)
        	for (int j = 0; j < k; ++j)
        		sums[i] += nums[i + j];
 
        int dp[3][20000];
        for (int i = 0; i < 3; ++i)
        	for (int j = 0; j < l; ++j)
        		dp[i][j] = 0;
 
        // dp[i][j] = maximun sum of previous j sums of number i
        // 0
        dp[0][0] = sums[0];
    	for (int i = 1; i < l; ++i) dp[0][i] = max(dp[0][i - 1], sums[i]);
    	// 1
    	dp[1][k] = sums[0] + sums[k];
        for (int i = 1 + k; i < l; ++i) dp[1][i] = max(dp[1][i - 1], sums[i] + dp[0][i - k]);
    	// 2
    	dp[2][k + k] = sums[0] + sums[k] + sums[k + k];
        for (int i = 1 + k + k; i < l; ++i) dp[2][i] = max(dp[2][i - 1], sums[i] + dp[1][i - k]);
 
        vector<int> result(3);
    	int max, pos;
    	int limit = l;
    	for (int i = 2; i >= 0; --i) {
    		max = pos = 0;
	    	for (int j = 0; j < limit; ++j) {
	    		if (max < dp[i][j]) {
	    			max = dp[i][j];
	    			pos = j;
	    		}
	    	}
	    	result[i] = pos;
	    	limit = pos - k + 1;
    	}
 
        return result;
    }
};


// 本来我的思路是建立dp[i][j]就是从i到j最大subarray的起始index.
// 然后通过遍历两个就行了。(a,i,b,j,c)以i，j为分界，双层for循环得到结果。



// 下面别人的方法也是很棒的。
// 不需要二次方了。他只遍历中间的，那个b的起始位置，
// 然后通过累加和知道从起始到中间的最大的，和中间到最后的最大的。找到最好的就可以了。


// https://www.cnblogs.com/grandyang/p/8453386.html
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), mx = INT_MIN;
        vector<int> sums{0}, res, left(n, 0), right(n, n - k);
        for (int num : nums) sums.push_back(sums.back() + num);
        for (int i = k, total = sums[k] - sums[0]; i < n; ++i) {
            if (sums[i + 1] - sums[i + 1 - k] > total) {
                left[i] = i + 1 - k;
                total = sums[i + 1] - sums[i + 1 - k];
            } else {
                left[i] = left[i - 1];
            }
        }
        for (int i = n - 1 - k, total = sums[n] - sums[n - k]; i >= 0; --i) {
            if (sums[i + k] - sums[i] >= total) {
                right[i] = i;
                total = sums[i + k] - sums[i];
            } else {
                right[i] = right[i + 1];
            }
        }
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1], r = right[i + k];
            int total = (sums[i + k] - sums[i]) + (sums[l + k] - sums[l]) + (sums[r + k] - sums[r]);
            if (mx < total) {
                mx = total;
                res = {l, i, r};
            }
        }
        return res;
    }
};