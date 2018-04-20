/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };分析：删除一些区间 使得剩下的区间不包含重合区间
 * 求解删除的最小的数量
 *  [ [1,2], [2,3], [3,4], [1,3] ]
 *  如果一个区间只是横跨一个区间说明可以删
 *  如果一个区间横跨多个区间必须删？
 *  是否需要先对区间排序？
 *  [ [1,2], [1,3], [2,3], [3,4] ]
 *  任何一个区间都有起始和终止点
 *  多个相同起始点的只能保存一个最短区间
 *  [ [1,2], [1,3], [2,5], [3,4] ,[4,6]]
 *目标是删除最少。。。那也就是留下最多的区间
 *越小的区间留下的可能性更大
 *按照长度排序？
 */
//我的想法是按照start排序 维持每一次的end最小 使得后面进来的间隔冲突的可能性降低
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
    	int n = intervals.size();
    	if(n<=1) return 0;
    	sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval& b) {
    		if(a.start<b.start)
    			return true;
    		else return false;
    	});
    	int res = 0;
    	Interval pre = intervals[0];
    	for(int i=1;i<n;++i) {
    		if(intervals[i].start == pre.start) {
    			pre = intervals[i].end < pre.end ?intervals[i]:pre;
    			++res;
    		}
    		else if(intervals[i].start<pre.end&&intervals[i].end>=pre.end)
    			++res;
            else if(intervals[i].start<pre.end&&intervals[i].end<pre.end) {
                ++res;
                pre = intervals[i];
            }
    		else
    			pre = intervals[i];
    	}
    	return res;
    }
};


//按照end排序更巧妙
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval& a, const Interval& b) {return a.end < b.end;};
        sort(intervals.begin(), intervals.end(), comp);
        int end = INT_MIN, ans = 0;
        for (auto i : intervals) {
            if (i.start < end)
                ans++;
            else
                end = i.end;
        }
        return ans;
    }
};