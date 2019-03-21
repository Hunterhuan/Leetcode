// 这道题，自己失误失误到，没想到如果能到达i，那么小于i的地方全都能到。
// 所以只要维护一个最远的就可以了。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for(int i=0;i<=farthest && farthest <nums.size()-1;++i)
            farthest = max(farthest, i+nums[i]);
        return farthest >=nums.size()-1;
    }
};