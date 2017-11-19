/*2017-11-19 21:33:17
题目：
有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。注意这次的网格中有些障碍点是不能走的。
给定一个int[][] map(C++ 中为vector >),表示网格图，若map[i][j]为1则说明该点不是障碍点，否则则为障碍。另外给定int x,int y，表示网格的大小。
请返回机器人从(0,0)走到(x - 1,y - 1)的走法数，为了防止溢出，请将结果Mod 1000000007。保证x和y均小于等于50
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

在取模操作中，我们常把MOD设置为1000000007
模一个大数和模一个质数可以减少冲突
而1e9+7又有一个很好的特点，就是相加不会爆int，相乘不会爆long long
在设置无穷大值时中我们常常选择0x7fffffff作为INF值（32位int的最大值）
如果用这个值进行比较的话还好，但如果用这个数进行计算就很可能会出错。
例如在最短路径算法中用到的的松弛操作：if(a[u]+lm[u][v]）
知道如果u不能到达v，那么lm[u][v]=INF，如果我们的INF取0x7fffffff，那么a[u]+lm[u][v]会溢出而变成负数， 我们的松弛操作便出错了。
我们可以得到一个设置INF值的原理：INF加上另一个数仍为无穷大
在别人的博客中看到了0x3f3f3f3f这个十分精妙的数
0x3f3f3f3f的十进制是1061109567，和0x7fffffff一样也是1e9级别的，而一般场合下的数据都是小于1e9的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。
由于一般的数据都不会大于1e9，所以当我们把无穷大加上一个数据时，它并不会溢出
事实上0x3f3f3f3f+0x3f3f3f3f=2122219134，这非常大，但却没有超过32位int的表示范围
0x3f3f3f3f还能给我们带来一个意想不到的额外好处：
如果我们想要将某个数组清零，我们通常会使用 memset(a,0,sizeof(a))这样的代码来实现
但是当我们想将邻接矩阵初始化时（所有边都为INF），就需要得自己写循环了
我们知道这是因为memset是按字节操作的，它能够对数组清零是因为0的每个字节都是0
但是如果我们将无穷大设为0x3f3f3f3f，由于0x3f3f3f3f的每个字节都是0x3f
所以要把一段内存全部置为无穷大，我们只需要memset(a,0x3f,sizeof(a))

*/

//递归超时
class Robot {
public:
    int count = 0;
    int countWays(vector<vector<int> > map, int x, int y) {
      int i = j = 0;
      travelMap(map,x,y,i,j);
      return count;
    }
    void travelMap(vector<vector<int> >& map, int x, int y, int i, int j) {
      if(i>x-1||j>y-1) return;
      if(i==x-1&&j==y-1) {
        count ++;
        return;
      }
      if(map[i+1][j]==1) {
        travelMap(map,x,y,i+1,j);
      }
      if(map[i][j+1]) {
        travelMap(map,x,y,i,j+1);
      }
    }
}；

//采取迭代 这里其实就是动态规划 的方法 如下算法的复杂度为O(x*y) 
//采用一个额外的数组 每个位置的值为从起点到改点的可行路径的个数
class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        vector<vector<int> > dp(x,vector<int>(y,0));//x行y列的全0
        for(int i = 0; i < x; i ++){
            for(int j = 0; j < y; j ++){
                if(map[i][j] != 1) continue;//如果是障碍直接跳出当前的循环执行下一层循环
                if(i == 0 && j == 0) dp[0][0] = 1;
                else if(i != 0 && j == 0) dp[i][0] = dp[i-1][0] ;
                else if(i == 0 && j != 0) dp[0][j] = dp[0][j-1] ;
                else{
                    dp[i][j] = (dp[i][j-1] + dp[i-1][j])%1000000007;//到达这个点的可行路径 为左和上方的点的可行路径之和
                }
            }
        }
        return dp[x-1][y-1];
    }
};