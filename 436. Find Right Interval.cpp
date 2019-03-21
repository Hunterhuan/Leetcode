// 感觉这种东西无从下手诶。
// 

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> retv;
        unordered_map<int,int> start_index;
        vector<int> start;
        for(int i  =0;i<intervals.size();i++)
        {
            start_index[intervals[i].start] = i;
            start.push_back(intervals[i].start);
        }
        sort(start.begin(),start.end());
        //O(nlogn) method
        for(int i = 0;i<intervals.size();i++)
        {
            int index = lower_bound(start.begin(),start.end(),intervals[i].end)-start.begin();
            if(index == intervals.size())
                retv.push_back(-1);
            else
                retv.push_back(start_index[start[index]]);
        }
        return retv;
    }
};