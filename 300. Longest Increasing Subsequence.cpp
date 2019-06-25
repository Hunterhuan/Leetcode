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


// 维护一个lps数组，如果比最后的大，就push到最后，如果不是，那么就找到lower_bound，改为nums[i].
// 最后结果就是lps的size
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;
        vector<int> lps;
        lps.push_back(nums[0]);
        for (int i=0; i<nums.size(); i++)
        {
            
            if(nums[i]>lps.back())
                lps.push_back(nums[i]);
            else{
                auto it = lower_bound(lps.begin(), lps.end(), nums[i]);
                *it = nums[i];
            }
        }
        return lps.size();
    }
};