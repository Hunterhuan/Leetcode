// 要么最大的三个，要么最小的两个和最大的一个。
// 要考虑到负数。

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()<3)
            return 0;
        int len = nums.size();
        return max(nums[len-1]*nums[len-2]*nums[len-3], nums[0]*nums[1]*nums[len-1]);
    }
};