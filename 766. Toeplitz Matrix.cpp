/*
分析：判断一个矩阵的每一条对角线元素是否相等
1 1 1 1
1 1 1 1
1 1 1 1
i j
i+1 j+1
 */
static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0);return 0;}();
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(!matrix.size()) return true;
        for(int i=0;i<matrix.size();++i) {
            for(int j=0;j<matrix[0].size();++j)
                if(i+1<matrix.size()&&j+1<matrix[0].size()&&matrix[i][j]!=matrix[i+1][j+1])
                    return false;
        }
        return true;
    }
};


class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        if(rows <= 1) return true;
        int cols = matrix[0].size();
        if(cols <= 1) return true;
        for(int row = 1; row < rows; ++row)
        {
            for(int col = 1; col < cols; ++col)
            {
                int formerValue = matrix[row-1][col-1];
                int currentValue = matrix[row][col];
                if(currentValue != formerValue) return false;
            }
        }
        return true;
    }

};