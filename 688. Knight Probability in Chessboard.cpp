/*
分析：要求从棋盘起始位置走k步还能停留在棋盘当中的概率。
其实就是求出走k步，还能留在棋盘上的可能路径总数。
如果一一枚举那么虽然棋盘上只有n*n个点但是路径总数将是指数级别的增长。

 */

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N,vector<double>(N,1));//这里的可能数是k的指数增长，所以肯定会超过int或者long long所以必须使用double
        vector<vector<int>> dir = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2}};
        for(int k=0;k<K;++k) {
        	vector<vector<double>> temp(N,vector<double>(N,0));
        	for(int i=0;i<N;++i) {
        		for(int j=0;j<N;++j) {
        			for(auto each : dir) {
        				int x = i + each[0];
        				int y = j + each[1];
        				if(x<0||x>=N||y<0||y>=N) continue;
        				temp[i][j] += dp[x][y];
        			}
        		}
        	}
        	dp = temp;
        }
        return dp[r][c]/pow(8,K);
    }
};


class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        const int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
        const int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
        vector<vector<double>> curr(N, vector<double>(N, 0.0)), next(N, vector<double>(N, 0.0));
        curr[r][c] = 1.0;

        for(int k=0;k<K;k++) {
            for(int x=0;x<N;x++)
            	for(int y=0;y<N;y++)
            		if(curr[x][y]>0) {
		                for(int i=0;i<8;i++) {
		                    int nx = x+dx[i], ny = y+dy[i];
		                    if(nx>=0&&nx<N&&ny>=0&&ny<N) {
		                        //cout << "add" << nx << " " << ny <<" " << next[nx][ny] << " " << curr[x][y]/8 << endl;
		                        next[nx][ny] += curr[x][y]/8;
		                    }
		                }
		            }

            swap(curr, next);
            for(int x=0;x<N;x++) for(int y=0;y<N;y++) {
                next[x][y] = 0.0;
            }
        }

        double res = 0.0;
        for(int x=0;x<N;x++)
        	for(int y=0;y<N;y++) {
            res += curr[x][y];
        }
        return res;
    }
};