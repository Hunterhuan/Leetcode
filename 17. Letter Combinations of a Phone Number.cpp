// 用队列做
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        if(digits.size()==0)
            return res;
        for(auto c:dict[digits[0]-'0'])
            q.push(dict[0]+c);
        for(int i=1;i<digits.size();++i){
            int s = q.size();
            int next = digits[i]-'0';
            for(int i=0;i<s;++i){
                for(auto c:dict[next]){
                    q.push(q.front()+c);
                }
                q.pop();
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

// 还可以用递归

class Solution {
public:
    string dic[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void makesstring(string digits,vector<string> &v,string s)
    {
        if(digits=="")
        {
            v.push_back(s);
            return;
        }
        char c=digits[0];
        int i=c-'0';
        digits=digits.substr(1,digits.size()-1);
        for(char w:dic[i])
        {
            makesstring(digits,v,s+w);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string tmp="";
        vector<string> res;
        if(digits.length()==0)
            return res;
        makesstring(digits,res,"");
        return res;
    }
};