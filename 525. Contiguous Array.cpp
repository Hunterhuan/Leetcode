class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> hash;
        hash[0]=-1;
        int ans=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]?1:-1;
            if(hash.count(sum))
                ans=max(ans,i-hash[sum]);
            else
                hash[sum]=i;                            //记录下标
        }
        return ans;
    }
};