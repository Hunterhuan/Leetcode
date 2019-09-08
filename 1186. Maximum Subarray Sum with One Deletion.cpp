class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> fw(n, 0);
        vector<int> bw(n, 0);
        fw[0] = arr[0];
        int cur_max = 0;
        int max_all = INT_MIN;
        for(int i=0;i<n;++i){
            cur_max = max(arr[i], cur_max + arr[i]);
            max_all = max(max_all, cur_max);
            fw[i] = cur_max;
        }
        bw[n-1] = arr[n-1];
        cur_max = 0;
        for(int i=n-1;i>=1;--i){
            cur_max = max(arr[i], cur_max + arr[i]);
            max_all = max(max_all, cur_max);
            bw[i] = cur_max;
        }
        for(int i=1;i<n-1;++i){
            max_all = max(max_all, fw[i-1]+bw[i+1]);
        }
        return max_all;
    }
};