// 这个还是得找规律的。挺巧妙的
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0|| nums.size()==1)
            return;
        int c = nums.size()-2;
        for(; c>=0;--c){
            if(nums[c]<nums[c+1])
                break;
        }
        int b;
        if(c>=0){
            for(b=c+1;b<nums.size();++b){
                if(nums[b]<=nums[c]){
                    break;
                }
            }
            int tmp = nums[b-1];
            nums[b-1] = nums[c];
            nums[c] = tmp;
        }
        reverse(nums.begin()+c+1, nums.end());
    }
};