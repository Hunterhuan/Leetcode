// 虽然是hard，但是只是感觉麻烦。
// 感觉还行。自己没有动手写。但是自己写应该是能写出来的。不过多了一些特判情况而已。
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
**/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        // 空的话，这种情况特判。
        if (intervals.size() < 1) {
            return vector<Interval> (1, newInterval);
        }
        // 找到开始的节点。
        int i=0;
        for (i=0; i<intervals.size(); ++i) {
            if (newInterval.start < intervals[i].start) {
                
                break;
            }
        }
        // 直接插入进去
        intervals.insert(intervals.begin()+i, newInterval);
        // 然后merge在一起
        // 这个merge的过程和我之前写的merge interval一样
        // emplace_back() 与 push_back() 的区别
        vector<Interval> res;
        int starts = intervals[0].start, ends = intervals[0].end;
        for (i=1; i<intervals.size(); ++i) {
            if (intervals[i].start <= ends) {
                ends = max(ends, intervals[i].end);
            } else {
                res.emplace_back(Interval(starts, ends));
                starts = intervals[i].start;
                ends = intervals[i].end;
            }
        }
        res.emplace_back(starts, ends);
        return res;
    }
};