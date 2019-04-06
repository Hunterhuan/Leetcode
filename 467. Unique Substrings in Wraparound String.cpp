// 类似于之前的一道题。只不过这个还要去重
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> visited(26,0);
        int N = p.size();
        if(N==0)
            return 0;
        int last = 1;
        int sum = 0;
        visited[int(p[0]-'a')] = 1;
        int tmp = 0;
        for(int i=2;i<=N;++i){
            if(p[i-1]-p[i-2]==1 || p[i-1]-p[i-2]==-25){
                last += 1;
            }
            else
                last = 1;
            tmp = p[i-1]-'a';
            visited[tmp] = max(visited[tmp], last);
        }
        for(int i=0;i<26;++i)
            sum += visited[i];
        return sum;
    }
};