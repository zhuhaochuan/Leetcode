/*
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

没想出来简单的算法思路
看了别人的思路 很精彩很清晰
有些想法和我想的一样但是我没有将想法深入
step1 将所有的键值对按照key的大小排列 对最大的key的子序列s进行排序 这个位置就是他们以后的相对位置
step2 对于剩下的序列中最大的key子序列 排序 在将其逐个插入到s对应value的位置
step3 重复2的操作

整个分析的过程：可见每次插入的位置就是value的位置
70 71
70 61 71
50 70 61 71
50 70 52 61 71
50 70 52 61 44 71
 */


class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    	auto temp = [](pair<int,int> p1, pair<int,int> p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };//无捕获的lambda表达式可以转换为同类的的函数指针
        bool (*func)(pair<int,int>, pair<int,int>) = temp;
    	sort(people.begin(),people.end(),func);
    	vector<pair<int,int>> sol;

        for (auto person : people){
            sol.insert(sol.begin() + person.second, person);
        }
        return sol;
    }
};



vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(),[](pair<int,int> p1, pair<int,int> p2){
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });//这里是从大到小排列。。定义的方式

        vector<pair<int,int>> sol;

        for (auto person : people){
            sol.insert(sol.begin() + person.second, person);
        }
        return sol;
}

/*
sort():
template <class RandomAccessIterator, class Compare>
  void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
这个是标准库中的算法 就是作用于各种标准的容器的一种排序算法
有三个参数
第一个参数是待排序的容器的首个排序位置的迭代器
第二个参数是排序最后位置的迭代器
切记是左闭右开的
第三个是一个对于小于号的定义的排序函数
这个函数定义了小于比较的bool返回值
如果返回值为true就交换两个元素
如果返回值为false就不交换
如果这个参数缺省就是按照迭代器指向的元素自身定义的小于号操作符函数去判断
那么问题来了 如果本身迭代器指向的元素没有小于号操作符那么就必须自己去重载
这个参数可以传入函数指针也可以传入函数对象
下面分别介绍：
1.函数指针的实现：
写一个bool类型返回值的函数 函数有两个参数 将函数名也就是函数指针传入第三个参数
2.函数对象的方式：
写一个类或者结构体 重载这个类的圆括号操作符 也就是()operater(){}这个函数
也是bool类型返回值，两个参数 再将这个类的对象传入第三个参数即可。

[](pair<int,int> p1, pair<int,int> p2)
{
    return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
 });
[]里是对于外部变量的捕获这里函数体内没有对于外部变量的使用就不需要捕获
()里是表达式的参数 将在函数体内使用到的
{}里是表达式的函数体 如果省略了返回值的描述将从return的类型自动判别

[capture](parameters)->return-type{body}
如果没有参数,空的圆括号()可以省略.返回值也可以省略,如果函数体只由一条return语句组成或返回类型为void的话
对于lambda表达式的使用也非常的简单
直接就是(参数1，参数2，...) 就和一般的函数一样使用
一个没有指定任何捕获的lambda函数,可以显式转换成一个具有相同声明形式函数指针.
当然也可以采用匿名函数的方式 也就是lambda表达式来作为第三个参数
 */
