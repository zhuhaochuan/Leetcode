/*
分析：给出一个有向图。规定安全节点为没有出度的节点。
规定一个节点按照任意一条出边都能最终走到安全节点的节点为所需节点。
找到所有这些节点
一个节点

深度优先遍历：规定遍历顺序，配合visited数组标识访问过的地方，减少不必要的访问。

*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if(!n) return vector<int>();
        vector<int> res;
        vector<int> visited(n,0);//0表示没有访问过 1表示访问过 2表示确定该节点属于安全节点
        for(int i=0;i<n;++i) {
            if(dfs(graph,visited,i))
                res.push_back(i);
        }
        return res;
    }

    bool dfs(vector<vector<int>>& graph,vector<int>& visited,int index) {
        if(visited[index]==2) return true;
        int n = graph[index].size();
        if(!n) {
            visited[index] = 2;
            return true;
        }
        visited[index] = 1;

        for(int i=0;i<n;++i) {
            if(visited[graph[index][i]]==0) {
                bool tag = dfs(graph,visited,graph[index][i]);
                if(!tag) return false;
            }
            else {
                if(visited[graph[index][i]]!=2) return false;
            }
        }
        visited[index] = 2;
        return true;
    }
};



//逻辑清晰一点：
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if(!n) return vector<int>();
        vector<int> res;
        vector<int> visited(n,0);//0表示没有访问过 1表示访问过 2表示确定该节点属于安全节点
        for(int i=0;i<n;++i) {
            if(dfs(graph,visited,i))
                res.push_back(i);
        }
        return res;
    }

    bool dfs(vector<vector<int>>& graph,vector<int>& visited,int index) {
        if(visited[index]!=0) return visited[index]==2;//如果被访问过 那么如果这个节点是安全的就返回true 否则这个节点还就是不安全的
        int n = graph[index].size();
        visited[index] = 1;

        for(int i=0;i<n;++i) {
            bool tag = dfs(graph,visited,graph[index][i]);
            if(!tag) return false;
        }
        visited[index] = 2;
        return true;
    }
};