class Solution {
private:
    void helper(vector<vector<int>> &res, vector<int> &cur, int pos, int n, int k){
        if(pos==n+1){
            if(cur.size()==k)
                res.push_back(cur);
            return;
        }
        if(n-pos+1+cur.size()<k)
            return;
        cur.push_back(pos);
        helper(res, cur, pos+1, n, k);
        cur.pop_back();
        helper(res, cur, pos+1, n, k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(res, cur, 1, n, k);
        return res;
    }
};