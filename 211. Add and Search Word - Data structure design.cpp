class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        bool isEnd;
        TrieNode* child[26];
    };
    
    TrieNode* getNode(){
        TrieNode* temp = new TrieNode;
        temp->isEnd = false;
        for(int i=0;i<26;i++){
            temp->child[i]=NULL;
        }
        return temp;
    }
    
    TrieNode* root;
    
    WordDictionary() {
        root = getNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n= word.length();
        TrieNode* pCrawl = root;
        for(int i=0;i<n;i++){
            int idx = word[i]-'a';
            if(!pCrawl->child[idx])
                pCrawl->child[idx] = getNode();
            pCrawl = pCrawl->child[idx];
        }
        pCrawl->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchUtil(TrieNode*cNode, string word,int i,int n){
        if(i==n){
            return cNode->isEnd;
        }
        if(word[i]!='.'){
            int idx = word[i]-'a';
            if(cNode->child[idx] && searchUtil(cNode->child[idx],word,i+1,n))
                return true;
            return false;
        }
        else{
            for(int idx = 0;idx<26;idx++){
                if(cNode->child[idx] && searchUtil(cNode->child[idx],word,i+1,n))
                    return true;
            }
            return false;
        }
    }
    
    bool search(string word) {
        int n= word.length();
        return searchUtil(root,word,0,n);
    }
    
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */