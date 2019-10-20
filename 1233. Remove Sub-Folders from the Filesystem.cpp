class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        //sort by alphabetical order
        sort(folder.begin(),folder.end(),mycomp);
        
        //find the root folders        
        vector<string> ret;
        ret.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            if(folder[i].find(ret[ret.size()-1]+"/")==string::npos){
                ret.push_back(folder[i]);
            }
        }
        return ret;
    }
    static bool mycomp(string a, string b){
        return a<b;
    }
};