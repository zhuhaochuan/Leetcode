/*
分析：数组当中出现次数最多的元素个数是这个数组的度
找到和原始数组度一样的最短的连续子数组
[1,2,2,3,1,4,2]

过程挺有意思，具体就是使用map保存信息，最后保存需要的结果
 */

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(!nums.size()) return 0;
        map<int,vector<int>> table;
        int res = 1,ans = 1;
        table[nums[0]] = vector<int> {0,1};
        for(int i=1;i<nums.size();++i) {
        	if(!table[nums[i]].size()) {
        		table[nums[i]].push_back(i);
        		table[nums[i]].push_back(1);
        	}
        	else
        		++table[nums[i]][1];
        	if(table[nums[i]][1]>=res) {
                if(table[nums[i]][1]==res)
                    ans =  i - table[nums[i]][0] + 1 < ans? i - table[nums[i]][0] + 1:ans;
                else
                    ans = i - table[nums[i]][0] + 1;
                res = table[nums[i]][1];
            }
        }
        return ans;
    }
};





