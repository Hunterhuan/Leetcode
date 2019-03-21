// 两个指针，一个快，一个慢。不难
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int num = 0;
        while(num < nums.size()){
            int count = num;
            ++num;
            while(num < nums.size() && nums[num]==nums[num-1])
                ++num;
            count = min(2, num-count);
            while(count--)
                nums[cnt++] = nums[num-1];
        }
        return cnt;
    }
};