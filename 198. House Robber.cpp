// 自己用vector实现的，看起来效率不是很高
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        dp[2] = nums[1];
        for(int i=3;i<=n;++i){
            dp[i] = max(dp[i-2],dp[i-3])+nums[i-1];
        }
        return max(dp[n],dp[n-1]);
    }
};


//别人还是用几个数来记录的，没有用vector
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        int result[size];
        result[0] = nums[0];
        result[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            result[i] = max(result[i - 1], result[i - 2] + nums[i]);
        }
        return result[size - 1];
    }
    int max(int a, int b) {
        return a > b ? a : b;
    }
};