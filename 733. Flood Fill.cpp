/*
分析：一个二维数组，给定一个起始位置，将所有与起始位置相连的相同的元素改变成要求的值。
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(!image.size()) return vector<vector<int>> ();
        int tag = image[sr][sc];
        if(tag==newColor) return image;//这里没有使用visited数组去标识是否已经被访问过，直接使用当前点的值和目标值对比去判断是不是访问过所以需要防止目标值和当前值一样的特例
        dfs(image,sr,sc,newColor,tag);
        return image;
    }

    void dfs(vector<vector<int>>& image, int i, int j, int newColor,int tag) {
    	image[i][j] = newColor;
    	if(i-1>=0&&image[i-1][j]==tag) dfs(image,i-1,j,newColor,tag);
    	if(i+1<image.size()&&image[i+1][j]==tag) dfs(image,i+1,j,newColor,tag);
    	if(j-1>=0&&image[i][j-1]==tag) dfs(image,i,j-1,newColor,tag);
    	if(j+1<image[0].size()&&image[i][j+1]==tag) dfs(image,i,j+1,newColor,tag);
    }
};



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(newColor == oldColor) return image;
        queue<pair<int,int>> q;
        q.push(make_pair(sr, sc));
        while(!q.empty()){
            tie(sr, sc) = q.front();
            q.pop();
            image[sr][sc] = newColor;
            if(sr > 0 && image[sr-1][sc] == oldColor){
                q.push(make_pair(sr-1,sc));
            }
            if(sr < image.size() - 1 && image[sr+1][sc] == oldColor){
                q.push(make_pair(sr+1,sc));
            }
            if(sc > 0 && image[sr][sc-1] == oldColor){
                q.push(make_pair(sr,sc-1));
            }
            if(sc < image[0].size() - 1 && image[sr][sc+1] == oldColor){
                q.push(make_pair(sr,sc+1));
            }

        }
        return image;
    }
};