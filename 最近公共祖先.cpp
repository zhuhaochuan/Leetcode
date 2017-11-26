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



//01 10 11
// 100 101
// 10 


//如果不给你用栈这种底层为deque这种慢的像蜗牛爬一样的容器类怎么办？

//脑子里想想这样的二叉树，然后上面每个编号转化成二进制，于是发现，每个节点A的2个儿子节点的二进制表示，是A的二进制表示后分别追加0和1.

//于是一种不需要任何数据结构的思路是，把10进制数转化成二进制串，从高位到低位，找最长公共前缀，这个前缀转化成十进制int就行了。

class LCA {
public:
    string int2b(int x){
        string ans="";
        while(x){
            ans=(char)((x&1)+'0')+ans; //char是根据后面变量的ascii码来转换对应字符串的。
            //x>>1;这样仅仅得到一个临时的无名变量 并不会改变x本身的值
            x = x >> 1; 
        }
        return ans;
    }
    int getLCA(int a, int b) {
        string sa=int2b(a);
        string sb=int2b(b);
        int ans=0;
        for(int i=0;i<sa.length()&&i<sb.length();i++){
            //if(sa[i]==sb[i]) ans=ans<<1+(sa[i]-'0'); 这样不对。<<作为移位运算符的优先级低于算数运算符。
            if(sa[i]==sb[i]) ans=(ans<<1)+(sa[i]-'0');
            else break;
        }
        return ans;
    }
};