// 不难，for循环遍历一遍，一个一个处理就可以了

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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(!intervals.size())
            return res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        int start = intervals[0].start, end = intervals[0].end;
        for(int i=1;i<intervals.size();++i){
            if(intervals[i].start > end){
                res.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else{
                end = max(end, intervals[i].end);
            }
        }
        res.push_back(Interval(start, end));
        return res;
    }
};