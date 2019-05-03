// 只让常数空间，那么就把这个array当作bool数组来用。用正负表示就行了
// 同样的题还有find duplicate in an array 278那道题
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for(int i=0;i<len;++i){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1] *= (-1);
            }else{
                res.push_back(abs(nums[i]));
            }
        }
        return res;
    }
};