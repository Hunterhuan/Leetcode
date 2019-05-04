// 没思路。看了tip中，也没提到用backtrack的方法。
// 就不知道怎么搞了

// 思路：好像是分析的出来的答案
//给定n那么k最大为n-1，假设这k个数字是 n-1,n-2,n-3...1，
//所以数列可以是1,n-1,2,n-2,....，比如给定n=9 k=8则数列可以是1 9 2 8 3 7 6 4 5，
//可以看出这组数据差值是8 7 6 5 4 3 2 1，如果给定k<n-1，
//则将剩余的项用递增或者递减顺序即可。


class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n,0);
        int c = 0;
        for(int v = 1; v< n-k;v++){
            ans[c++] = v;
        }
        for(int i=0; i<=k;++i){
            ans[c++] = (i%2==0)? (n-k+i/2):(n-i/2);
        }
        return ans;
    }
};