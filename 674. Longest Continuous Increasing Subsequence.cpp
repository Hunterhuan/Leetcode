class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 1;
        if(nums.size()<=1){
            return int(nums.size());
        }
        int res = 1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1]){
                ++cnt;
                res = max(res, cnt);
            }
            else
                cnt = 1;
        }
        return res;
    }
};