//分析：给出一个二维矩阵，从左到右升序排序
//从上到下升序排序
//找到目标元素是否存在
//[[1,2,3,4,5],
//[6,7,8,9,10],
//[11,12,13,14,15],
//[16,17,18,19,20],
//[21,22,23,24,25]]


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int m = matrix.size()-1,n = matrix[0].size()-1;
        return find(matrix,target,0,0,m,n);
    }
    bool find(vector<vector<int>>& matrix, int target,int x1,int y1,int x2,int y2) {
        if(max(x1,x2)>=matrix.size()||max(y1,y2)>=matrix[0].size()) return false;
    	int mid_m = x1 + (x2-x1)/2,mid_n = y1 + (y2-y1)/2;

    	if(x1>=x2&&y1>=y2&&matrix[mid_m][mid_n]!=target) return false;
    	if(matrix[mid_m][mid_n]==target) return true;
    	else if(matrix[mid_m][mid_n]>target) {
    		return find(matrix,target,x1,y1,mid_m,mid_n)||find(matrix,target,x1,mid_n+1,mid_m,y2)||find(matrix,target,mid_m+1,y1,x2,mid_n);
    	}
    	else {
    		return find(matrix,target,x1,mid_n+1,mid_m,y2)||find(matrix,target,mid_m+1,y1,x2,mid_n)||find(matrix,target,mid_m+1,mid_n+1,x2,y2);
    	}
    }
};






class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.size() == 0) return false;

        int i,j,rows = matrix.size(),cols = matrix[0].size();

        i = 0;
        j = cols-1;
        while(i < rows && j >= 0)
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};