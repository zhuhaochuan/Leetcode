/*
分析：含有冷却时间的股票交易最大利润问题：
卖出后的下一天不能买入。
对于第i天将会有三个状态可以买，可以卖，冷却状态
hold[i] = max(hold[i-1],unhold[i-2]-prices[i]);
unhold[i] = max(unhold[i-1],hold[i-1]+prices[i]);
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size()<2) return 0;
    	int n = prices.size();
        vector<int> hold(n,0),unhold(n,0);
        hold[0] = -prices[0];
        hold[1] = max(hold[0],-prices[1]);
        unhold[1] = max(unhold[0],hold[0]+prices[1]);
        for(int i=2;i<n;++i) {
        	hold[i] = max(hold[i-1],unhold[i-2]-prices[i]);
			unhold[i] = max(unhold[i-1],hold[i-1]+prices[i]);
        }
        return unhold[n-1];
    }
};