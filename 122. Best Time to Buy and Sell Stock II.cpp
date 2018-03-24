/*
分析：还是买卖股票问题，这是最近做到的第三个这类问题。
这次还是可以买卖多次，但是没有税。
这个问题的话就和之前的问题不是一个类型。
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int min = prices[0], max = -1, res = 0;
        for(int i=1;i<prices.size();++i) {
        	if(prices[i]<=prices[i-1]) {
        		res += prices[i-1] - min;
        		min = prices[i];
        		max = prices[i];
        	}
            else {
                if(prices[i]<min) min = prices[i];
	            if(prices[i]>max) max = prices[i];
                if(i==prices.size()-1)
                    res += max - min;
            }
        }
        return res;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if(m < 2)
            return 0;
        int ans = 0;
        int q = -prices[0];
        for(int i = 1; i < m; i++){
            int t = ans;
            ans = max(ans, q+prices[i]);
            q = max(q, t-prices[i]);
        }

        return ans;
    }
};

//足够的贪心！
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1]){
                totalProfit+=prices[i]-prices[i-1];
            }
        }
        return totalProfit;
    }
};