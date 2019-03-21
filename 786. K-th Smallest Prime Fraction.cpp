// 自己只会这种暴力的解法。ε=(´ο｀*)))唉
// hard 的题自己根本做不出来
class Solution {
public:
    struct cmp
{
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        return float(a.first)/a.second > double(b.first)/b.second;
    }
};
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        //sort(A.begin(), A.end());
        for(int i=0;i<A.size();++i){
            for(int j=i+1;j<A.size();++j){
                q.push(pair<int,int>(A[i],A[j]));
            }
        }
        vector<int> res(2);
        for(int i=0;i<K;++i)
        {
            res[0] = q.top().first;
            res[1] = q.top().second;
            q.pop();
        }
        return res;
    }
};



// runtime 只有12ms， 牛逼！
// 但自己也是理解了很久。 其实是l=0.0， r=1.0，然后二分搜索不断的精确到区间。
// 难点在于如何确定有多少个小于该区间。
class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    const int n = A.size();
    double l = 0;
    double r = 1.0;    
    while (l < r) {
    // 确定分割的点
      double m = (l + r) / 2;
      double max_f = 0.0;
      int total = 0;
      int p, q = 0;
      for (int i = 0, j = 1; i < n - 1; ++i) {
        while (j < n && A[i] > m * A[j]) ++j;
        if (n == j) break;
        total += (n - j);
        const double f = static_cast<double>(A[i]) / A[j];
        if (f > max_f) {
          p = i;
          q = j;
          max_f = f;
        }
      }
      if (total == K)
        return {A[p], A[q]};        
      else if (total > K)
        r = m;
      else
        l = m;
    }
    return {};
  }
};