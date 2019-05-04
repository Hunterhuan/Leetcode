// 暴力法
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        if(len<3)
            return res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;++i){
            for(int j=i+1;j<nums.size()-1;++j){
                for(int k=j+1; k<nums.size() && nums[k]<nums[i]+nums[j];++k){
                    ++res;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        if(len<3)
            return res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<len-2;++i){
            int k = i+2;
            for(int j=i+1;j<len-1 && nums[i]!=0;++j){
                while(k<len && nums[i]+nums[j]>nums[k])
                    k++;
                res += (k-j-1);
            }
        }
        return res;
    }
};