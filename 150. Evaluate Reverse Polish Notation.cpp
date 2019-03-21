// 效率不是很高。但是做的还是有条理性的
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();++i){
            if((tokens[i][0] >='0' && tokens[i][0]<='9') || tokens[i].size()>1){
                s.push(atoi(tokens[i].c_str()));
            }
            else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(tokens[i][0]=='+')
                    s.push(a+b);
                else if(tokens[i][0]=='-')
                    s.push(b-a);
                else if(tokens[i][0]=='*')
                    s.push(b*a);
                else if(tokens[i][0]=='/')
                    s.push(b/a);
            }
        }
        return s.top();
    }
};