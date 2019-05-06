// 用hash表遍历的方法
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s;
        for(auto a: A)
            s.insert(a);
        int res = 2;
        for(int i=0;i<A.size()-2;++i){
            for(int j = i+1; j<A.size()-1;++j){
                int tmp = 2;
                int pre1 = A[i], pre2 = A[j];
                while(s.find(pre1+pre2)!=s.end()){
                    ++tmp;
                    pre2 += pre1;
                    pre1 = pre2-pre1;
                }
                res = max(tmp, res);
            }
        }
        if(res==2)
            return 0;
        return res;
    }
};


// 自己在想如何用状态转移方程。但似乎想不到

// dp的效率挺高的
// 但dp为什么效率会高。因为前两个数只要定下，后面的所有都会不同。感觉是跟暴力完全一样的
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int N = A.size();
        unordered_map<int, int> index;
        // 建立索引
        for (int i = 0; i < N; ++i)
            index[A[i]] = i;

        unordered_map<int, int> longest;
        int ans = 0;
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < k; ++j) {
                if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
                    int i = index[A[k] - A[j]];
                    longest[j * N + k] = longest[i * N + j] + 1;
                    ans = max(ans, longest[j * N + k] + 2);
                }
            }

        return ans >= 3 ? ans : 0;
    }
};
