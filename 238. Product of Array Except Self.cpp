// 简单
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if(len==0)
            return {};
        if(len==1)
            return {1};
        vector<int> v(len,0);
        v[0] = nums[0];
        vector<int> v2(len,0);
        v2[len-1] = nums[len-1];
        for(int i=1;i<len;++i){
            v[i] = v[i-1]*nums[i];
            v2[len-1-i] = v2[len-i]*nums[len-1-i];
        }
        vector<int> res(len,0);
        res[0] = v2[1];
        res[len-1] = v[len-2];
        for(int i=1;i<len-1;++i){
            res[i] = v[i-1]*v2[i+1];
        }
        return res;
    }
};