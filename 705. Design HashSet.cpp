class MyHashSet {
    vector<int> hash;
public:
    /** Initialize your data structure here. */
    MyHashSet() {}
    
    void add(int key) {
        if(hash.size() < key)   hash.resize(key + 100);
        hash[key] = 1;
    }
    
    void remove(int key) {
        if(hash.size() > key)   hash[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash.size() > key && hash[key];
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */