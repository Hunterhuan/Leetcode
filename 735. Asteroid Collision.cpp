// 很明显的stack题
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.empty()){
            return {};
        }
        vector<int> s;
        s.emplace_back(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            bool exploded = false;
            // while 里面的条件就是会发生碰撞
            while(s.size()>0&&s.back()>0&&asteroids[i]<0){
                int t = s.back();
                int t1 = -asteroids[i];
                if(t1>t){
                    // stack最后一个呗撞毁
                    s.pop_back();
                }
                else if(t1==t){
                    // 如果等于，全部报废
                    s.pop_back();
                    exploded = true;
                    break;
                }
                else{
                    // 这个被毁坏
                    exploded = true;
                    break;
                }
            }
            if(!exploded){
                // 没有毁坏的话，把这个push进去
                s.emplace_back(asteroids[i]);
            }
        }
        return s;
        
    }
};