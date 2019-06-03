class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //nums = {1,2,3,1,2,3};
        //k = 2;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();++i){
            if(m.count(nums[i])){
                if(i+1-m[nums[i]]<=k)
                    return true;
            }
            m[nums[i]] = i+1;
        }
        return false;
    }
};