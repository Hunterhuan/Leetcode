// 先统计S中的26个字母的index。
// 对于每个word，都在里面搜索。如果满足条件就+1。
// 搜索的时候使用二分搜索会效果好一些

class Solution {
public:
    int search(vector<int>&pos, int k){//二分查找下标数组中第一个大于k的数，k是words[i]中上一个字母的下标
        if(pos.size()==0)
            return -1;
        int l = 0;
        int r = pos.size()-1;
        if(k>=pos[r])
            return -1;
        while(l<r){
            int mid = (l+r)/2;
            if(pos[mid]>k)
                r = mid;
            if(pos[mid]<=k)
                l = mid+1;
        }
        if(pos[l]>k)
            return l;
        else
            return -1;
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>>pos;
        int res = 0;
        for(int i= 0;i<26;i++){//只有26个英文小写字母
            vector<int>v;
            pos.push_back(v);
        }
        for(int i = 0;i<S.size();i++){
            pos[S[i]-'a'].push_back(i);
        }
        for(int i =0;i<words.size();i++){
            bool flag = true;
            int k = -1;//k表示上一个字母的下标，下一个字母的下标必须大于k
            for(int j = 0;j<words[i].size();j++){
                k = search(pos[words[i][j]-'a'], k);//二分查找
                if(k<0){//说明下标数组中找不到比k大的下标了，该字符串不是S的子序列
                    flag = false;
                    break;
                }
                k = pos[words[i][j]-'a'][k];//更新k
            }
            if(flag)//说明该字符串是S的子序列
                res += 1;
        }
        return res;
    }
};