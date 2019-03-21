// 自己写的。似乎有错误。自己没发现,就不debug了

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger tmp();
        int i = 0;
        for(i=0;i<s.size();++i){
            if(s[i]==',')
                continue;
            else if(s[i]=='['){
                int cnt = 0;
                int index = i;
                while(index<s.size()){
                    if(s[index++]=='[')
                        ++cnt;
                    if(s[index++]==']')
                        --cnt;
                    if(!cnt)
                        break;
                }
                tmp.add(deserialize(s.substr(i, index-i)));
                i = index-1;
            }
            else{
                int index = i;
                while(index < s.size()){
                    if(s[index++]==',')
                        break;
                }
                tmp.add(NestedInteger(stoi(s.substr(i,index-i))));
                i = index - 1;
            }
        }
        vetor<NestedInteger> l = tmp.getList();
        if(l.size()==1 && l[0].isInteger == true)
            return l[0];
        else
            return tmp;
    }
};
// 自己的从根源上出了问题。不应该以[] 传送string.
// 别人的solution。

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        if (s.size() <= 2) return NestedInteger();
        NestedInteger res;
        int start = 1, cnt = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (cnt == 0 && (s[i] == ',' || i == s.size() - 1)) {
                res.add(deserialize(s.substr(start, i - start)));
                start = i + 1;
            } else if (s[i] == '[') ++cnt;
            else if (s[i] == ']') --cnt;
        }
        return res;
    }
};