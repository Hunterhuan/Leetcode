// 通过率很低。
// 个人觉得，关键在于 很多path可以到达某个节点，以及队列的入列可能会有重复的。
// 处理比较复杂。

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ladders;
        vector<string> ladder;
        ladder.push_back(beginWord); // 加入起点
        
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return ladders;
        words.erase(beginWord);
        words.erase(endWord);
        
        unordered_set<string> beginWords, endWords;
        beginWords.insert(beginWord);
        endWords.insert(endWord);
        unordered_map<string, vector<string>> paths;
        
        if (twoSidedBfs(beginWords, endWords, words, paths))
            dfs(beginWord, endWord, paths, ladder, ladders);
        
        return ladders;
    }
    
private:
    bool twoSidedBfs(unordered_set<string> &beginWords, unordered_set<string> &endWords, 
        unordered_set<string> &words, unordered_map<string, vector<string>> &paths) {
        unordered_set<string> *p1 = &beginWords, *p2 = &endWords;
        
        while (!p1->empty() && !p2->empty()) {
            if (p1->size() > p2->size())
                swap(p1, p2);

            unordered_set<string> tempWords;
            bool found = false; // 是否能在p2中找到单词
            for (string word : *p1) {
                string tempWord = word;
                for (int i = 0; i < word.size(); i++) {
                    char letter = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        
                        bool existsInP2 = p2->find(word) != p2->end();
                        bool existsInWords = words.find(word) != words.end();
                        if (existsInP2 || existsInWords) {
                            if (p1 == &beginWords)
                               paths[tempWord].push_back(word);
                            else
                               paths[word].push_back(tempWord);
                        }
                        if (existsInP2)
                            found = true; // 注意到没有在found=true的时候立刻返回，因为可能有多条最短路径
                        if (existsInWords)
                            // 不能在这里删除单词，否则会丢失一部分最短路径！
                            tempWords.insert(word);
                    }
                    word[i] = letter;
                }
            }
            
            if (found) return true;
            // 注意只能在遍历p1的循环外删除单词表的单词，因为可能有多条最短路径，所以每一层的单词允许有重复
            // 例如hit hot pot dot dit和hit hot hop dop dit，在第二层就有两个重复的hot
            for (string tempWord : tempWords)
                words.erase(tempWord);
            swap(*p1, tempWords);
        }
        return false;
    }
    
    void dfs(string beginWord, string endWord, unordered_map<string, vector<string>> &paths,
        vector<string> &ladder, vector<vector<string>> &ladders) {
        if (beginWord == endWord) {
            ladders.push_back(ladder);
            return;
        }
        for (const string &nodeWord : paths[beginWord]) {
            ladder.push_back(nodeWord);
            dfs(nodeWord, endWord, paths, ladder, ladders);
            ladder.pop_back();
        }
    }
};