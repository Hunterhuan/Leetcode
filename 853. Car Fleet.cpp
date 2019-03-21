// 自己的方法没用到stack
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 0)
            return 0;
        if(position.size() == 1)
            return 1;
        map<int,double> m;
        for(int i=0;i<position.size();++i)
            m[position[i]] = double(target-position[i])/speed[i];
        sort(position.begin(), position.end());
        int res = 0;
        double last_time = 0;
        for(int i = position.size()-1;i >=0;--i){
            if(m[position[i]] > last_time){
                last_time = m[position[i]];
                ++res;
            }
        }
        return res;
    }
};

// 别人牛逼。
class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        map<int, double> m;
        for (int i = 0; i < pos.size(); i++) m[-pos[i]] = (double)(target - pos[i]) / speed[i];
        int res = 0; double cur = 0;
        for (auto it : m) if (it.second > cur) cur = it.second, res++;
        return res;
    }
};