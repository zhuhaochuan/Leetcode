/*
分析：给出一个扫雷的矩阵，如果找到雷直接修改并且返回
如果找到空白就标记
 */
static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0);return 0;}();
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M') {
        	board[click[0]][click[1]] = 'X';
        	return board;
        }
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        dfs(board,click[0],click[1],dir);
        return board;
    }

    void dfs(vector<vector<char>>& board, int i,int j,vector<vector<int>>& dir) {
    	if(board[i][j]=='E') {
    		int tag = 0;
    		for(auto each : dir) {
    			if(i+each[0]>=0&&i+each[0]<board.size()&&j+each[1]>=0&&j+each[1]<board[0].size())
    				tag += find_M(board,i+each[0],j+each[1]);
    		}
    		if(tag)
    			board[i][j] = tag + '0';
    		else {
    			board[i][j] = 'B';
    			for(auto each : dir) {
	    			if(i+each[0]>=0&&i+each[0]<board.size()&&j+each[1]>=0&&j+each[1]<board[0].size())
	    				dfs(board,i+each[0],j+each[1],dir);
    			}
    		}
    	}
    }

    int find_M(vector<vector<char>>& board, int i,int j){
    	if(board[i][j]=='M')
    		return 1;
    	else return 0;
    }
};



static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
	void reveal(vector<vector<char>>& board, vector<vector<char>>& newBoard, int row, int col) const {
		int nRows = (int)board.size();
		if (row >= 0 && row < nRows) {
			int nCols = (int)board[0].size();
			if (col >= 0 && col < nCols) {
				if (newBoard[row][col] == 'E') {
					int nMines = 0;
					for (int i = max(0, row - 1); i < min(nRows, row + 2); ++i) {
						for (int j = max(0, col - 1); j < min(nCols, col + 2); ++j) {
							if (i != row || j != col) {
								if (newBoard[i][j] == 'M') {
									++nMines;
								}
							}
						}
					}
					if (nMines) {
						newBoard[row][col] = (char)(nMines + '0');
					}
					else {
						newBoard[row][col] = 'B';
						for (int i = max(0, row - 1); i < min(nRows, row + 2); ++i) {
							for (int j = max(0, col - 1); j < min(nCols, col + 2); ++j) {
								if (i != row || j != col) { reveal(board, newBoard, i, j); }
							}
						}
					}
				}
			}
		}
	};
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) const {
		vector<vector<char>>newBoard = board;
		int row = click[0], col = click[1];
		char underClick = board[row][col];
		if (underClick == 'M') { newBoard[row][col] = 'X'; }
		else { reveal(board, newBoard, row, col); }
		return newBoard;
	};
};