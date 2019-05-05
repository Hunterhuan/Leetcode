class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        vector<int> v(len,0);
        vector<int> v2(len,0);
        for(int i=1;i<len;++i){
            v[i] = v[i-1] + nums[i-1];
            v2[len-i-1] = v2[len-i] + nums[len-i];
        }
        for(int i=0;i<len;++i){
            if(v[i]==v2[i])
                return i;
        }
        return -1;
    }
};