/*
分析：给出一组正整数组成的数组 找到最大的集合
集合当中的元素两两都可以有一个被另一个整除
大的数肯定不可以被小的数整除
找到最大的集合
1 2 4 3 6
nums: [1,2,4,8,9]
Result: [1,2,4,8]
[3,5,6,4,8,9,2,7]
[2,3,4,5,6,7,8,9]
9->3
8->4->2
7->
6->3
5->
4->2
3->
2->
dp[i] = max(dp[j]) + 1 j<i j能被i整除
这道题目的难点在于：需要排序将问题转化为标准dp
还要输出结果 在于保存信息
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	int n = nums.size();
    	if(n<2) return nums;
    	vector<int> dp(n,1);
    	int max_c = 0,c = 0;
    	sort(nums.begin(),nums.end());
    	map<int,vector<int>> table;//没有必要开一个数组去存放每一条路径。。只需要知道其父亲节点是谁就可

    	for(int i=0;i<n;++i) {
    		vector<int> v;
    		table[nums[i]].push_back(nums[i]);

    		for(int j=i-1;j>=0;--j) {
    			if(nums[i]%nums[j]==0) {
    				int t = dp[j] + 1;
    				if(t>dp[i]) {
    					v = table[nums[j]];
    					dp[i] = dp[j] + 1;
    				}
    			}
    			if(dp[i]>max_c) {
    				max_c = dp[i];
    				c = nums[i];
    			}
    		}
    		table[nums[i]].insert(table[nums[i]].end(),v.begin(),v.end());
    	}
        //cout << c << endl;
    	return table[c];
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        // if (nums.size()==0) return ans;
        sort(nums.begin(), nums.end());
        vector<int> parent(nums.size(), 0);
        int m_len = 0;
        int mi = 0;
        for (int i = nums.size()-1;i>=0;i--){
            for (int j=i;j<nums.size();j++){
                if (nums[j]%nums[i]==0 && dp[i]<1+dp[j]){
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                    if (dp[i]>m_len){
                        m_len = dp[i];
                        mi = i;
                    }
                }
            }
        }
        vector<int> ans;
        for (int i=0;i<m_len;i++){
            ans.push_back(nums[mi]);
            mi = parent[mi];
        }
        return ans;
    }
};
