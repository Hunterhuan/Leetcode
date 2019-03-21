// 简单。这个两指针就是一个是需要填入的index，一个是遍历到的index
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        if(nums.size()==0)
            return 0;
        for(int i=1;i<nums.size();++i){
            if(nums[i] == nums[i-1])
                continue;
            nums[cnt++] = nums[i];
        }
        return cnt;
    }
};