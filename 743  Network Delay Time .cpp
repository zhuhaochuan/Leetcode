/*
分析：找到从指定节点到所有其他节点的最短路径当中最长的那条。
我觉得应该使用djstla算法
*/
//我的实现 历经磨难。。。
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(K>N) return -1;
        int res = 0,n = times.size();
        vector<int> v(N+1,1000);
        vector<int> visited(N+1,0);
        visited[K] = 1;
        v[K] = 0;
        map<int,vector<vector<int>>> table;

        for(int i=0;i<n;++i) {
            table[times[i][0]].push_back(times[i]);
        }

        dfs(table,v,K,visited);

        for(int i=1;i<=N;++i) {
            //cout << v[i] << endl;
            res = max(res,v[i]);
        }
        return res==1000?-1:res;
    }

    void dfs(map<int,vector<vector<int>>>& table,vector<int>& v,int K,vector<int>& visited) {
        if(!table.count(K)) {
            visited[K] = 1;
            int t = findMinNode(visited,v);
            if(!t) return;
            else dfs(table,v,t,visited);
        };

        for(int i=0;i<table[K].size();++i) {
            v[table[K][i][1]] = min(v[table[K][i][0]]+table[K][i][2],v[table[K][i][1]]);
        }

        int next;
        next = findMinNode(visited,v);
        if(next==0) return;
        visited[next] = 1;
        dfs(table,v,next,visited);
        return;
    }

    int findMinNode(vector<int>& visited, vector<int>& v) {
        int minIndex = 0, minV = 60001;
        for (int i = 1; i < v.size(); ++i) {
            if (!visited[i] && minV > v[i]) {
                minIndex = i;
                minV = v[i];
            }
        }
        return minIndex;
    }
};

//别人的实现 N*N*N的时间复杂度
//将Djstla算法分成三个部分：首先构成有向图的数据结构 邻接矩阵的形式
//每次需要从所有的节点当中找到cost最小的节点 通过他的边的信息更新路径表
//对于每一个处理过的节点将其放入已经得到最短路径的节点的集合当中 使用visited数组实现标识
//最后遍历路径表得到答案
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        vector<vector<int> > graph(N + 1, vector<int>(N + 1, 60001));
        vector<int> cost(N + 1);
        vector<bool> visited(N + 1, false);

        for (int i = 0; i < times.size(); ++i)
            graph[times[i][0]][times[i][1]] = times[i][2];
        for (int i = 1; i <= N; ++i)
            cost[i] = graph[K][i];

        cost[K] = 0;
        visited[K] = true;

        for (int i = 1; i <= N; ++i) {
            int minNode = findMinNode(cost, visited);
            if (minNode == 0) break;
            for (int j = 1; j <= N; ++j) {
                if (!visited[j] && cost[j] > cost[minNode] + graph[minNode][j]) {
                    cost[j] = cost[minNode] + graph[minNode][j];
                }
            }
            visited[minNode] = true;
        }

        return calSum(cost);
    }

    int findMinNode(vector<int>& cost, vector<bool>& visited) {
        int minIndex = 0, minV = 60001;
        for (int i = 1; i < cost.size(); ++i) {
            if (!visited[i] && minV > cost[i]) {
                minIndex = i;
                minV = cost[i];
            }
        }
        return minIndex;
    }

    int calSum(vector<int>& cost) {
        int sum = 0;
        for (int i = 1; i < cost.size(); ++i) {
            if (cost[i] == 60001) { return -1; }
            if (sum < cost[i]) { sum = cost[i]; }
        }
        return sum;
    }
};