/*
分析：从给定的单词中得到含有给定的字母的最短的单词
字母的出现的次数也需要一致才可以
如果有多个结果符合的话选择第一个遇到的

我的想法就是 遍历一遍整个数组
这个是必须要做的 因为需要得到最短的 那个单词
那么需要一个数组保存可行的结果 最后输出这些结果当中长度最短的第一个单词

第一个问题：怎么判断单词含有这些字母
看例子当中的输入的不一定都是字母 可能含有空格和数字 含有的字母可能包含大小写
给的单词只有小写
方案1：将输入的标准字母得到 全部转换为小写字母
和数组中的单词逐个比较 这样复杂度太高

方案2：将有的字母以key的形式插入到multimap(可能会有重复)当中 value为数字的序号
将单词按照每一个元素去判断是否在map当中
比如 ssabc 这5个字母为必须具备的 那么如果在 map[key]--
当map中的所有元素的key都为0 就表示这个单词含有这些字母
每次判断结束之后 map要还原
 */

//傻逼写法
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
    	string res, s;
    	map<char,int> m;
    	map<int,string> ans;
     	for(auto each : licensePlate) {
    		if(each>=65&&each<=90) {
    			char temp = (char)(each + 32);
    			s += temp;
    			if(m.find(temp)==m.end())
    				m[temp] = 1;
    			else
    				m[temp]++;
    		}
    		else if(each>=97&&each<=122) {
    			s += each;
    			if(m.find(temp)==m.end())
    				m[temp] = 1;
    			else
    				m[temp]++;
    		}
    	}

    	for(auto each : words) {
    		map<char,int> mm(&m);
    		for(int i=0;i<words.size();i++) {
    			if(mm.find(words[i]!=mm.end())) {
    				if(mm[temp]!=0)
    					mm[temp]--;
    			}
    		}
    		int flag = s.size();
    		for(auto each : mm) {
    			if(each.second==0)
    				flag--;
    		}
    		if(flag==0)
    			ans[words.size()] = each;

    	}
    	return res = *ans.begin();
    }
};


//和我的想法基本一致
//学习这里用到的函数
class Solution {
    inline bool hasMet(vector<int>& a) {
        for (auto x : a)
            if (x > 0)
                return false;
        return true;
    }
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> h(26, 0);
        string ans = "";
        for (auto x : licensePlate)
            if (isalpha(x))
                h[tolower(x) - 'a']++;

        for (auto w:words) {
            vector<int> f = h;//采用拷贝构造的方式这样每次不用再考虑还原的事情
            for (auto x : w) {
                if (isalpha(x)) {
                    f[tolower(x) - 'a']--;
                    if (hasMet(f) && (ans.length() > w.length() || ans.length() == 0)) {
                        ans = w;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};