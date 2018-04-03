/*
分析：给出一个字符串，分解成若干个子串，要求每个子串当中的字母只在当前子串中出现
求解可以分解的子串的最大个数
babcafga jklj pp q o

对于当前遍历到的字母，将其插入到一个map当中并且记录出现的第一次的位置
如果下一个元素没有在map当中，那么目前认为这两个字母属于不同的子串

 */
//我的方法，是根据将已知信息进行处理最后判断的方式，空间复杂度略大。
static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(!S.size()) return vector<int>();
        map<char,vector<int>> table;
        vector<int> res;
        int n = S.size();
        for(int i=0;i<n;++i) {
        	if(table.find(S[i])==table.end())
        		table[S[i]] = vector<int> {i,i};
        	else
        		table[S[i]][1] = i;
        }
        vector<int> tag(n,0);
        for(int i=0;i<n;++i) {
        	if(table[S[i]][0]!=table[S[i]][1]) {
        		tag[table[S[i]][0]] = -1;
        		tag[table[S[i]][1]] = 1;
        	}
        }
        int sum = 0,index = -1;
        for(int i=0;i<n;++i) {
        	sum += tag[i];
        	if(sum==0) {
        		res.push_back(i-index);
        		index = i;
        	}
        }
        return res;
    }
};


//总的时间复杂度为o(2n)，空间复杂度为o(1)
//这道题目的贪心体现在：先假设最左边的元素出现的范围是要切分的集合
//得到这个集合的尾部指针
//继续遍历每个元素，如果集合当中的每个元素的尾部位置都在集合当中
//那么这个贪心的切分(最简单的切分)就是最优的切分
//如果中间出现了一个元素的尾部位置在集合之外，再将尾部位置更新为这个元素的尾部位置
//也就是出现了问题，调整集合，继续处理。
//每一个子问题都是一样的，每一步都是在构造当前最优的结果，这个结果不一定是最终的最优解
//但是一定是当前看到的有限条件下的最优子情况，随着看到的条件越来越多，自动去调整为最优解。
//这就是贪心算法的核心思想。
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> map(26, -1);
        //vector<pair<int,int>> group;
        for(int i=0; i<S.size(); i++)
        {
            map[S[i]-'a'] = i;//得到每一个字母最后一次出现的位置
        }

        for(int i=0, idx=0; i<S.size(); i++)
        {
            if(i==0 || i>idx)//当i>idx的时候，说明当前的元素已经不属于之前的集合
            {
                res.push_back(map[S[i]-'a']-i+1);//首先在i==0的时候将最左边第一个元素的首尾长度当做第一个子串长度
                idx = map[S[i]-'a'];//idx更新为第一个元素出现的最后一个位置
            }
            else if(map[S[i]-'a']>idx)//如果当前遍历到的元素出现的最后一个位置大于idx，说明之前的集合小了需要更新之前的集合长度以及集合的尾指针idx
            {
                res[res.size()-1] += map[S[i]-'a']-idx;//超出的元素的末尾下标减去之前集合的尾指针就是多出的元素个数
                idx = map[S[i]-'a'];//更新尾指针 尾指针后移
            }//其他情况就是i<idx并且map[S[i]-'a']<idx说明当前集合的这个元素的最后位置也在当前集合当中不用做任何处理
        }
        return res;
    }
};