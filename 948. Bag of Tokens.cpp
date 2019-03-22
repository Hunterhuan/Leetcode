// 占用空间很少，但是效率比较低
// 可以看看别人的solution
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        //tokens = {100};
        //P = 50;
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size()-1;
        int points = 0, ans = 0;
        while(l<=r){
            if(P>=tokens[l]){
                cout<<P<<endl;
                P-=tokens[l];
                ++l;
                points++;
            }
            else if(points>=1){
                if(l==r)
                    break;
                cout<<P<<endl;
                P += tokens[r];
                --r;
                --points;
                
            }
            else
                break;
        }
        return points;
    }
};