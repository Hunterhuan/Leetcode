class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		int len = points.size();
		if (len == 0)
			return 0;
		int res = 0;
		for (int i = 0; i < len; i++) {
			unordered_map<double, int>solpeMap;
			int maxCount = 0;//保存slopeMap中最大的值
			int sameCount = 0;//记录和points[i]相同的点的个数
			for (int j = 0; j != i && j < len; j++) {
				if (points[i] == points[j])
					sameCount++;//更新和points[i]相同点的个数，相同点无法计算斜率
				else {
					int count = ++solpeMap[slope(points[i], points[j])];
					maxCount = max(count, maxCount);
				}
			}
			maxCount += sameCount;//和points[i]斜率相同的点的个数
								 //等于斜率相同的点个数和
								 //与points[i]相同的点个数相加
			res = max(res, maxCount);//更新res
		}
		return res + 1;//要加上本身点
	}
	//计算两点斜率
	double slope(vector<int>&p1, vector<int>&p2) {
		if (p1[0] == p2[0])
			return DBL_MAX;//两点在垂直线上，设定斜率为double最大值
		return ((double)p1[1] - p2[1]) / (p1[0] - p2[0]);
	}
};