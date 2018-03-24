/*
分析：给出一个矩阵表示每个人之间的直接相互关系，关系可以传递，如果这些人在一个圈子就组成一个group
需要得到group总数
这道题应该采用并查集。
并查集有3种常用的操作，创建集合，合并集合，找到代表元素，分别是make_set,union,find_set。
使用一个数组group()记录每一个人属于的集合
数组的下标表示这个人，group[i] 表示当前i属于的集合代表
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> header(n,0);
        int group = n;
        for(int i=0;i<n;++i) header[i] = i;
        for(int i=0;i<n;++i) {
        	for(int j=i+1;j<n;++j) {
        		if(M[i][j]) {
        			//整个过程就是union
        			int header_i = find(i,header);//先find_set
        			int header_j = find(j,header);
        			if(header_j!=header_i) {//再union
        				header[header_i] = header_j;
        				--group;
        			}
        		}
        	}
        }
        return group;
    }
    int find(int index, vector<int>& header) {
    	return header[index]==index?index:find(header[index],header);
    }
};



class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        // Union Find
        // 非常经典的Union Find，根据好友的传递关系，把所有人分成几个Set
        // 可以校验一下 M是否是对称矩阵，这里就不做了。
        vector<int> parent = build(M);
        int cnt = 0;
        for (int i = 0; i < parent.size(); i++) {
            // 别忘了没有朋友的人，自己也是一个cycle
            if (parent[i] == i || parent[i] == -1) cnt++;
        }
        return cnt;
    }
    int Find(vector<int> &parent, int i) {
        if (parent[i] == -1) parent[i] = i;
        if (parent[i] != i) parent[i] = Find(parent, parent[i]); // 路径压缩优化
        return parent[i];
    }
    void Union(vector<int> &parent, int x, int y) {
        int rootx = Find(parent, x);
        int rooty = Find(parent, y);
        if(rootx != rooty) parent[rootx] = rooty;        // 可以利用rank来优化
    }
    vector<int> build(const vector<vector<int>>& M) {
        vector<int> parent(M.size(), -1);  // 注意，要有默认值-1
        for (int i = 0; i < M.size(); i++) {
            for (int j = i + 1; j < M.size(); j++) {
                if (M[i][j]) Union(parent, i, j);
            }
        }
        return parent;
    }
};

//使用图的深度优先遍历
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();
        vector<bool> visited(size, false);
        int groups = 0;
        for (int i = 0; i < size; i++) {
            bool b = dfs(i, M, visited);//找到所有的联通元素，找到一个就标识为visited，下次将无法访问
            groups += b ? 1 : 0;//没被访问就加1被访问过就说明在之前的集合当中就不加
        }
        return groups;
    }
private:
    int dfs(int i, vector<vector<int>>& M, vector<bool> &visited)
    {
        int size = visited.size();

        if (visited[i] == true) {//如果当前元素已经被访问过 就return false
            return false;
        }
        visited[i] = true;
        //visit所有与当前元素i有直接关系的元素
        for (int j = 0; j < size; j++) {
            if ((M[i][j] == 1) && !visited[j]) {
                dfs(j, M, visited);
            }
        }
        return true;
    }
};