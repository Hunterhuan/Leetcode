class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int cnt = 0;
        if (timeSeries.size() == 0)// 一个特判
            return cnt;
        for (int i = 0; i < (int)timeSeries.size()-1; i++) {
            for (int k = 0; k < duration; k++) {
                if ((timeSeries[i] + k) != timeSeries[i + 1]) {
                    cnt++;
                }
                else {
                    break;
                }
            }
        }
        return cnt + duration;
        }
};