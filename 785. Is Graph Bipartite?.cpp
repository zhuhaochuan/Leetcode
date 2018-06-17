/*
分析： 给出一个无向图 判断是否可以将这个图的节点分成两个集合
使得每条边在每个集合的都有一个节点出现。判断图是不是二分的。
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n<3) return true;
        //visited数组 对于每个节点分为两组 用1和2标识
        vector<int> visited(n,0);
        visited[0] = 1;
        for(int i=0;i<n;++i)
            if(!dfs(graph,visited,i))
                return false;
        return true;
    }

    bool dfs(vector<vector<int>>& graph,vector<int>& visited,int index) {
        for(int i=0;i<graph[index].size();++i) {
            if(!visited[graph[index][i]]) {
                visited[graph[index][i]] = visited[index]==1?2:1;
                if(!dfs(graph,visited,graph[index][i]))
                    return false;
            }
            else if(visited[graph[index][i]]==visited[index])
                return false;
        }
        return true;
    }
};

