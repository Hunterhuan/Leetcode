//题目就是将 3sum变成了4sum
// 变成固定两个数，然后用双指针。一样的方法
// 但是提交了很多次，因为对重复数字把握的不是很好
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        if(nums.size()<4)
            return res;
        for(int i=0;i< nums.size();++i){
            if((i>0) && (nums[i]==nums[i-1]))
                continue;
            for(int j=i+1;j<nums.size();++j){
                if((j>i+1) && (nums[j]==nums[j-1]))
                    continue;
                int left=j+1, right = nums.size()-1;
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        res.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        while(left + 1<right && nums[left] == nums[left +1])
                            ++left;
                        while(left+1<right && nums[right] == nums[right-1])
                            right--;
                        left++;
                        right--;
                    }
                    else if(sum>target)
                        right--;
                    else
                        left++;
                }
            }
        }
        return res;
    }
};

// 跟3-sum 相比，多了一个for循环，