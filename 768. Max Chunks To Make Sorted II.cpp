// 哭了。竟然是这么做
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int len = arr.size();
        vector<int> leftMax(len,0);
        vector<int> rightMin(len,0);
        leftMax[0] = arr[0];
        for(int i=1;i<len;++i){
            leftMax[i] = max(leftMax[i-1],arr[i]);
        }
        rightMin[len-1] = arr[len-1];
        for(int i=len-2; i>=0;--i){
            rightMin[i] = min(rightMin[i+1],arr[i]);
        }
        int total =1;
        for(int i=0;i<len-1;++i){
            if(leftMax[i] <= rightMin[i+1])
                total++;
        }
        return total;
    }
};