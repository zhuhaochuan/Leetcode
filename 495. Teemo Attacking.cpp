/*
分析：给出中毒的时间点 立即中毒
给出中毒的持续时间
输出中毒的时间总长度
[1,2], 2
遍历整个数组
如果当前元素的值减去前一个元素的值得差小于2就sum加上差
否则sum加上2
 */


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(!timeSeries.size()) return 0;
        int len = timeSeries.size();
        if(len==1) return duration;
        int sum = 0;
        for(int i=1;i<len;i++) {
        	if(timeSeries[i]-timeSeries[i-1]<duration)
        		sum += timeSeries[i] - timeSeries[i-1];
        	else
        		sum += duration;
        }
        return sum + duration;
    }
};


class Solution {
public:
    int findPosisonedDuration(vector<int>& ts, int duration) {
        int tp = 0, pe = 0;
        for(int i=0; i<ts.size(); ++i){
            tp += duration - (ts[i] < pe) *(pe - ts[i]);
            pe = ts[i] + duration;
        }
        return tp;
    }
};