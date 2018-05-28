//给出一些点的坐标，从中间选取3个点构成三角形，求解最大的三角形的面积

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3) return 0;
        double res = 0;
        for(int i=0;i<n;++i) {
        	for(int j=i+1;j<n;++j) {
        		for(int k=j+1;k<n;++k) {
        			double area = points[j][0]*points[k][1] + points[i][0]*points[j][1] + points[k][0]*points[i][1] - points[k][0]*points[j][1] - points[j][0]*points[i][1] - points[i][0]*points[k][1];
        			area = abs(area)*0.5;
        			res = max(area,res);
        		}
        	}
        }
        return res;
    }
};