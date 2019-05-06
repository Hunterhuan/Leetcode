class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(),deck.end());
        vector<int>v(n,-1); // mark empty slot by -1
        int count=0,i=0,j=0;
        while(j<n){
            v[i] = deck[j]; 
            j++;
            count = 0;
            while(j<n && count<2){  // skip next empty slot each time
                i = (i+1)%n;
                if(v[i]==-1){
                    count++;
                }
            }
        }
       return v; 
    }
};