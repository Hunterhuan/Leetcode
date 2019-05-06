// 哭了。竟然是这么做
// 从左边遍历找到最大的。
// 从右边遍历找到最小的。
// 然后对每个遍历，如果max<=min 的时候，就++
// 原理：如果此时max<=min，就说明这个可以作为一个分界，
// 前面和后面的sort之后都是有序的
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