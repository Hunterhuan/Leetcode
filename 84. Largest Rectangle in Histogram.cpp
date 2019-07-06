// 要再做一次
// 找到峰值就向前循环
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        if(n==0)
            return 0;
        if(n==1)
            return heights[0];
        for(int i=0;i<heights.size();++i){
            if(i==n-1 || heights[i]>heights[i+1]){
                int min_l = heights[i];
                for(int j=i;j>=0;--j){
                    min_l = min(min_l, heights[j]);
                    res = max(res, min_l*(i-j+1));
                }
            }
        }
        return res;
    }
};