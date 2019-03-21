// 送分题。easy
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int res = 0;
        for(int i=0;i<nums.size();++i){
            if(!nums[i]){
                cnt = 0;
            }
            else
                cnt++;
            res = max(cnt, res);
        }
        return res;
    }
};