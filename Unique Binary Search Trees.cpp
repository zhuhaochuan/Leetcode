/*
 这道题要求可行的二叉查找树的数量，其实二叉查找树可以任意取根，只要满足中序遍历有序的要求就可以。
 从处理子问题的角度来看,选取一个结点为根，就把结点切成左右子树，左边的结点值均小于当前根结点的值，右边的结点的值均大于当前结点的值。
 以这个结点为根的可行二叉树数量就是左右子树可行二叉树数量的乘积，
 所以总的数量是将以所有结点为根的可行结果累加起来。写成表达式如下：

熟悉卡特兰数的朋友可能已经发现了，这正是卡特兰数的一种定义方式，是一个典型的动态规划的定义方式（根据其实条件和递推式求解结果）。
所以思路也很明确了，维护量res[i]表示含有i个结点的二叉查找树的数量。根据上述递推式依次求出1到n的的结果即可。
时间上每次求解i个结点的二叉查找树数量的需要一个i步的循环，总体要求n次，
所以总时间复杂度是O(1+2+...+n)=O(n^2)。空间上需要一个数组来维护，并且需要前i个的所有信息，所以是O(n)。代码如下：


思路就是：反正就是BST，每个元素都做根节点，算出每个元素做根节点时有几种情况，然后每个节点的几种情况相加。
每个元素有几种情况，根据bst的特性，就是中序便利是排序的。所以：
以n＝3为例。新建一个int res[]= int[3+1](循环1，2，3，每个数字对应所再index，而不是1对应0index，2对应1 index...)
1是根节点的时候，1的左子树是0个，右子树是2，3（两个）。所以是1是根节点的种类数是：res[0]乘以res[2]情况数。
2是根节点的时候，2的左子树是1（1个），右子树是1（1个）。所以是2是根节点的种类数是：res[1]乘以res[1]情况数。
3是根节点的时候，3的左子树是1，2（2个），右子树是（0个）。所以是2是根节点的种类数是：res[2]乘以res[0]情况数。
*/
public int numTrees(int n) {  
    if(n<=0)  
        return 0;  
    int res[n+1];  
    res[0] = 1;  
    res[1] = 1;  
    for(int i=2;i<=n;i++)  
    {  
    	res[i] = 0; //需要置0 局部变量没有初始化都为随机值
        for(int j=0;j<i;j++)  
        {  
            res[i] += res[j]*res[i-j-1];  
        }  
    }  
    return res[n];  
 }  

/*
这种求数量的题目一般都容易想到用动态规划的解法，这道题的模型正好是卡特兰数的定义。
当然这道题还可以用卡特兰数的通项公式来求解，这样时间复杂度就可以降低到O(n)。因为比较直接，这里就不列举代码了。
如果是求解所有满足要求的二叉树（而不仅仅是数量）那么时间复杂度是就取决于结果的数量了，
不再是一个多项式的解法了，有兴趣的朋友可以看看Unique Binary Search Trees II。
*/