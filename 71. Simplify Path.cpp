// 很简明的思路，就是效率略低。
// 如果使用string的内置函数的话效率应该会高一些。
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ss;
        for(int i=0; i<path.size();){
            while(i < path.size() && path[i] == '/') ++i;
            string s = "";
            while(i < path.size() && path[i] != '/')
                  s += path[i++];
            if(".." == s && !ss.empty())
                ss.pop();
            else if(s != "" && s!= "." && s!="..")
                ss.push(s);
        }
        string s = "";
        while(!ss.empty()){
            s = "/" + ss.top() + s;
            ss.pop();
        }
        if(s.size()==0)
            return "/";
        return s;
    }
};