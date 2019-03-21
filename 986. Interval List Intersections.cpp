// 自己写的代码真烂。debug 都能de这么久
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int cnt_b = 0;
        vector<Interval> res;
        for(int i=0;i<A.size();++i){
            cnt_b = min(cnt_b, int(B.size()-1));
            for(; cnt_b<B.size();++cnt_b){
                int start = max(A[i].start, B[cnt_b].start), end = min(A[i].end, B[cnt_b].end);
                cout<<i<<' '<<cnt_b<<endl;
                if(start <= end)
                    res.push_back(Interval(start, end));
                if(B[cnt_b].start > A[i].end){
                    --cnt_b;
                    cnt_b = max(cnt_b, 0);
                    break;
                }
            }
        }
        return res;
    }
};

// 别人的代码就能简洁明了
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
      vector<Interval> res;
      for (auto i = 0, j = 0; i < A.size() && j < B.size(); ) {
        if (A[i].end < B[j].start) ++i;
        else if (B[j].end < A[i].start) ++j;
        else {
          res.push_back({ max(A[i].start, B[j].start), min(A[i].end, B[j].end) });
          if (A[i].end < B[j].end) ++i;
          else ++j;
        }
      }
      return res;
    }
};


// 这个代码更快
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> result;
        int i = 0;
        int j = 0;
        while (i < A.size() && j < B.size()) {
            int lo = max(A[i].start, B[j].start);
            int hi = min(A[i].end, B[j].end);
            if (lo <= hi) {
                Interval interval(lo, hi);
                result.emplace_back(move(interval));
            }
            if (A[i].end > B[j].end) {
                ++j;
            } else {
                ++i;
            }
        }
        return result;
    }
};