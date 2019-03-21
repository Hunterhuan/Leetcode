
//跟3-sum的思路接近，只是保存一个全局最优，每次更新就可以了
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();++i){
            if((i>0) && nums[i]==nums[i-1])
                continue;
            int left = i+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(res-target)>abs(sum-target))
                    res = sum;
                if(sum==target){
                    return target;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    left++;
                }
                
            }
        }
        return res;
    }
};