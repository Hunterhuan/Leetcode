// 自己写的代码。 别人写的应该更简洁
// 用两个一维数组，一个数组去追踪上一个，一个数组记录最好的结果。

// 关键在于排序，对于 i<j<k如果j%i k%j 那么k%i
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n<=1)
            return nums;
        vector<int> dp(n,1);
        vector<int> last(n,-1);
        int largest = 1;
        int largest_index = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j] + 1;
                        last[i] = j;
                        if(dp[i]>largest){
                            largest = dp[i];
                            largest_index = i;
                        }
                    }
                }
            }
        }
        vector<int> res;
        while(largest_index!=-1){
            res.push_back(nums[largest_index]);
            largest_index = last[largest_index];
        }
        return res;
    }
};



// 别人的代码
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() ==0) return {}; 
        sort(nums.begin(), nums.end(), greater<int>());
        int len = nums.size(), curMax=1, k=0;
        vector<int> par(len), dp(len, 1), result;
        for(int i =0; i < len; i++) par[i] = i;
        for(int i =1; i < len; i++)
        {
            for(int j =0; j < i; j++)
            {
                if(nums[j]%nums[i]!=0) continue;
                if(dp[i] < dp[j]+1) par[i] = j, dp[i]=dp[j]+1;
                if(dp[i] > curMax) curMax = dp[i], k = i;
            }
        }
        while(par[k] != k)
        {
            result.push_back(nums[k]);
            k = par[k];
        }
        result.push_back(nums[k]);
        return result;
    }
};