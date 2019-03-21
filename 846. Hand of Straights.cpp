// 练习一下如何使用map，挺有用的一道题。另外得记住c++新版和老版的map接口不太一样。
class Solution {
public:
    bool findone(map<int, int> &m, int W){
        map<int, int>::iterator iter = m.begin();
        int start = iter->first;
        for(int i=0;i<W;++i){
            iter = m.find(start);
            if(iter==m.end())
                return false;
            iter->second -= 1;
            if(iter->second==0)
                m.erase(iter);
            start++;
        }
        return true;
    }
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size() % W) return false;
        sort(hand.begin(), hand.end());
        map<int, int> m;
        for(auto n : hand)
            m[n] += 1;
        int times = hand.size()/W;
        int cnt = 0;
        while(cnt<times){
            if(findone(m, W)==false)
                return false;
            cnt++;
        }
        return true;
    }
};