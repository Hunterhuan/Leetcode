// 跟之前那道题基本一样。很简单
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        if(nums.size()==0)
            return 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i] == val){
                continue;
            }
            nums[cnt++] = nums[i];
        }
        return cnt;
    }
};