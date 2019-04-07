// 辣鸡题，边界情况这么多
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int sum = 0;
        
        hash[0] = -1;
        for(int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if(k) sum %= k;
            if(hash.find(sum) != hash.end()) {
                if(i-hash[sum] > 1) return true;
            }
            else hash[sum] = i;
        }
        
        return false;
    }
};