// 遍历两遍，找到最大的两个数，比较一下就可以了。
class Solution {
public:
int dominantIndex(vector<int>& nums) {
    int sizeN = nums.size();
    if (sizeN <= 1)
        return 0;
    
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    if (temp[sizeN-1] < temp[sizeN-2]*2)
        return -1;
    
    return find(nums.begin(), nums.end(), temp[sizeN-1]) - nums.begin();
}
};