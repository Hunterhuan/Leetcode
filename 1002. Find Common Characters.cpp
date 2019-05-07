class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        std::vector<vector<int>> charToCountMap(26, vector<int>(A.size(), 0));
        for (int i=0; i<A.size(); i++) {
            for (const auto& ch : A[i]) {
                charToCountMap[ch - 'a'][i] += 1;
            }
        }

        vector<string> commonCharsVec;
        for (int i=0; i<26; i++) {
            int minCharVals = *std::min_element(charToCountMap[i].begin(), charToCountMap[i].end());
            for (int j=0; j<minCharVals; j++) {
                commonCharsVec.push_back(std::string(1, char('a'+i)));
            }
        }

        return commonCharsVec;
    }
};