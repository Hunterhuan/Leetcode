// 使用了递归。效率极低
class Solution {
public:
    void getres(vector<vector<int>> &res, vector<int> & candidates, int target, vector<int> v, int start , int sum){
        if(sum > target)
            return;
        if(sum==target){
            res.push_back(v);
            return;
        }
        if(start>=candidates.size())
            return;
        getres(res, candidates, target, v, start+1, sum);
        while(sum<target){
            v.push_back(candidates[start]);
            sum = sum+candidates[start];
            getres(res, candidates, target, v, start+1, sum);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> t;
        getres(res, candidates, target, t, 0, 0);
        return res;
    }
};

// 别人的简洁代码。
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        sort(candidates.begin(), candidates.end());
        helper(results,vector<int>{},candidates,target,0);
        return results;
    }
    void helper(vector<vector<int>> &results, vector<int> result, vector<int>& c, int target, int index){
        if(target == 0){
            results.push_back(result);
            return;
        }
        for(int i = index; i < c.size() && target >= c[i]; ++i){
            result.push_back(c[i]);
            helper(results, result, c, target - c[i], i);
            result.pop_back();
        }//end of for
    }//end of helper
};