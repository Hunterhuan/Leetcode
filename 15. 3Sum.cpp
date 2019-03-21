// fix一个，然后用twosum的方法利用map去搜索，但遇到了问题，因为有重复的数字
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i=0;i<nums.size()-2;++i){
            int target = 0-nums[i];
            unordered_map<int, int> comp;
            for(int j=i+1;j<nums.size();++j){
                unordered_map<int,int>::const_iterator got = comp.find(nums[j]);
                if(got != comp.end()){
                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[got->second]);
                    a.push_back(nums[j]);
                    result.push_back(a);
                }
                comp.insert({target-nums[i],i});
            }
        }
        return result;
    }
};


//方法2 就是先sort成有order的，然后再用双指针
// 这个题关键在于处理重复的number
// right-- 和  left++ ????
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        for(int i=0;i< nums.size();++i){
            if((i>0) && (nums[i]==nums[i-1]))
                continue;
            int left=i+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    res.push_back(vector<int> {nums[i],nums[left],nums[right]});
                    while(left + 1<right && nums[left] == nums[left +1])
                        ++left;
                    while(left+1<right && nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
                else if(sum>0)
                    right--;
                else
                    left++;
            }
        }
        return res;
    }
};

// 相关
// 3-sum-smaller
// 3sum cloest