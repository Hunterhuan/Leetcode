// 简单
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0)
                nums[cnt++] = nums[i];
        }
        while(cnt<nums.size())
            nums[cnt++] = 0;
    }
};