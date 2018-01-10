/*
分析：给出一个公司所有人的id数据 求给定id的人的总value
一个人最多只可以有一个直接上司 可以有很多个直接下属
想法：这个是每个人只知道后继有谁不知道前驱是谁
这样的话可以使用一个数组去存前驱 数组pre[n+1] 每个位置存放他的直接领导
再使用一个map key为对应的id value为该id所具有的值


我的方法的空间开销其实挺大的 其他的还好
这个方式从建模的角度去看
可以看做图或者多叉树 每个人的关系是复杂的
要的得到一个人的总的value 就需要遍历所有与之相连的节点
这样的遍历就是深度优先遍历 DFS
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
struct node {
	int val;
	vector<int> v;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
    	unordered_map<int,node> table;
    	for(auto each : employees) {
    		table[each->id].val = each->importance;
    		table[each->id].v = each->subordinates;
    	}
    	int sum = table[id].val;
    	findsum(id,sum,table);
    	return sum;
    }
    void findsum(int id,int& sum,unordered_map<int,node>& table) {
    	for(auto each : table[id].v) {
    		sum += table[each].val;
    		findsum(each,sum,table);
    	}
    }
};

//这个想法我也想过 先将给定的数组按照自定义的比大小的方式进行排序
//使用的是自定义的小于号 按照id的大小排序 id小的在前面
//使用算法中的sort对数组进行排序
//然后递归的访问每一个结构体
//
class Solution {
public:
    static bool compare(Employee* e1, Employee* e2){
        return e1->id < e2->id;
    }
    void visit(vector<Employee*> &employee, int id, int& ret){
        Employee e;//这里需要找到对应id的元素 所以需要用一个临时的e去保存待比较的id
        e.id = id;
        auto it = lower_bound(employee.begin(), employee.end(), &e, compare);
        //找到大于等于给定id的第一个位置的迭代器 在这里就是等于id的迭代器
        ret += (*it)->importance;//加上自己的值
        for(int i : (*it)->subordinates){//对于所有的后继 递归的访问
            visit(employee, i, ret);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int ret = 0;
        sort(employees.begin(), employees.end(), compare);
        visit(employees, id, ret);
        return ret;
    }
};