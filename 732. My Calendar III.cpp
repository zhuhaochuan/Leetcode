/*
分析：返回当前所以集合当中最大的交集个数
MyCalendarThree();
MyCalendarThree.book(10, 20); // returns 1
MyCalendarThree.book(50, 60); // returns 1
MyCalendarThree.book(10, 40); // returns 2
MyCalendarThree.book(5, 15); // returns 3
MyCalendarThree.book(5, 10); // returns 3
MyCalendarThree.book(25, 55); // returns 3
每次插入一个集合 求得所有集合当中交集最多的集合的个数
怎样算是有交集：
[a,b) 和 [c,d)
计算交集的情况有四种
怎样算是没有交集：
c>=b
a>=d
就这两种
那么可以采用一个数组存储这些集合

 */
struct node {
	int first;
	int end;
    node(int& a,int& b):first(a),end(b) {}
};

class MyCalendarThree {
public:
	vector<node> v;
	int max = 0;
	node n(0,0);
    MyCalendarThree() {

    }

    int book(int start, int end) {
    	if(!v.size()) {
    		v.push_back(node(start,end));
    	    return max = 1;
    	}
    	n.first = start;
    	n.end = end;
        int temp = 1;
    	for(auto each : v) {
    		if(!(start>=each.end||each.first>=end)) {
    			if(!(n.first>=each.end||each.first>=n.end))
    				temp++;
    			n.first = start>each.first? start : each.first;
    			n.end = end < each.end ? end : each.end;
    		}
    	}
        if(temp>max)
    		max = temp;
        v.push_back(node(start,end));
    	return max;
    }
};


//大写的服气
//http://blog.csdn.net/guo15331092/article/details/78883265
class MyCalendarThree {
public:
    MyCalendarThree() {
        maximum = 0;
    }

    int book(int start, int end) {
        int k = 0;
        ++m[start];
        --m[end];
        for (auto i = m.begin(); i != m.end(); ++i) {
            k+= i->second;
            if (maximum < k) maximum = k;
        }
        return maximum;
    }
    map<int, int> m;
    int maximum;
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */