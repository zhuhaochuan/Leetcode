/*
分析：分配饼干 一人一个，但是必须满足每一个孩子
求可满足的孩子的最大个数
[1,2], [1,2,3]先对于孩子的饥饿程度排序
越小的孩子优先给，最好是分配的大小和需要的大小一致
 */

//o(n*m)的方法。。。有点蠢
static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(!g.size()||!s.size()) return 0;
        int n = g.size(),m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res = 0;
        for(int i=0;i<n;++i) {
            int j=0;
        	for(;j<m;++j) {
        		if(g[i]<=s[j]) {
        			++res;
        			s[j] = 0;
                    break;
        		}
        	}
            if(j==m) break;
        }
        return res;
    }
};

//改进版本 o(m) + o(log(n)) 先排序，如果当前的孩子被满足就进行下一个孩子，如果当前的孩子没有被满足，那么后面的孩子就没有必要再去判断因为不可能
static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(!g.size()||!s.size()) return 0;
        int n = g.size(),m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res = 0,j = 0;
        for(int i=0;i<n&&j<m;++j) {
    		if(g[i]<=s[j]) {
    			++res;
    			++i;
    		}//如果不满足就++j直到最后都没有就跳出
        }
        return res;
    }
};