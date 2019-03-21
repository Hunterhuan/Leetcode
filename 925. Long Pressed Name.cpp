// 这个也是双指针，不过一个指针在name中，一个指针在typed里面。
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = 0;
        for(int i=0;i<typed.size();++i){
            if(n==name.size()){
                if(typed[i]!=typed[i-1])
                    return false;
                continue;
            }
            if(typed[i] == name[n])
                ++n;
            else{
                if(typed[i]==name[n-1])
                    continue;
                else
                    return false;
            }
        }
        if(n==name.size())
            return true;
        return false;
    }
};