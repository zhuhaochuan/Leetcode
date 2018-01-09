/*
分析：insert 就是插入键值对
sum 就是找到拥有对应前缀的键对应的值得和
想法就是 设置一个成员变量为undered_map 将对应的键和值插入
再去用前缀匹配
 */

class MapSum {
public:
	unordered_map<string,int> m;
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
    	m[key] = val;
    }

    int sum(string prefix) {
    	int len = prefix.size(),sum = 0;
    	for(auto each : m) {
    		if(each.first.size()>=len) {
    			for(int i=0;i<len;i++){
    				if(each.first[i]!=prefix[i])
    					break;
    				if(i==len-1) {
    					sum += each.second;
    				}
    			}
    		}
    	}
    	return sum;
    }
};


class MapSum {
public:
    //这里是采用map的方式  就是所有的元素按照key排序
    //这里的key是string string重载了<操作符 所以可以放入
    //string的比较是按照首个字符开始逐个比较ASCII码
    void insert(string key, int val) {
        mp[key] = val;
    }

    int sum(string prefix) {
        int sum = 0, n = prefix.size();
        //lower_bound 返回的是大于等于的当前参数的第一个元素的迭代器 这个元素的key值可以等于也可以更大
        //upper_bound 返回的是大于参数的第一个元素的迭代器 这个元素的key值是大于参数的
        for (auto it = mp.lower_bound(prefix); it != mp.end() && it->first.substr(0, n) == prefix; it++)
            sum += it->second;
        return sum;
    }
private:
    map<string, int> mp;
};


/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */