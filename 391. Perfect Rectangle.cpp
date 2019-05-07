class Solution {
public:
    
     
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int xl = numeric_limits<int>::max();
        int yl = numeric_limits<int>::max();
        int xh = numeric_limits<int>::min();
        int yh = numeric_limits<int>::min();
        int area = 0;
        if (rectangles.empty()) return false;
        vector<std::pair<int, int>> nodes;
        nodes.reserve(rectangles.size()*4);
        for (const auto rectangle: rectangles) {
            xl = min(xl, rectangle[0]);
            yl = min(yl, rectangle[1]);
            xh = max(xh, rectangle[2]);
            yh = max(yh, rectangle[3]);
            int area1 = (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
            nodes.push_back(make_pair(rectangle[0], rectangle[1]));
            nodes.push_back(make_pair(rectangle[2], rectangle[1]));
            nodes.push_back(make_pair(rectangle[2], rectangle[3]));
            nodes.push_back(make_pair(rectangle[0], rectangle[3]));
            area += area1;
        }
        if (area != (xh - xl) * (yh - yl)) return false;
        std::sort(nodes.begin(), nodes.end());
        std::pair<int, int> prevNode = (nodes[0]);
        int cnt = 1;
        bool prevNodeIsBoundary = (prevNode == make_pair(xl,yl) || prevNode == make_pair(xh, yl) || prevNode == make_pair(xh, yh) || prevNode == make_pair(xl, yh));
        for (size_t i = 1; i < nodes.size(); ++i) {
            if (nodes[i] == prevNode) {
                cnt++;
            } else {
                if ((prevNodeIsBoundary && cnt !=1) || (!prevNodeIsBoundary && cnt !=2 && cnt != 4)) {
                    return false;
                }
                cnt = 1;
                prevNode = nodes[i];
                prevNodeIsBoundary = (prevNode == make_pair(xl,yl) || prevNode == make_pair(xh, yl) || prevNode == make_pair(xh, yh) || prevNode == make_pair(xl, yh));
            }
         }
          return true;
    }
};