/*
分析：还是得保持看到一道题目先写分析的习惯
这道题目是给定一个数组 每个元素的每天股票的价格
每天可以买入和卖出 但是最多只能进行一次交易 也就是说只能买卖一次或者不进行交易
求得交易过程当中可以获得的最大价值
[7, 1, 5, 3, 6, 4]
显然需要遍历所有的元素才可以去确定这个最大的正差值是多少 时间复杂度至少是o(n)

 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int res = 0, min = INT_MAX;
        for(int i=0;i<prices.size();++i) {
        	if(prices[i]<min)
        		min = prices[i];
        	res = (prices[i] - min)>res?prices[i]-min:res;
        }
        return res;
    }
};