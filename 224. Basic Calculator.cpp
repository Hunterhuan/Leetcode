class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<int> op;
        int i = 0;
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ')
                i ++;
            if(i == s.size())
                break;
            if(s[i] == '+' || s[i] == '-' || s[i] == '(')
            {
                op.push(s[i]);
                i ++;   
            }
            else if(s[i] == ')')
            {
                while(op.top() != '(')
                {// calculation within parentheses 
                    int n2 = num.top();
                    num.pop();
                    int n1 = num.top();
                    num.pop();
                    if(op.top() == '+')
                        num.push(n1 + n2);
                    else
                        num.push(n1 - n2);
                    op.pop();
                }
                op.pop();
                while(!op.empty() && op.top() != '(')
                {
                    int n2 = num.top();
                    num.pop();
                    int n1 = num.top();
                    num.pop();
                    if(op.top() == '+')
                        num.push(n1 + n2);
                    else
                        num.push(n1 - n2);
                    op.pop();
                }
                i ++;
            }
            else
            {
                int n = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9')
                {
                    n = n*10 + (s[i]-'0');
                    i ++;
                }
                num.push(n);
                while(!op.empty() && op.top() != '(')
                {
                    int n2 = num.top();
                    num.pop();
                    int n1 = num.top();
                    num.pop();
                    if(op.top() == '+')
                        num.push(n1 + n2);
                    else
                        num.push(n1 - n2);
                    op.pop();
                }
            }
        }
        return num.top();
    }
};