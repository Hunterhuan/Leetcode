class Solution {

    // This class could be used for both group-level sort and item-level sort.
    class Topo {
        unordered_set<int> nodes;
        unordered_map<int, int> in_degree;
        unordered_map<int, vector<int>> out_nodes;
        
    public:
        void AddNode(int node) {
            nodes.insert(node);
        }
        
        void AddEdge(int from, int to) {
            AddNode(from), AddNode(to);
            in_degree[to] ++;
            out_nodes[from].push_back(to);
        }
        
        unique_ptr<vector<int>> Sort() {
            queue<int> q;
            unique_ptr<vector<int>> order(make_unique<vector<int>>());
            
            // BFS starting from nodes with [in_degree=0].
            for (int node : nodes) if (!in_degree[node]) q.push(node);
            while (!q.empty()) {
                order->push_back(q.front());
                int node = q.front(); q.pop();
                for (int next : out_nodes[node]) 
                    if (!--in_degree[next]) q.push(next);
            }
            
            // Return a nullptr if the graph cannot be sorted.
            if (order->size() < nodes.size()) return nullptr;
            return order;
        }
    };
    
public:
    vector<int> sortItems(int n, int m, vector<int>& group_id, vector<vector<int>>& beforeItems) {
        // For non-group items, add them to their own unique groups.
        for (int i=0; i<n; i++) if (group_id[i] == -1) group_id[i] = m++;
        
        // Initialize group-level graph.
        Topo all_groups;
        for (int i=0; i<m; i++) all_groups.AddNode(i);
        
        // Initialize item-level graphs.
        vector<Topo> groups(m);
        for (int i=0; i<n; i++) groups[group_id[i]].AddNode(i);
        
        // Add group-level edges and item-level edges.
        for (int i=0; i<n; i++)
            for (int j : beforeItems[i])
                if (group_id[i] == group_id[j]) 
                    groups[group_id[i]].AddEdge(j, i);
                else
                    all_groups.AddEdge(group_id[j], group_id[i]);
        
        vector<int> items;
        
        // Sort all groups.
        unique_ptr<vector<int>> group_order(all_groups.Sort());
        if (!group_order) return {};
        
        // Sort all items for each group.
        for (int i : *group_order) {
            unique_ptr<vector<int>> item_order(groups[i].Sort());
            if (!item_order) return {};
            for (int item : *item_order) items.push_back(item);
        }
        
        return items;
    }
};