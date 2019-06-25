// 这个题挺难的。如果用两个数组可能就会容易理解一些。
// 一个数组是记录前一个被avoid掉的总earn
// 一个数组是记录前一个被use 掉的总earn


/*看题目，可以意识到是动态规划类型的题目，但不知道怎么写迭代式子，就是相不清楚状态。所以，一开始心虚的按照自己的贪婪算法实现了下，结果就是代码极多，但结果不能对～

无奈，开始查阅资料，找到了一篇比较靠谱的博客。借鉴他的思路，自己努力写了下动态规划的实现。思路的关键在于：

取出一个数，其收益为 数的频数 × 数的值。按照规则，取出一个，必然取出该值的所有数。
两个状态，取出当前数的最大收益（maxFetch），不取当前数的最大收益（maxNoFetch）。
初始状态：
　maxFetch = 0, maxNoFetch = 0;
当前状态与上一状态的关系
不取当前数，则为上一状态的最大值（max(prevMaxFetch, prevMaxNoFetch)）。
取出当前数，若数和上一状态的数关联（+/- 1），则为prevMaxNoFetch + 取出数的收益。否则，为max(prevMaxFetch, prevMaxNoFetch) + 取出数的收益。*/


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