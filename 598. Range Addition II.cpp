/*
分析：给出一个矩阵 和一系列操作 将给出的操作当中范围内的元素加一
最后返回矩阵当中最大元素的个数
直接取所有操作的交集
 */


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(!ops.size()) return m*n;
        int len = ops.size(),a = INT_MAX,b = INT_MAX;
        for(int i=0;i<len;++i) {
        	if(ops[i][0]<a)
        		a = ops[i][0];
        	if(ops[i][1]<b)
        		b = ops[i][1];
        }
        return a * b;
    }
};

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(vector<int> &op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m*n;
    }
};