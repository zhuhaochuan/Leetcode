//判断第二个字符串当中是否包含第一个字符串的排列构成的子串
//Input:s1= "ab" s2 = "eidboaoo"
//Output: False
//超时 得到字符串的全排列 采用的递归的方式 这样的时间复杂度为o(n!+m*m)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        if(n>m) return false;
        //得到s2的所有可能的子串放进map当中
        unordered_map<string,int> table;
        vector<string> v;
        for(int i=0;i<m;++i) {
        	vector<string> temp;
        	for(auto e:v) {
        		string ts = e + s2[i];
        		temp.push_back(ts);
        		++table[ts];
        	}
        	string tt;
        	tt.push_back(s2[i]);
        	temp.push_back(tt);
        	++table[tt];
            v = temp;
        }
        return getperm(s1,"",table);
    }

    //得到s1的全排列
    bool getperm(string& s1,string temp,unordered_map<string,int>& table) {
    	int n = s1.size();
    	if(n==0) {
    		bool tag = table[temp];
    		return tag;
    	}
    	for(int i=0;i<n;++i) {
    		temp.push_back(s1[i]);
    		string t(s1.begin(),s1.end());
    		t.erase(t.begin()+i);
    		bool res = getperm(t,temp,table);
    		if(res) return true;
    		temp.pop_back();
    	}
        return false;
    }
};
//超时 时间复杂度为o(n*m*m)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        if(n>m) return false;

        unordered_map<char,int> table2;
        for(auto e:s1) {
        	++table2[e];
        }
        vector<string> v;
        for(int i=0;i<m;++i) {//得到字符串所有的子串 时间复杂度为o(m*m)
            bool tag1 = false,tag2 = false;
        	vector<string> temp;
        	for(auto e:v) {
        		string ts = e + s2[i];
        		temp.push_back(ts);
        		if(ts.size()==n)
        			tag1 = helper(ts,table2);
        	}
        	string tt;
        	tt.push_back(s2[i]);
        	temp.push_back(tt);
        	if(tt.size()==n)
        		tag2 = helper(tt,table2);
            v = temp;
            if(tag1||tag2) return true;
        }
        return false;
    }

    bool helper(string& s,unordered_map<char,int> table2) {
    	for(auto e: s) {
    		--table2[e];
    		if(table2[e]<0)
    			return false;
    	}
    	return true;
    }
};

//过了。。。但是时间复杂度有点高  我这时间复杂度其实是o(n*(m-n))
//我这里也是维持一个滑动窗口，但是每次都还是遍历一遍子串看看和s1是不是所有元素的个数相同。。。
//没有考虑到一共就26个字母，所以维持一个26个字母的哈希表就可以每次只需要改的头尾元素变化带来的影响
//这样每次只需要比较26个字母，而我的想法则要比较n个元素，，如果n远大于26那么复杂度将很大！！
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        if(n>m) return false;

        unordered_map<char,int> table2;
        for(auto e:s1) {
        	++table2[e];
        }
        for(int i=0;i<m-n+1;++i) {
        	unordered_map<char,int> table = table2;
        	for(int j=i;j<=i+n-1;++j) {
        		--table[s2[j]];
        		if(table[s2[j]]<0)
        			break;
        	}
        	return true;
        }
        return false;
    }
};

//一样的思路但是时间复杂度其实是o(26*(m-n))
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<int> m1(128),m2(128);
        for(int i=0;i<n1;i++){
            ++m1[s1[i]],++m2[s2[i]];
        }
        if(m1==m2) return true;
        for(int i=n1;i<n2;i++){
            ++m2[s2[i]];
            --m2[s2[i-n1]];
            if(m1==m2) return true;
        }
        return false;
    }
};

