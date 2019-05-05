// 不会做。还得再做再理解
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums.back()-nums[0];
        while(lo < hi){
            // 对差值二分搜索
            int mi = (lo + hi)/2;
            // 滑动窗口法
            int count = 0, left = 0;
            for(int right = 0; right<nums.size();++right){
                while(nums[right]-nums[left]>mi)
                    left++;
                count += right-left;
            }
            if(count>=k)
                hi = mi;
            else
                lo = mi +1;
        }
        return lo;
    }
};