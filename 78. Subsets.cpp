// 找出所有的subsets，我的solution是递归。
// 但看起来效率一般。
class Solution {
public:
    void getsubsets(vector<vector<int>> &res, int cnt, vector<int> cur, vector<int> & nums){
        if(cnt==nums.size()){
            res.push_back(cur);
            return;
        }
        getsubsets(res, cnt+1, cur, nums);
        cur.push_back(nums[cnt]);
        getsubsets(res, cnt+1, cur, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        getsubsets(res, 0, cur, nums);
        return res;
    }
};

// 乘n次2，就可以用 <<n 来实现
// 这个是用bit
// 看某一位是不是

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.reserve(1<<nums.size()+1);
    
        
        for (int i = 0; i < 1 << nums.size(); i++) {
            int n = i;
            
            int j = 0;
            vector<int> subset;
            // 这个部分的操作很有趣。
            while (n > 0) {
                if (n & 1) {
                    subset.push_back(nums[j]);
                }
                n >>= 1;
                ++j;
            }
            result.push_back(subset);
        }
        
        return result;
    }
};