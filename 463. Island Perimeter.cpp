//分析：一个单元所贡献的边长 由四周的情况所决定
//如果 某个方向的值为0 则这条边需要被计算
//如果 这个方向的值为1 则这条边不需要计算

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(!grid.size()) return 0;
        int sum = 0;
        //遍历所有的点 
        for(int i=0;i<grid.size();i++) {
        	for(int j=0;j<grid[0].size();j++){
        		if(grid[i][j]==0)
        			continue;
        		else {
        			sum += len(i,j,grid);
        		}
        	}
        }
        return sum;
    }
    int len(int i,int j,vector<vector<int>>& grid);
};

//计算当前点的边 算法很简单 
int Solution::len(int i,int j,vector<vector<int>>& grid) {
	int ans = 0;
	if(j-1>=0&&!grid[i][j-1]||j==0)
		ans++;
	if(i-1>=0&&!grid[i-1][j]||i==0)
		ans++;
	if(j+1<grid[0].size()&&!grid[i][j+1]||j+1==grid[0].size())
		ans++;
	if(i+1<grid.size()&&!grid[i+1][j]||i+1==grid.size())
		ans++;
	return ans;
}

//别人更快的算法 
//计算有多少个1的点 每个点边数最大化 再减去重复的边的个数
//定义每个点的相邻的点是右，下这两个方向 ，因为是从左上方从上往下遍历这样不会出现重复计算相邻的点
//每一个相邻的点将多计算两条边 
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0, neighbours = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    islands++;
                    if (i < m - 1 && grid[i + 1][j] == 1) neighbours++;
                    if (j < n - 1 && grid[i][j + 1] == 1) neighbours++;
                }
        return islands * 4 - neighbours * 2;
    }
};