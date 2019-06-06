/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_set<int> s;
        unordered_map<int, int> m1;
        unordered_map<int, vector<int>> m2;
        int res = 0;
        queue<int> q;
        q.push(id);
        for(auto e:employees){
            m1[e->id] = e->importance;
            m2[e->id] = e->subordinates;
        }
        while(!q.empty()){
            int n = q.front();
            q.pop();
            res += m1[n];
            auto list = m2[n];
            for(int i=0;i<list.size();++i){
                q.push(list[i]);
            }
        }
        return res;
    }
};