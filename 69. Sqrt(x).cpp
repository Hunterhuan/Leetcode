// 不知道这道题为啥会是easy。不是很明白。
// 开始自己想的是从x中间搜索。但会遇到临界的问题。用int表示就会溢出。
// 这个方法很巧妙。直接从int搜索域开始搜索。就能避免溢出的问题
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int left=0;
        int right=INT_MAX;
        while(true)
        {
            int mid=left+(right-left)/2;
            if(mid>(x/mid))
                right=mid-1;
            else
            {
                if(mid+1>x/(mid+1))
                    return mid;
                left=mid+1;
            }
        }
    }
};