/*
分析：平面上有一堆气球，最少发射多少根箭可以将所有的气球射穿
看成数轴上的一根一根线段，在线段相交最多的点进行截断，也就是求截断所有的线段所需的最少交点。
[[10,16], [2,8], [1,6], [7,12]]
 */

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(!points.size()) return 0;
        sort(points.begin(),points.end());
        int l = points[0].first,r = points[0].second,res = 1;
        for(int i=1;i<points.size();++i) {
        	if(points[i].first>r) {
        		++res;
        		l = points[i].first;
        		r = points[i].second;
        	}
        	else {
        		l = points[i].first;
                r = min(r,points[i].second);
        	}
        }
        return res;
    }
};