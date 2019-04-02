// solution1 : 就是不断的加进去，从base开始
// 但要考虑好如果相等的话怎么办。
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        res.push_back(1);
        int i=0,j=0,k=0;
        int minnumber;
        while(res.size()<n)
        {
            int ni=res[i]*2,nj=res[j]*3,nk=res[k]*5;
            minnumber=min(ni,min(nj,nk));
            if(minnumber==ni)
                ++i;
            if(minnumber==nj)
                ++j;
            if(minnumber==nk)
                ++k;
            res.push_back(minnumber);
        }
        return res.back();
    }
};
