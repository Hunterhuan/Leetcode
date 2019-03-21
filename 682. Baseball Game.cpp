class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        stack<int> s;
        for(int i=0;i<ops.size();++i){
            if(ops[i]=="+"){
                int tmp1 = s.top();
                s.pop();
                int tmp2 = s.top();
                s.push(tmp1);
                res += tmp1+tmp2;
                s.push(tmp1+tmp2);
            }
            else if(ops[i]=="D"){
                s.push(s.top()*2);
                res += s.top();
            }
            else if(ops[i]=="C"){
                res -= s.top();
                s.pop();
            }
            else{
                int tmp = stoi(ops[i]);
                res += tmp;
                s.push(tmp);
            }
        }
        return res;
    }
};