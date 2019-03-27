// 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int cur_max = nums[0];
        int cur_sum = max(0, nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            cur_sum = cur_sum + nums[i];
            cur_max = max(cur_max, cur_sum);
            cur_sum = max(0, cur_sum);
        }
        return cur_max;
    }
};