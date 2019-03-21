// solution: greedy 每次尽量都多扎
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int res = 0;
        int i = 0;
        sort(points.begin(), points.end(), [](pair<int,int>& a, pair<int,int>& b){return a.first < b.first;});
        while(i<points.size()){
            int start = points[i].first;
            int end = points[i].second;
            int j;
            for(j = i+1;j<points.size();++j){
                if(points[j].first<=end){
                    start = max(points[j].first, start);
                    end = min(points[j].second, end);
                }
                else
                    break;
            }
            i = j;
            ++res;
        }
        return res;
    }
};