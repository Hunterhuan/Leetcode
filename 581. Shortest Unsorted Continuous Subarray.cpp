// 用stack 去从两边向里面add，直到逆序开始。
// 感觉都不是一个easy的题
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int l = nums.size(), r = 0;
        for(int i=0;i< nums.size();++i){
            while(!s.empty() && nums[s.top()]>nums[i]){
                l = min(l, s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i = nums.size()-1; i>=0; --i){
            while(!s.empty() && nums[s.top()] < nums[i]){
                r = max(r, s.top());
                s.pop();
            }
            s.push(i);
        }
        return r-l>0 ? r-l+1:0;
    }
};