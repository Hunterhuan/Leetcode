// 懂这道题的意思了。
// 对每个数，争取都放在对应的地方。然后从1开始遍历。如果没有被n被放置到n，就返回n
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 特判特殊情况
        if(!n)
            return 1;
        // 对每个遍历
        for(int i=0;i<n;++i){
            // 如果正好，那就跳过
            if(nums[i]==i+1)
                continue;
            // 如果遇到了可以替换的，那么就替换掉。
            while(nums[i]<=n && nums[i]>0 && nums[i]!=nums[nums[i]-1]){
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
        }
        int i=0;
        for(i=0;i<n;++i){
            if(nums[i]!=(i+1))
                break;
        }
        return i+1;
    }
};