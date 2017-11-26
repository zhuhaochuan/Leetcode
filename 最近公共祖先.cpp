/*
有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
*/
// 1 2 3 4 5 6 7 8 9

//      1
//    2   3
//   4 5 6 7
//  8 9


//我的想法 比较傻瓜 明显是满二叉树 却还要自己构造一个数组 没有好好利用这个条件
class LCA {
public:
    int getLCA(int a, int b) {
      if(a>b) {
        int c = a;
        a = b;
        b = c;
      }
        int res[b+1];
        res[0] = 1;
        res[1] = 1;
        int j = 1;
        for(int i=2;i<=b;) {
          res[i] = j;
          if(i+1<=b) res[i+1] = j;
          i+=2;
          j++;
        }
        int lager,smaller;
        lager = -1;
        smaller = 0;
        while(lager!=smaller) {
           if(res[a]<=res[b]) {
             lager = res[b];
             smaller = res[a];
             res[b] = res[res[b]];
           }
           else if(res[a]>=res[b]) {
             lager = res[a];
             smaller = res[b];
             res[a] = res[res[a]];
           }
          }
          return lager;
    }
};




//思路：满二叉树的子节点与父节点之间的关系为root = child / 2
//利用这个关系，如果a ！= b，就让其中的较大数除以2， 如此循环知道a == b，
//即是原来两个数的最近公共祖先
//代码如下：
 class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        while(a != b)
            {
            if(a > b)
                a /= 2;
            else
                b /= 2;
        }
        return a;
    }
};