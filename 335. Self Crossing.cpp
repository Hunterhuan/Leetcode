class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if(x.size() < 4) return false;//少于四条绝对不相交
        if(x[2] <= x[0] && x[3] >= x[1])
            return true;//四条情况下，第三条与第一条相交
        if(x.size() > 4 && x[3] <= x[1] && x[4] >= x[2])
            return true;//五条情况下，最后一条与第二条相交
        if(x.size() > 4 && x[3] == x[1] && x[4] + x[0] >= x[2])
            return true;//五条情况下，最后一条与第一条重合相交
        for(int i = 5;i < x.size();i++){//多于五条之后，相交便呈现规律性变化
            if(x[i - 1] <= x[i - 3] && x[i] >= x[i - 2])
                return true;
            if(x[i - 1] <= x[i - 3] && x[i - 4] <= x[i - 2] && x[i] + x[i - 4] >= x[i - 2] && x[i - 5] + x[i - 1] >= x[i - 3])
                return true;
        }
        return false;
    }
};