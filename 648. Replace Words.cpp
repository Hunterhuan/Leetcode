class Solution {
public:
    struct Node{
        vector<Node*> nodes = vector<Node*>(26);
        bool leaf = false;
    };
    
    void add(Node* n, const char* s){
        while (*s){
            if (!n->nodes[*s-'a'])
                n->nodes[*s-'a'] = new Node;
            
            n = n->nodes[*s-'a'];
            s++;
        }
        n->leaf = true;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        
        Node trie;
        for(string& s: dict)
            add(&trie, s.c_str());
        
        Node* node = &trie;
        string result, root, word;
        bool root_found = false;
        bool continue_search = true;
       
        for (char& c: sentence){
            if (c == ' '){
                result += root_found ? root: word;
             
                root.clear();
                word.clear();
                node = &trie;
                root_found = false;
                continue_search = true;
                result += ' ';
            }
            else{
                if (continue_search){
                    if (!root_found && node->nodes[c-'a']){
                        node = node->nodes[c-'a'];
                        if (node->leaf)
                            root_found = true;
                        root += c;
                    }
                    else
                        continue_search = false;
                }
                word += c;                
            }
        }
        result += root_found ? root: word;
        return result;
    }
};