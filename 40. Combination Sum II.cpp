class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& candidates, vector<int> cur, int begin, int target){
        for(int i=begin;i<candidates.size();++i){
            if(candidates[i]>target)
                break;
            else if(candidates[i]==target){
                cur.push_back(candidates[i]);
                res.push_back(cur);
                break;
            }else{
                cur.push_back(candidates[i]);
                helper(res, candidates, cur, i+1, target-candidates[i]);
                cur.pop_back();
                while(i<candidates.size()-1 && candidates[i]==candidates[i+1])
                    i++;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        helper(res, candidates, cur, 0, target);
        return res;
    }
};