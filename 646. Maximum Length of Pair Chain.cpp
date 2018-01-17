/*
分析：给定一些pair 集合 将这些pair连成一个序列
每一个pair的第二个数都大于第一个数 只有当后一个pair的第一个数大于前一个pair的第二个数
才可以相连
最后要得到最大的长度 链的连接顺序没有要求
[[1,2], [2,3], [3,4]]

 */

//我的做法 先按照图的模型进行建模
//使用了有向图的临接矩阵的方式进行存储
//然后递归的去找寻以每一个节点的链的结尾的链长
//最后遍历这个数组最大的链长就是所求的
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = pairs.size();
        vector<vector<int>> dp(len,vector<int>(len));
        //int dp[len][len] = {};
        for(int i=0;i<len;i++) {
        	for(int j=0;j<len;j++) {
        		if(pairs[i][1]<pairs[j][0])
        			dp[i][j] = 1;
        	}
        }
        vector<int> d(len);
        for(int i=0;i<len;i++)
        	d[i] = DFS(i,d,dp,len);
        cout << d[2]<<endl;
        return *max_element(d.begin(),d.end());
    }

    int DFS(int i,vector<int>& d,vector<vector<int>>& dp,int len) {
    	if(d[i]) return d[i];
    	vector<int> v;
    	for(int j=0;j<len;j++) {
    		if(dp[j][i])
    			v.push_back(DFS(j,d,dp,len));
    	}
    	if(!v.size()) return 1;
    	else
    		return *max_element(v.begin(),v.end()) + 1;
    }
};//问题在于 有没有必要将所有的链接信息先存下来
//因为没有给原始的节点进行相应的排序
//所以很麻烦

//dp的方法
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = pairs.size();
        sort(pairs.begin(),pairs.end(),[](vector<int>& a,vector<int>& b) {
        	return a[0]<b[0];
        });//按照第一个元素从小到大进行排序 按照条件只有前面的才可以连接到当前的点
        int max = 0;
        vector<int> d(len,1);//全部初始化为1
        for(int i=0;i<len;i++) {
        	for(int j=0;j<i;j++) {
        		if(pairs[j][1]<pairs[i][0])
        			d[i] = d[j] + 1 > d[i] ? d[j] + 1 : d[i];
        	}
        	if(d[i]>max)
        		max = d[i];
        }
        return max;
    }
};

//非dp 并没有记忆化搜索 分析过程即可
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp = [](const vector<int>& a, const vector<int>&b){
            return a[0] < b[0];
        };
        sort(pairs.begin(), pairs.end(), cmp);
        int count = 0, end = INT_MIN;
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i][0] > end) {
                end = pairs[i][1];
                count++;
            }
            else if (pairs[i][1] < end){
                end = pairs[i][1];
            }
        }
        return count;
    }
};


