// 思路就是先算出和，然后除2之后就是target
// 问题转化为了在list中找到一个子集的和是target

// solution1: 就是用dp,每次遍历
// 但效率就是很低
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};



// solution2 : 使用bitset
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<5001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int num : nums) bits |= bits << num;
        return (sum % 2 == 0) && bits[sum >> 1];
    }
};

//solution3: dfs
// 感觉就是思路一样， 但这个效率就是高
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum+=nums[i];
        }        
        if (sum%2!=0) return false;        
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end(), greater<int>() );
        return helper(nums, visited, sum/2, 0, 0);        
    }
          
    bool helper(vector<int> &nums, vector<bool> &visited, int target, int cur_sum, int start) {
        if (cur_sum>target || start>=nums.size()) return false;
        if (cur_sum==target) return true;
        // 这里剪枝了，效率应该就是在这儿提升的
        if (nums[start]>target) return false;  // This is the key arg to make DFS pass OJ
        for (int i=start; i<nums.size(); i++) {
            if (visited[i] ) continue;
            visited[i] = true;
            if (helper(nums, visited, target, cur_sum+nums[i], i+1) ) return true;
            visited[i] = false;
        }        
        return false;        
    }
};
