// 果然是hard， brute force的方法果然超时了
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> sum(A.size()+1,0);
        for(int i = 0;i<A.size();++i)
            sum[i+1] = sum[i] + A[i];
        int res = INT_MAX;
        for(int i=0;i<sum.size();++i){
            for(int j=i+1;j<sum.size()&& j-i<res;++j){
                if(sum[j]-sum[i]>=K)
                    res = j-i;
            }
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
};



class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if(A.empty()){
            return -1;
        }
        
        int minRes = INT_MAX;
        
        vector<int> ps;
        ps.push_back(0);
        // 双端队列
        deque<int> q;
        // 求序列和
        for(int i=0;i<A.size();++i)
            ps.push_back(ps.back()+A[i]);
        
        // 对每个遍历
        for(int i = 0; i < ps.size(); ++i){
            // 看不懂
            while(!q.empty() && ps[q.back()] > ps[i]){
                q.pop_back();
            }
            
            while(!q.empty() && ps[i] - ps[q.front()] >= K){
                minRes = min(minRes,i - q.front());
                q.pop_front();
            }
            
            q.emplace_back(i);
        }
        
        return (minRes == INT_MAX ? -1 : minRes);
    }
};