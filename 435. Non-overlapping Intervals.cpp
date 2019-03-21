// solution: 对start从小到大排序，
// 然后对每个重叠的，删去end最大的。来保证影响最小。
// 思路想对了
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// 这个实现是别人写的
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int res = 0, n = intervals.size(), last = 0;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){return a.start < b.start;});
        for (int i = 1; i < n; ++i) {
            if (intervals[i].start < intervals[last].end) {
                ++res;
                if (intervals[i].end < intervals[last].end) last = i;
            } else {
                last = i;
            }
        }
        return res;
    }
};