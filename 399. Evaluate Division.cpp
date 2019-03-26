// 关于graph的代码真的长，基本思路就是先建图，然后再
class Solution {
public:
    vector<double> calcEquation(
        vector<pair<string, string>> equations, 
        vector<double>& values, 
        vector<pair<string, string>> queries) 
    {
        unordered_map<string, unordered_map<string, double>> table;
        for (int i = 0; i < equations.size(); ++i) {
            string from = equations[i].first;
            string to = equations[i].second;
            
            table[from].insert(pair<string, double>(to, values[i]));
            table[to].insert(pair<string, double>(from, 1.0/values[i]));
        }

        vector<double> ret(queries.size(), 0.0);
        size_t i = 0;
        
        for (auto& q : queries) {
            unordered_set<string> visited;
            string from = q.first;
            string to = q.second;
            
            double t = dfs(from, to, table, visited, 1.0);
            ret[i++] = t == 0 ? -1.0 : t;
        }
        
        return ret;
    }
    
    double dfs(
        string from, string to,
        unordered_map<string, unordered_map<string, double>>& table,
        unordered_set<string>& visited,
        double carry) 
    {
        // if "visited" OR "the query string not in table"
        if (visited.find(from) != visited.end() || table.find(from) == table.end())
            return 0.0;
		// find a path, NOTE: this is not necessarily the shortest one
        if (from == to)
            return carry;
        
        // mark visited
        visited.insert(from);
        for (auto& link : table[from]) {
            double t = dfs(link.first, to, table, visited, carry*link.second);
            if (t != 0.0)
                return t;
        }
        // unmark visited
        visited.erase(from);

        return 0.0;
    }
};