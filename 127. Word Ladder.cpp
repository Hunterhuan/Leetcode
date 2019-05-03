class Solution {
public:
    bool diff(string & a, string &b){
        if(a.size()!=b.size())
            return false;
        int len = a.size();
        int count = 0;
        for(int i=0;i<len;++i){
            if(a[i]!=b[i])
                ++count;
        }
        return count==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        vector<int> dist(len, INT_MAX);
        int index = -1;
        for(int i=0;i<len;++i){
            if(wordList[i]==endWord){
                index = i;
                break;
            }
        }
        if(index==-1)
            return 0;
        dist[index] = 1;
        queue<int> q;
        q.push(index);
        int cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            //cout<<wordList[cur]<<endl;
            if(diff(wordList[cur], beginWord))
                return dist[cur]+1;
            for(int i=0;i<len;++i){
                if(dist[i]!=INT_MAX)
                    continue;
                //cout<<wordList[i]<<' '<<wordList[cur]<<endl;
                if(diff(wordList[i], wordList[cur])){
                    q.push(i);
                    dist[i] = dist[cur]+1;
                }
            }
        }
        return 0;
    }
};