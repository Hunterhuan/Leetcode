// woc别人都是怎么想到的。
// 每个数都是int，创建一个新数组
// 从0到32，count所有数中在这个为1的个数，个数不是三的倍数，
// 则说明只有一个的那个在这位为1.
// 最后取出result就可以了。

class Solution {
public:
    int singleNumber(vector<int>& A) {
        int n = A.size();
        int count[32]={0};
        int result=0;
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                count[i]+=((A[j]>>i)&1); //首先把输入数字的第i位加起来。
                //count[i]=count[i]%3; //然后求它们除以3的余数。
            }
            count[i] = count[i]%3;
            result|=(count[i]<<i);//把二进制表示的结果转化为十进制表示的结果
        }
        return result;
    }
};