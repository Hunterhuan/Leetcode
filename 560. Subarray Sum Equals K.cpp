//solution1 : 求和
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int len = nums.size();
        vector<int> sum(len+1,0);
        for(int start = 1; start<=len;++start){
            sum[start] = nums[start-1]+sum[start-1];
        }
        for(int start = 0; start<len;++start){
            for(int end = start+1; end<=len;++end){
                if(sum[end]-sum[start] == k)
                    ++count;
            }
        }
        return count;
    }
};


//solution2: brute force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int len = nums.size();
        for(int start = 0; start<len;++start){
            int sum = 0;
            for(int end = start; end<len;++end){
                sum += nums[end];
                if(sum==k)
                    ++count;
            }
        }
        return count;
    }
};


// 最推崇的方法。用hashmap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> m{{0, 1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            res += m[sum - k];
            ++m[sum]; 
        }
        return res;
    }
};