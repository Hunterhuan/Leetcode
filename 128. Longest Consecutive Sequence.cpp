// O(n) 复杂度，就只能使用hashmap了
// 如果不限制复杂度的话，可以sort一下再search

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hash;
        for(auto val: nums) hash[val] = true;
        int Max = 0;
        for(auto val: nums)
        {
            int len = 1, tem = val+1;
            while(hash.count(tem))
            {
                hash.erase(tem);
                len++, tem++;
            }
            tem = val-1;
            while(hash.count(tem))
            {
                hash.erase(tem);
                len++, tem--;
            }
            Max = max(len, Max);
        }
        return Max;
    }
};