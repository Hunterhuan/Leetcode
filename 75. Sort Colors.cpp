// sort，因为已经给出了 值域，所以能用双指针。遇到要提前的就置换到前面。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt = 0, l= nums.size()-1;
        int tmp;
        while(cnt<l){
            while(nums[cnt]==0 && cnt<l)
                ++cnt;
            while(l>cnt && nums[l]!=0)
                --l;
            tmp = nums[l];
            nums[l] = nums[cnt];
            nums[cnt] = tmp;
        }
        l = nums.size() - 1;
        while(cnt<l){
            while(nums[cnt]==1 && cnt<l)
                ++cnt;
            while(l>cnt && nums[l]!=1)
                --l;
            tmp = nums[l];
            nums[l] = nums[cnt];
            nums[cnt] = tmp;
            ++cnt;
        }
    }
};