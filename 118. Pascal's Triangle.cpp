/*
分析：建立一个杨辉三角形
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
每一个位置的元素是由其左上和右上元素的和构成的
 */

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows) return vector<vector<int>> ();
        vector<vector<int>> res;
        res.push_back(vector<int>{1});
        while(numRows>1) {
        	vector<int> temp(res.back().size()+1,0);
        	for(int i=0;i<temp.size();++i) 
        		temp[i] = (i-1>=0?res.back()[i-1]:0) + (i<res.back().size()?res.back()[i]:0);
        	res.push_back(temp);
            --numRows;
        }
        return res;
    }
};