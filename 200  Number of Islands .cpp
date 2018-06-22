/*
分析：求有多少个孤岛  孤岛的周围必须全部是水
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()) return 0;
        int res = 0;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));

        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j)
                res += dfs(grid,i,j,visited);
        }
        return res;
    }

    bool dfs(vector<vector<char>>& grid,int x,int y,vector<vector<int>>& visited) {
        if(visited[x][y]||grid[x][y]=='0') return false;
        visited[x][y] = 1;
        if(x-1>=0&&grid[x-1][y]=='1') dfs(grid,x-1,y,visited);
        if(x+1<grid.size()&&grid[x+1][y]=='1') dfs(grid,x+1,y,visited);
        if(y-1>=0&&grid[x][y-1]=='1') dfs(grid,x,y-1,visited);
        if(y+1<grid[0].size()&&grid[x][y+1]=='1') dfs(grid,x,y+1,visited);
        return true;
    }
};