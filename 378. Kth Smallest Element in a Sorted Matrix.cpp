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