/*
分析：有N个房间编号0~N-1。从第0个房间开始。每个房间含有若干把钥匙每个钥匙可以开一个房间。
判断是否可以打开所有的房间。
深度优先遍历：每次进入一个房间，拿走全部钥匙，将visit数组当中对应该位置的tag置位1（记忆化搜索）。
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(n<2) return true;
        vector<int> visited(n,0);
        vector<int> keys(1,0);
        int tag = 0;
        for(int i=0;i<keys.size();++i) {
            if(tag==n) return true;
            if(!visited[keys[i]]) {
                visited[keys[i]] = 1;
                ++tag;
                int m = rooms[keys[i]].size();
                for(int j=0;j<m;++j) {
                    if(!visited[rooms[keys[i]][j]])
                        keys.push_back(rooms[keys[i]][j]);
                }
            }
        }
        return tag==n;
    }
};