/*
分析：还是买卖股票的问题
可以无限次买卖股票，但是每次买卖股票需要交纳一个固定的税
每次买股票之前必须在之前已经将之前持有的股票卖出
求解最大的收益
prices = [1, 3, 2, 8, 4, 9], fee = 2

一开始没有解题的思路，暴力解有点太蠢了非常的不适合这样的题目。
对于每一天有三种可能：买入，卖出，或者什么都不做
使用一个数组是没办法表示这几种可能的情况，因为今天做什么也需要取决于前一天的情况而定
使用hold[i]表示第i天持有股票所能获得的最大收益，sell[i]表示第i天不持有股票所能获得的最大收益。
具体分析：
第i天持有股票有两种情况，1：这一天什么都不做，保持前一天的持有状态。2：前一天已经是不持有状态，今天买入price[i]
所以hold[i]为两种情况的最大值：hold[i] = max(hold[i-1],sell[i-1] - princ[i])
第i天不持有也分为两种情况：1：这一天什么都不做，保持前一天不持有的状态。2：前一天已经是持有状态，今天卖出price[i]
sell[i] = max(sell[i-1],hold[i-1] + prince[i] - fee)
最终可以获得的最大收益为max(hold[n-1],sell[n-1])
 */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()<2) return 0;
        int n = prince.size();
        vector<int> hold(n-1,0),sell(n-1,0);
        hold[0] = -prince[0];
        for(int i=1;i<n;++i) {
        	hold[i] = max(hold[i-1],sell[i-1] - princ[i]);
        	sell[i] = max(sell[i-1],hold[i-1] + prince[i] - fee);
        }
        return max(hold[n-1],sell[n-1]);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0, s1 = -50010;
        for(int p:prices) {
            s0 = max(s0, s1+p-fee);
            s1 = max(s1, s0-p);
        }
        return s0;
    }
};




