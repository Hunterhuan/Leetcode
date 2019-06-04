class MyHashMap {
    const int MAX_SIZE=9999;
    typedef list<pair<int,int> > LIST;
    vector<LIST> mArr;
private:
    int hashFunc(int key) {
        return key;
    }
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        mArr.resize(MAX_SIZE);
    }
    
    list<pair<int,int> >::iterator GetIter(const int &key, const int &hashedKey){
        LIST &l = mArr[hashedKey];
        for(LIST::iterator i = l.begin(); i!=l.end(); i++) {
            if(i->first == key) {
                return i;
            }
        }
        return l.end();
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashedKey = hashFunc(key) % MAX_SIZE;
        LIST::iterator i = GetIter(key,hashedKey);
        if(i != mArr[hashedKey].end())
            i->second = value;
        else
            mArr[hashedKey].push_back(make_pair(key,value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashedKey = hashFunc(key) % MAX_SIZE;
        LIST::iterator i = GetIter(key,hashedKey);
        if(i != mArr[hashedKey].end())
            return i->second;
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashedKey = hashFunc(key) % MAX_SIZE;
        LIST::iterator i = GetIter(key,hashedKey);
        if(i != mArr[hashedKey].end())
            mArr[hashedKey].erase(i);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */