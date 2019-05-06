// 看到age有限制范围，而len很大，如果要len建数组的话，就会很不合理，就想到要count
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        //ages = {20,30,100,110,120};
        int len = ages.size();
        vector<int> num(125, 0);
        for(int i=0;i<len;++i){
            num[ages[i]]++;
        }
        vector<vector<bool>> matrix(121,vector<bool>(121,true));
        int res = 0;
        for(int i=1;i<=120;++i){
            for(int j=1;j<=120;++j){
                if(j<=0.5*i+7 || j>i || (j>100 &&i<100))
                    matrix[i][j] = false;
                else{
                    if(i==j){
                        res += (num[i]*(num[j]-1));
                    }else
                        res += num[i]*num[j];
                }
            }
        }
        return res;
    }
};