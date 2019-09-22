class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int num = INT_MAX;
        for(int i=0;i<arr.size()-1;++i){
            num = min(arr[i+1]-arr[i], num);
        }
        vector<vector<int>> res;
        for(int i=0;i<arr.size()-1;++i){
            if(arr[i+1]-arr[i]== num)
                res.push_back({arr[i], arr[i+1]});
        }
        return res;
    }
};