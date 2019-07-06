class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        int res = nums[0];
        int sum = 0;
        for(int i=1;i<nums.size();++i){
            res = min(res, nums[i]);
        }
        for(int i=0;i<nums.size();++i){
            sum += (nums[i]-res);
        }
        return sum;
    }
};