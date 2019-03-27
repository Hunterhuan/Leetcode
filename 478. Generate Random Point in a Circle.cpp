#include <stdlib.h>
class Solution {
public:
    double x, r, y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        int pos = (rand()&3);
        //cout<<pos<<endl;
        double tmp_x,tmp_y;
        while(true){
            tmp_x = double(rand()%1000)/1000;
            cout<<tmp_x;
            tmp_y = double(rand()%1000)/1000;
            if(tmp_x*tmp_x+tmp_y*tmp_y<=1)
                break;
        }
        //cout<<tmp_x<<tmp_y<<endl;
        switch(pos){
            case 0:
                return {x-r*tmp_x,y-r*tmp_y};
            case 1:
                return {x+r*tmp_x,y-r*tmp_y};
            case 2:
                return {x-r*tmp_x,y+r*tmp_y};
            case 3:
                return {x+r*tmp_x,y+r*tmp_y};
        }
        return {0,0};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */