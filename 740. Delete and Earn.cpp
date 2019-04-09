// 这个题挺难的。如果用两个数组可能就会容易理解一些。
// 一个数组是记录前一个被avoid掉的总earn
// 一个数组是记录前一个被use 掉的总earn
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001,0);
        for(int x:nums)
            count[x]++;
        int avoid = 0, use = 0, prev = -1;
        for(int k = 0; k<=10000; ++k){
            if(count[k]>0){
                int m = max(avoid, use);
                if(k-1 != prev){
                    use = k * count[k] + m;
                    avoid = m;
                }else{
                    use = k * count[k] + avoid;
                    avoid = m;
                }
                prev = k;
            }
        }
        return max(avoid, use);
    }
};