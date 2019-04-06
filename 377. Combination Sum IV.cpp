// gg 自己写的bfs又超时了
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int base = q.front();
                q.pop();
                for(auto num:nums){
                    if(base+num==target)
                        res++;
                    else if(base+num > target)
                        break;
                    else
                        q.push(base+num);
                }
            }
        }
        return res;
    }
};

// 别人的dp算法，很简洁
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        vector<long> dp(target+1, 0);
        dp[0] = 1;
        for(int i =1; i <= target; i++)
        {
            for(auto val: nums)
                if(val <= i) dp[i] = (dp[i]+dp[i-val])%INT_MAX;
        }
        return dp[target];
    }
};