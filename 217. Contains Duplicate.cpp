class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int length = 0;
        for(auto n:nums){
            s.insert(n);
            if(s.size()==length){
                return true;
            }
            length = s.size();
        }
        return false;
    }
};