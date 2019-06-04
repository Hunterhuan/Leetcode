// solution1: 用优先队列实现
// 全部放进去，然后在pop出来。注意 pq 的定义如何定义。最大堆和最小堆
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto row:matrix){
            for(auto e:row){
                pq.push(e);
            }
        }
        for(int i=0;i<k-1;++i){
            pq.pop();
        }
        int res = pq.top();
        return res;
    }
};

// 用二分查找法去实现
// 注意upper_bound的写法。
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int size = matrix.size(), l = matrix[0][0], r = matrix[size-1][size-1];
        while(l < r)
        {
            int smaller = 0, m = l+((r-l)>>1);
            for(int i = 0; i < size; ++i) 
                smaller += upper_bound(matrix[i].begin(), matrix[i].end(), m)-matrix[i].begin();
            smaller<k? l=m+1 : r=m;
        }
        return r;
    }
};