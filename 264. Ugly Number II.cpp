/*
分析：2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27
16 15
7 5 3
1 0 0

1 1 0
2 2 1

2 1 1
d[n] = dp[n-1]
1:只能被2整除
2:只能被3整除
3：只能被5整除
4：2，3
5：2，5
6：3，5
7：2，3，5
30
1 2 3 4 6 8 9 10 12
20 30 50
 */
//暴力解 超时。。。
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<0) return 0;
        if(n==1) return 1;
        vector<int> dp(n,0);
        map<int,int> table;
        dp[0] = 1;
        table[1] = 1;
        for(int i=1;i<n;++i) {
        	bool tag = false;
        	for(int j=1;j<=dp[i-1];++j) {
        		if(table[dp[i-1]+j]!=0) {
        			dp[i] = dp[i-1]+j;
        			tag = true;
                    ++table[dp[i-1]*2];
                    ++table[dp[i-1]*3];
                    ++table[dp[i-1]*5];
        			break;
        		}
        	}
        	if(!tag) {
        		dp[i] = 2 * dp[i-1];
                ++table[dp[i-1]*3];
                ++table[dp[i-1]*5];
            }
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<0) return 0;
        if(n==1) return 1;
        vector<int> dp;
        dp.push_back(1);
        for(int i=1;i<n;++i) {
        	int a = find(dp[i-1]/2,dp);
        	int b = find(dp[i-1]/3,dp);
        	int c = find(dp[i-1]/5,dp);

        	dp.push_back(min(min(a*2,b*3),c*5));
        }
        return dp[n-1];
    }

    int find(int tag,vector<int>& dp) {
        if(tag==0) return 1;
        int l = 0,r = dp.size()-1;
        while(l<=r) {//此处必须有相等！！！
            int mid = l + (r - l) / 2;
            if(dp[mid]<=tag)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return dp[l];
    }
};


//优化的方法 判断每次选取的是哪个 对应的下标 就加1非常皮
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp (n, 1);
        int a2 = 0, a3 = 0, a5 = 0;
        for (int i  = 1; i < n; ++i) {
            int d2 = 2 * dp[a2];
            int d3 = 3 * dp[a3];
            int d5 = 5 * dp[a5];
            dp[i] = min(d2, min(d3, d5));
            if (dp[i] == d2) a2++;
            if (dp[i] == d3) a3++;
            if (dp[i] == d5) a5++;
        }
        return dp[n-1];
    }
};