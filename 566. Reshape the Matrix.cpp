/*
分析：按行的方式将原始的矩阵进行重新构建
nums.size()是原始矩阵的行数
nums[0].size()是原始矩阵的列数

如果原始的行数乘以列数 不等于 r*c
那么就是不合法的转换
否则合法

 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(!nums.size()) return nums;
        int row = nums.size();
        int col = nums[0].size();
        int cur_r = 0,cur_c = 0;
        vector<vector<int>> ans;

        if(row*col != r*c)
        	return nums;
        else {
        	for(int i=0;i<r;i++) {
        		vector<int> v;
        		for(int j=0;j<c;j++) {
        			int cur_i = cur_r,cur_j = cur_c;
        			if(cur_i<row) {
        				if(cur_j<col) {
        					v.push_back(nums[cur_i][cur_j]);
        					cur_c++;
                            if(cur_c==col)//原矩阵到行尾换行 列数归0
                                cur_c = 0;
        				}
                        if(cur_j==col-1)//下一行
        				    cur_r++;
        			}
        		}
        		ans.push_back(v);
        	}
        }
        return ans;
    }
};




class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        if(r*c != nums[0].size()*nums.size()) return nums;

        vector<vector<int>> res(r, vector<int>(c,0));
        //先将矩阵空间开好 会更快
        int nums_r = 0, nums_c = 0, res_r = 0, res_c = 0;

        while(res_r < r && nums_r < nums.size())
        {
            res[res_r][res_c] = nums[nums_r][nums_c];
            if(res_c == c-1)
            {
                res_r++;
                res_c=0;
            }
            else res_c++;

            if(nums_c == nums[0].size()-1)
            {
                nums_r++;
                nums_c=0;
            }
            else nums_c++;
        }

        return res;


    }
};


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size()*nums[0].size()!=r*c) return nums;

        int a1=nums.size();
        int a2=nums[0].size();
        vector<vector<int>>vec(r);

        for(int i=0;i<r;i++){
            vec[i].resize(c);
        }

        for(int i=0;i<r*c;i++){
            vec[i/c][i%c] = nums[i/a2][i%a2];//这个就是将两个矩阵每个元素的位置映射好
        }
        return vec;
    }
};



