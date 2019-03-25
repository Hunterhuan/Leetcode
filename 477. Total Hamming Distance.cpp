// 对32位上分别求，这个效率还不是最好，说明还有更好的方法。
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int N = nums.size();
        for(int i=0;i<32;++i){
            int n = 0;
            for(int j=0;j<N;++j){
                if((nums[j]>>i)&1)
                    ++n;
            }
            res += (N-n)*n;
        }
        return res;
    }
};


// 大概看了一下，方法都是count的。效率应该就这样了吧。