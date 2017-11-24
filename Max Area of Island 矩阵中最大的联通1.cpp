/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 */


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 1) ans = max(ans, dfs(grid, i, j));//当前结点的值为1才深度优先遍历
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), area = 1;//一旦进入 因为当前结点的值为1 首先将其对应的area设为1
        grid[row][col] = 0;//将这个点的值设为2 因为这个点已经被处理过了  

        vector<int> dir({-1,0,1,0,-1});//这是一个巧妙的设置遍历上下左右的点的方式 减少代码书写
        for (int i = 0; i < 4; i++) {
            int r = row+dir[i], c = col+dir[i+1];//依次遍历当前处理结点的上，右，下，左四个点
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) //结点在范围内 且该节点的值为1 排除所有为0的点以及访问过的点 避免重复
                area += dfs(grid, r, c);
        }
        return area;
    }
};

