// solution1 : sorting
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i)
            if(nums[i]!=i)
                return i;
        return n;
    }
};


// solution2 : hashtable 效率更低
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> m;
        for(auto num:nums){
            m[num] = true;
        }
        for(int i=0;i<=n;++i)
            if(!m[i])
                return i;
        return n;
    }
};


// solution3: bit manipulation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0;i<=n;++i)
            res ^= i;
        for(auto num:nums)
            res ^= num;
        return res;
    }
};