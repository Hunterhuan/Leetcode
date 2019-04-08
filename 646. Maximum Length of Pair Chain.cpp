class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int N = pairs.size();
        if(N<=1)
            return N;
        int res = 1;
        sort(pairs.begin(), pairs.end());
        vector<int> dp(N,1);
        for(int i=1;i<N;++i){
            for(int j=0;j<i;++j){
                if(pairs[j][1]<pairs[i][0])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};


// greedy algorithm
class Solution {
private:
    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1]<b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int N = pairs.size();
        if(N<=1)
            return N;
        sort(pairs.begin(), pairs.end(), cmp);
        int cur = INT_MIN, ans = 0;
        for(auto pair:pairs)
            if(cur < pair[0]){
                cur = pair[1];
                ans++;
            }
        return ans;
    }
};