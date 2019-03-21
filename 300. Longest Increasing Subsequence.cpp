// 看起来是以前自己做的，用的是dp
#include <math>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int dp[nums.size()];
        dp[0] = 1;
        int maxAns = 1;
        for(int i=0;i<nums.size();++i){
            int maxVal = 0;
            for(int j=0;j<i;++j){
                if(nums[i]> nums[j])
                    maxVal = max(maxVal, dp[j]);
            }
            dp[i] = maxVal + 1;
            maxAns = max(maxAns, dp[i]);
        }
        return maxAns;
    }
};

// 