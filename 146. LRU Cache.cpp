class LRUCache {
private:
    int n;
    list<pair<int,int> > lis;
    unordered_map<int,list<pair<int,int>>::iterator> m;
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        int ans = -1;
        if(it!=m.end())
        {
            ans = it->second->second;
            lis.erase(it->second);
            lis.push_front(make_pair(key,ans));
            it->second = lis.begin();
        }
        return ans;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it!=m.end())
        {
            lis.erase(it->second);
            lis.push_front(make_pair(key,value));
            m[key] = lis.begin();
        }
        else if(m.size()<n)
        {
            lis.push_front(make_pair(key,value));
            m[key] = lis.begin();
        }
        else
        {
            auto it = lis.end();
            it--;
            m.erase(it->first);
            lis.erase(it);
            lis.push_front(make_pair(key,value));
            it = lis.begin();
            m[key] = it;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */