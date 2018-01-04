/*
分析：给出一个数字N 用1-N的所有整数构造一种排列
第i个位置的数可以整除位置i或者位置i可以整这个位置的数
1 1
2 [1,2] [2,1]
3 [1,2,3] [2,1,3] [3,2,1]
4 [1,2,3,4] [2,1,3,4] [3,2,1,4] [4,1,3,2] [4,2,3,1]



分析：深度优先搜索，从N开始一直到0，用visit标记当前元素是否访问过，
当当前下标为1的时候表示当前深度优先的一条路径满足条件，result+1，
否则遍历visit数组看有没有没被访问过的元素，如果满足(i % index == 0 || index % i == 0)就标记为已经访问过，
然后继续向下遍历dfs(index-1)～最后返回result的结果～

不能说是深度优遍历
应该是典型的回溯算法的应用
选择合适的顺序去枚举 并且标记每一个被选择的可能 减少搜索空间
 */

//学习下面的代码
class Solution {
public:
    int countArrangement(int N) {
        visit.resize(N+1);//为什么是n+1 因为可以得到1-N的下标代表1-N个值 0并不用
        dfs(N);
        return result;
    }
private:
    int result = 0;
    vector<bool> visit;

    void dfs(int index) {
        if (index == 1) {//递归的出口 当放置到位置1 的时候 说明前面所有的位置都被放好了且位置1放任何数都可以 result++
            result++;
            return;
        }
        //一般情况 从N开始先判断是否visit过 若无看是否匹配当前的index 如果匹配这个数就放在当前的位置 去找下一个位置应该放置的数
        //下一次还是会从visit数组从头开始遍历 找到第一个没放置的数去匹配当前的位置
        for (int i = 1; i < visit.size(); i++) {
            if (visit[i] == false && (i % index == 0 || index % i == 0)) {
                visit[i] = true;
                dfs(index-1);
                visit[i] = false;//因为是求的所有的可能这里的visit必须还原 然后进行下一个可能的尝试
            }
            return;//这里的return写不写都一样 就是当这个位置没有数匹配的时候 就递归返回
        }
    }
};