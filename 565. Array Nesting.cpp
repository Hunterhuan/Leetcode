class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        vector<int> v(len,0);
        int cur = 0;
        int res = 0;
        while(cur<len){
            if(v[cur]!=0){
                ++cur;
                continue;
            }
            int cnt = 0;
            int c = cur;
            while(1){
                v[c] = cnt++;
                c = nums[c];
                if(c==cur){
                    v[cur] = cnt;
                    break;
                }
            }
            res = max(res, cnt);
            ++cur;
        }
        return res;
    }
};