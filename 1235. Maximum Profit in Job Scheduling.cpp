class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& profit) {
        int idx, tmp, n = s.size();
        // build 2xn struct for sorting
        vector <vector<int>> intervals(n, vector <int>(3));
        for(int i=0;i<n;i++){
            intervals[i][0] = s[i];
            intervals[i][1] = e[i];
            intervals[i][2] = profit[i]; 
        }
        // Earliest finish first (Greedy)
        sort(intervals.begin(), intervals.end(), [](auto &aa, auto &bb){return aa[1]<bb[1];});
        
        vector <int> DP(n);
        DP[0] = intervals[0][2]; // first jobs profit
        for(int i=1;i<n;i++){
            idx = -1;
            // Can be optimized by doing binary search
            for(int j=i-1;j>=0;j--)
                if(intervals[j][1] <= intervals[i][0]){
                    // If there exists a job whose finish time is prior to current's start
                    idx = j; 
                    break;
                }
            // if latest previous job that is compatible exists, idx will not be -1 
            tmp = (idx==-1)?intervals[i][2]:intervals[i][2]+DP[idx];
            // DP Update
            DP[i] = max(tmp, DP[i-1]);
        }
        return DP[n-1];
    }
};