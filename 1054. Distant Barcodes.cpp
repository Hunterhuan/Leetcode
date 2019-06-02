class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& bar) {
        unordered_map<int,int>m;
        int val=-1; // value most frequent
        int maxf=0; //  frequency of val
        
        for(int i=0;i<bar.size();i++){
            int aux = m[bar[i]]+1; 
            m[bar[i]] = aux;
            
            if(aux>maxf){
                maxf =aux;
                val = bar[i];
            }
        }
        
        //even then odd
        int n = bar.size();
        int pos = 0;//even positions
        vector<int>ans(n,0);
        
		//fill the value most frequent
        for(int i=0;i<maxf;i++){
            ans[pos]=val;
            pos+=2;
            if(pos>=n)pos=1;
        }

        m[val]=0;//value filled in the array, now his frecuency is 0
 
        for(unordered_map<int,int>::iterator it= m.begin();it!=m.end();it++){
            for(int i=0;i<(*it).second;i++){
                ans[pos]=(*it).first;
                pos+=2;
                if(pos>=n)pos=1;//now check odd positions
            }
        }
        
        return ans;
    }
};