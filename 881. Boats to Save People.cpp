
// 自己写的， time limit 难受
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // people = {3,2,3,2,2};
        // limit = 6;
        vector<bool> visited(people.size(), false);
        sort(people.begin(), people.end());
        int count = people.size();
        int res = 0;
        while(count){
            int tmp = limit;
            int cnt = 0;
            for(int i=people.size()-1; i>=0; --i){
                if(people[i] <= tmp && visited[i]==false){
                    --count;
                    visited[i] = true;
                    tmp -= people[i];
                    ++cnt;
                }
                if(cnt>=2)
                    break;
            }
            ++res;
        }
        return res;
    }
};
// 因为限制了2个
// 所以最大和最小组合就可以了。那么sort之后，用双指针从两段向中间运行就可以了
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0, r = people.size()-1;
        sort(people.begin(), people.end());
        int res = 0;
        while(l <= r){
            if(people[l] + people[r] > limit)
                --r;
            else{
                ++l;
                --r;
            }
            ++res;
        }
        return res;
    }
};