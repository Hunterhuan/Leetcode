class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(int(nums.size()), -1);
        stack<pair<int,int>> st;
        for(int i=0;i<nums.size();++i){
            while(!st.empty() && st.top().first<nums[i]){
                res[st.top().second] = nums[i];
                st.pop();
            }
            st.push(pair<int,int>(nums[i],i));
        }
        for(int i=0;i<nums.size();++i){
            while(!st.empty() && st.top().first<nums[i]){
                res[st.top().second] = nums[i];
                st.pop();
            }
        }
        return res;
    }
};


// 别人的运行更快
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        vector<int> ret(nums.size(), -1);        
        stack<int> s;
        
        for(int i = 0; i<nums.size()*2; ++i) {
            int num = nums[i%nums.size()];
            while(s.size() && nums[s.top()] < num) {
                ret[s.top()] = num;
                s.pop();
            }
            
            if(i < nums.size()) {
                s.push(i);
            }
        }
        
        return ret;
    }
};