class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> vec[N];
        int flag[N]={0};
        for(int i=0;i<trust.size();i++)
        {
            int k=trust[i][0];
            int j=trust[i][1];
            if(find(vec[j-1].begin(),vec[j-1].end(),k)==vec[j-1].end())
            {
                flag[k-1]=1;
                vec[j-1].push_back(k);
            }
        }
        for(int i=0;i<N;i++)
        {
            if(vec[i].size()==N-1&&flag[i]==0) return i+1;
        }
        return -1;
    }
};