class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxRes = 0;
        int pointsSize = (int)points.size();
        //S =  |(x1 · y2 - x2 · y1) + (x2 · y3 - x3 · y2) + (x3 · y1 - x1 · y3)| / 2
        for(int i = 0; i < pointsSize; i++) {
            for(int j = i + 1; j < pointsSize; j++) {
                for(int k = j + 1; k < pointsSize; k++) {
                    //三层循环，穷举三角形的三个坐标
                    maxRes = max(maxRes, abs(points[i][0] * points[j][1] + points[j][0] * points[k][1] + points[k][0] * points[i][1] - points[i][0] * points[k][1] - points[j][0] * points[i][1] - points[k][0] * points[j][1]) / 2.0);
                }
            }
        }
        return maxRes;
    }
};