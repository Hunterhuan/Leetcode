// solution1: optimized iterative
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& p, auto& q) {return p[1] < q[1];});
        int time = 0, count = 0;
        int n = courses.size();
        for(int i=0;i<n;++i){
            // 可以开课
            if(time + courses[i][0] <= courses[i][1]){
                time += courses[i][0];
                courses[count++] = courses[i];
            }else{
                // 冲突的话，就向前回溯找到t最长的
                int max_i = i;
                for(int j=0;j<count;++j){
                    if(courses[j][0] > courses[max_i][0])
                        max_i = j;
                }
                // 把时间最长的，变成i，等于是腾出来更多的时间
                if(courses[max_i][0] > courses[i][0]){
                    time += courses[i][0] - courses[max_i][0];
                    courses[max_i] = courses[i];
                }
            }
        }
        return count;
    }
};


// solution2: pq
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& p, auto& q) {return p[1] < q[1];});
        priority_queue<int> q;
        int sum = 0;
        for (auto& c : courses) {
            q.push(c[0]);
            sum += c[0];
            if (sum > c[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};