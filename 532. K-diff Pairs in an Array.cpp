// sort后搜索
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), j = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int j = max(j, i + 1);
            while (j < n && (long)nums[j] - nums[i] < k) ++j;
            if (j < n && (long)nums[j] - nums[i] == k) ++res;
            while (i < n - 1 && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};

// 利用map
#include <map>
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0)
            return 0;
        unordered_map<int,int> m;
        int sum=0;
        for(int i = 0;i<nums.size();++i)
            ++m[nums[i]];
        for(auto it=m.begin();it!=m.end();++it){
            if(k==0){
                 if(it->second > 1)
                     ++sum;
            }
            else if(m.find(it->first + k)!=m.end())
                ++sum;
        }
        return sum;
    }
};