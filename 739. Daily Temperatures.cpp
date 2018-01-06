/*
分析：给出一个数组 给出每一个数到达下一个比他大的数要经过的数的个数 若没有返回0
 [73, 74, 75, 71, 69, 72, 76, 73]
 [1, 1, 4, 2, 1, 1, 0, 0]
 */

//如果所有的数都一样那么这个代码的时间复杂度是n!
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for(int i = 0;i<temperatures.size();i++) {
        	for(int j = i+1;j<temperatures.size();j++) {
        		if(temperatures[j]-temperatures[i]>0) {
        			res.push_back(j-i);
        			break;
        		}
        		res.push_back(0);
        	}
        }
        res.push_back(0);
        return res;
    }
};

//真的是尼玛艰辛的debug过程。。。。  降序栈
//思路其实很正确 使用一个栈遍历给的数组 整体的算法的复杂度为o(n)
//因为后面的数在得到结果的同事可以将前面的小的数一并解决减少了很多的重复的判断
//期间将数入栈 如果大于当前栈顶元素的值就将栈顶元素出栈 得到其对应的输出
//如果此时栈不为空继续判断下一个栈顶元素的值和当前的值得比较
//也就是大数入栈就持续压栈将栈中小的元素压出去并且得到小数的输出
//最后栈中剩下的元素就是没有对于答案的数 就将其对应的输出设为0
//中间需要自己定义一个节点的结构体 去存放对应的数的值和在原数组的index
class Solution {
public:
	struct node {
		int value;
		int index;
		node(int val,int i):value(val),index(i){}
	};

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<node> s;
        node temp(temperatures[0],0);
        s.push(temp);

        for(int i=1;i<temperatures.size();i++) {
        		node cur = s.top();
        		while(!s.empty()) {
        			if(temperatures[i]>cur->value) {
        				res[cur.index] = (i-cur.index);
        				s.pop();
        				if(!s.empty()) //这个判断不能少 如果栈为空再top编译不通过
        					cur = s.top();
        			}
        			else break;
        		}
                node tempnode(temperatures[i],i);
    		    s.push(tempnode);
        }
        while(!s.empty()) {
        	res[s.top().index] = 0;
        	s.pop();
        }
        return res;
    }
};

//使用pair类型 就不用自己再定义一个结构体了
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> rest;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); ++i) {
            if(!res.empty()) {
                while(!rest.empty()) {
                    pair<int, int> r = rest.top();
                    if(r.second >= temperatures[i]) break;
                    rest.pop();
                    res[r.first] = (i - r.first);
                }
            }
            rest.push(make_pair(i, temperatures[i]));
        }
        return res;
    }
};

//别人的二叉搜索
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        multimap<int,int>hash;
        vector<int>res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            auto it=hash.lower_bound(temperatures[i]);
            for(auto it2=it;it2!=hash.begin();){
                it2--;res[it2->second]=i-it2->second;
            }
            hash.erase(hash.begin(),it);
            hash.emplace_hint(hash.begin(),temperatures[i],i);
        }
        return res;
    }
};