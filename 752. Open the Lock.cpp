class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        q.push("0000");
        unordered_set<string> s;
        for(auto t:deadends){
            s.insert(t);
        }
        unordered_set<string> visited;
        if(target=="0000")
            return 0;
        int steps = 1;
        visited.insert("0000");
        if(s.count("0000"))
            return -1;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;++i){
                auto f = q.front();
                q.pop();
                for(int j=0;j<4;++j){
                    if(f[j]=='9')
                        f[j] = '0';
                    else
                        f[j]++;
                    if(f==target)
                        return steps;
                    if(!s.count(f) && !visited.count(f)){
                        q.push(f);
                        visited.insert(f);
                    }
                    if(f[j]=='0')
                        f[j] = '9';
                    else
                        f[j]--;
                    if(f[j]=='0')
                        f[j] = '9';
                    else
                        f[j]--;
                    if(f==target)
                        return steps;
                    if(!s.count(f) && !visited.count(f)){
                        q.push(f);
                        visited.insert(f);
                    }
                    if(f[j]=='9')
                        f[j] = '0';
                    else
                        f[j]++;
                }
            }
            ++steps;
        }
        return -1;
    }
};