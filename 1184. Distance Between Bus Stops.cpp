class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int a = max(start, destination), b = min(start, destination);
        int c = 0, d = 0;
        for(int i=0;i<distance.size();++i){
            if(i<b || i>= a)
                c += distance[i];
            else
                d += distance[i];
        }
        return min(c,d);
    }
};