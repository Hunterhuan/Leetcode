// to_string 函数

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0;
        while(i<nums.size()){
            int j = i+1;
            while(j<nums.size()){
                if(nums[j]==nums[j-1]+1)
                    j++;
                else
                    break;
            }
            if(j==i+1){
                res.push_back(to_string(nums[i]));
                ++i;
            }else{
                res.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
                i = j;
            }
        }
        return res;
    }
};