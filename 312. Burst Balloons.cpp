// 第一反应是回溯。但状态太多。不可能的
// 所以转向dp，dp的状态转移方程好难想。


class Solution {
public:
    //using dp
    vector<vector<int>> d;
    int maxCoins(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int size = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        d = vector<vector<int>>(size + 2, vector<int>(size + 2, 0));
        for(int len = 1; len <= size; ++len){
            for(int start = 1;start + len - 1 <= size; ++start){
                int end = start + len - 1;
                for(int k = start;k <= end; ++k){// k is the last one to be popped
                    d[start][end] = max(d[start][end], d[start][k - 1] + d[k + 1][end] + nums[start - 1] * nums[k] * nums[end + 1]);
                }
            }
        }
        return d[1][size];
    }
};