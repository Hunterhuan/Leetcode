class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(), nums.end());
        vector<int> list;
        Helper(nums, used, list, res);
        return res;
    }
    void Helper(vector<int> nums, vector<bool> used, vector<int> list, vector<vector<int>> &res){
        if(list.size()==nums.size()){
            res.push_back(list);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(used[i])
                continue;
            if(i>0 && nums[i-1]==nums[i] && !used[i-1])
                continue;
            used[i] = true;
            list.push_back(nums[i]);
            Helper(nums, used, list, res);
            used[i] = false;
            list.pop_back();
        }
    }
};