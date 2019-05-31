// 这道题感觉难点在于去重的处理上

class Solution {
public:
    bool isUsed(vector<int> &A, int start, int index){
        for(int i=start;i<index;i++)
            if(A[i]==A[index])
                return true;
        return false;
    }

    void backtracking(vector<vector<int>> &ans, vector<int>& A, vector<int> &curr, int index){
        // 如果出现一个ans，那就push
        if(curr.size()>1)
            ans.push_back(curr);
        // 没有了。就return
        if(index==A.size())
            return;
        
        // choices
        for(int i=index;i<A.size();i++){
            if(curr.size()>0 && A[i]<curr[curr.size()-1]) // next Smaller
                continue;
            // 重复的元素
            if(i>index && isUsed(A,index,i)) // repeating element
                continue;
            curr.push_back(A[i]);
            backtracking(ans,A,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& A) {
        vector<vector<int>> ans;
        vector<int> curr;
        // 调用回溯
        backtracking(ans,A,curr,0);
        //sort(ans.begin(),ans.end());
        return ans;
    }
};