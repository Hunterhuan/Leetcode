// 生成合法的括号组合，用递归。
class Solution {
public:
    void generate(int leftNum,int rightNum,string s,vector<string> &result)  
    {  
        if(leftNum==0&&rightNum==0)  
        {
            result.push_back(s);  
        }
        if(leftNum>0)  
        {
            generate(leftNum-1,rightNum,s+'(',result);  
        }  
        if(rightNum>0 && leftNum<rightNum)
        {
            generate(leftNum,rightNum-1,s+')',result);  
        }
}
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,n,"",res);
        return res;
    }
};