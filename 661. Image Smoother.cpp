/*
分析：平滑一张图像，使得每个像素点的值为周围8个和自身的平均值

 */
//暴力解法。。对每一个点计算其周围每一个点的值。。。时间复杂度o(n*n)空间复杂度o(n*n)
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(!M.size()) return vector<vector<int>> ();
        int n = M.size(),m = M[0].size();
        vector<vector<int>> res(n,vector<int>(m,0));
        for(int i=0;i<n;++i) {
        	for(int j=0;j<m;++j)
        		res[i][j] = helper(M,i,j);
        }
        return res;
    }

    int helper(vector<vector<int>>& M,int i,int j) {
    	vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    	int res = 0,c = 0;
    	for(auto each : dir) {
    		int x = i + each[0],y = j + each[1];
    		if(x>=0&&x<M.size()&&y>=0&&y<M[0].size())
			{
				res += M[x][y];
				++c;
			}
    	}
    	return (res + M[i][j])/(c + 1);
    }
};


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int rows = M.size();
        int cols = M[0].size();
        vector<vector<int>> result = M;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                int sum = 0;
                bool row1 = false;
                bool row2 = false;
                bool col1 = false;
                bool col2 = false;
                sum += M[i][j];
                int number = 1;
                if(i + 1 < rows){
                    row2 = true;
                    sum += M[i + 1][j];
                    number++;
                }
                if(i - 1 >= 0){
                    row1 = true;
                    sum += M[i - 1][j];
                    number++;
                }
                if(j + 1 < cols){
                    col2 = true;
                    sum += M[i][j + 1];
                    number++;
                }
                if(j - 1 >= 0){
                    col1 = true;
                    sum += M[i][j - 1];
                    number++;
                }
                if(row1 && col1){
                    sum += M[i-1][j-1];
                    number++;
                }
                if(row1 && col2){
                    sum += M[i-1][j+1];
                    number++;
                }
                if(row2 && col1){
                    sum += M[i+1][j-1];
                    number++;
                }
                if(row2 && col2){
                    sum += M[i+1][j+1];
                    number++;
                }

                int avg = sum / number;
                result[i][j] = avg;
            }
        }
        return result;
    }
};