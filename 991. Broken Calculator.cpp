// 惊了，别人的solution竟然这么简单。
// 知道自己为什么错了。自己想从X变到Y，应该从Y变到X
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while(Y>X){
            ans++;
            if(Y%2==1)
                Y++;
            else
                Y /=2;
        }
        return ans+X-Y;
    }
};