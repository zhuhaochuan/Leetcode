/*
分析：给出两个数n 和 k
需要构造出一个n个元素的序列
这n个元素两两前后相减得到的绝对值 拥有不同的个数为K个
n个数得到的是n-1个差的结果 这个差序列 有k个不同的数
并且还有一个条件就是构成原来序列的元素必须在1-n之间
必须使用1-n个不同的数 没有重复

首先k<=n-1
比如k
那么生成的差我选取K K-1 K-2 K-3..
第一个去构成的就是K这个差

 */

class Solution {
public:
    vector<int> constructArray(int n, int k) {
    	vector<int> res;
        if(k==1) {
        	for(int i=1;i<=n;i++)
        		res.push_back(i);
        	return res;
        }
        map<int,int> table;
        for(int i=1;i<=n;i++) {
        	table[i] = 1;
        }
        res.push_back(1); table[1] = 0;
        int temp = 0,i = 1;
        while(k>0) {
            if(table.find(res[i-1]-k)!=table.end() && table[res[i-1]-k]!=0) {
                table[res[i-1]-k] = 0;
                temp = res[i-1] - k;
                res.push_back(temp);
            }
            else {
                table[res[i-1]+k] = 0;
                temp = res[i-1]+k;
                res.push_back(temp);
            }
            k--; i++;
        }
        for(auto each : table) {
            if(each.second!=0)
                res.push_back(each.first);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        res.push_back(1);
        int j = k;
        for(int i=1;i<=j;i++) {
        	int tag = i%2;
        	if(tag)
        		res.push_back(res[i-1]+k);
        	else
        		res.push_back(res[i-1]-k);
        	k--;
        }
        for(int i=j+2;i<=n;i++)
        	res.push_back(i);
        return res;
    }
};