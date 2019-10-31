// 利用gray code，格雷码。
// 先生成格雷码，然后再根据题意把start作为开始就可以了。
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
            vector<int> res = {0,1};
            for(int i = 2;i <= n;i++){
                for(int j = res.size()-1;j >= 0;j--){
                    res.push_back(res[j] + (1 << (i-1)));
                }
            }

            int l = 0,r = res.size()-1;
            while(l <= r){
                if(res[l] == start || res[r] == start) break;
                l++,r--;
            }

            if(res[l] == start){
                reverse(res.begin(),res.end());
                reverse(res.begin(),res.end()-l);
                reverse(res.end()-l,res.end());
            }else{
                reverse(res.begin(),res.end());
                reverse(res.begin(),res.begin()+l+1);
                reverse(res.begin()+l+1,res.end());
            }
            return res;
    }
};




// dp算法
class Solution {
public:
    vector<vector<int>> dp;
    Solution(){
        dp.push_back({0,1});
        for(int n = 2;n<=16;n++){
            int h = 1 << (n-1);
            dp.push_back({});
            for(int i = dp[n-2].size()-1;i>=0;i--){
                dp[n-1].push_back(h + dp[n-2][i]);
            }
            for(int i = 0;i<dp[n-2].size();i++){
                dp[n-1].push_back(dp[n-2][i]);
            }
        }
        
    }
    vector<int> circularPermutation(int n, int start) {
        vector<int> ret;
        int s = 0;
        while(dp[n-1][s]!=start){
            s++;
        }
        for(int i = s;i<dp[n-1].size();i++){
            ret.push_back(dp[n-1][i]);
        }
        for(int i = 0;i<s;i++){
            ret.push_back(dp[n-1][i]);
        }
        return ret;
    }
};