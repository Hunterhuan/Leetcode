// 用位运算去当作26长度的list
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // Lengths
        int P = puzzles.size();
        int W = words.size();
        
        // Letter masks
        vector<int> letterMask(26, 0);
        
        for (int i = 0, mask = 1; i < 26; ++i, mask <<= 1) {
            letterMask[i] = mask;
        }
        
        // Word masks with count info
        unordered_map<int, int> wordsMask;
        
        // For each word
        for (int i = 0; i < W; ++i) {
            // Compute word mask
            int mask = 0;
            
            for (char c: words[i]) {
                mask = mask | letterMask[c - 'a'];
            }
            
            ++wordsMask[mask];
        }
       
         // Result : result[i] => number of words covered by puzzles[i]
        vector<int> result(P, 0); 
        
        // For each puzzle
        for (int i = 0; i < P; ++i) {
            // Compute puzzle mask
            int mask = 0;
            
            for (char c: puzzles[i]) {
                mask = mask | letterMask[c - 'a'];
            }
            
            // Iterate through all valid subset of mask i.e. subset of puzzle chars = 2^7 = 64 in count
            // This makes the complexity O(P*64)
            int subMask = mask;
            
            while (subMask) {
                if ((subMask & letterMask[puzzles[i][0] - 'a']) && wordsMask.count(subMask)) {
                    result[i] += wordsMask[subMask];
                }
                
                // Only select valid bits i.e. bits corresponding to chars in puzzle
                subMask = (subMask - 1) & mask;
            }
        }
        
        return result;
    }
};