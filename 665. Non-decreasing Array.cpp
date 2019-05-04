class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
         bool modified = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (modified) return false;
                // 这个判断条件很巧妙。可以再做一次的
                (i - 2 < 0 || nums[i - 2] <= nums[i]) ? nums[i - 1] = nums[i] : nums[i] = nums[i - 1];
                modified = true;
            }
        }
        return true;
    }
};