// 用map做。
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();++i){
            m[nums[i]] = i;
        }
        cout<<"1done"<<endl;
        vector<int> res;
        for(int i=0;i<findNums.size();++i){
            int j = m[findNums[i]];
            cout<<"done"<<endl;
            for(;j<nums.size();++j){
                if(nums[j] > findNums[i])
                    break;
            }
            if(j == nums.size())
                res.push_back(-1);
            else
                res.push_back(nums[j]);
        }
        return res;
    }
};



// 用stack做
// 思路很巧妙。
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> m;
        for (int num : nums) {
            while (!st.empty() && st.top() < num) {
                m[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for(int num:findNums){
            if(m[num])
                res.push_back(m[num]);
            else
                res.push_back(-1);
        }
        return res;
    }
};