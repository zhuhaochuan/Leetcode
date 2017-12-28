/*
分析：对于偶数个糖果 一个人最多分到的就是n/2个 最多的种类就是n/2
最简单的方式就是遍历一遍数组 数一共有多少种糖果当数量达到n/2的时候就直接停止就可以
否则遍历到数组最后

先对数组进行排序，数组可能很大 第一中方式在判断是否重复上有问题
怎么判别当前的数是否已经有了？
不可能将所有的数在单独保存在一个数组当中 然后遍历保存的数组看是否存在 这样的时间复杂度太高

采用集合set的形式 集合是排好序的但是不可重复
进而采用unorder_set 没有排序的集合 只要遍历过程中插入set即可 最后在n/2和set.size()取个交集就是答案
 */


class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        if(!candies.size()) return 0;
        unordered_set<int> s;
        for(auto each : candies) {
        	s.insert(each);//注意这里是insert
        }
        return candies.size()/2>s.size()?s.size():candies.size()/2;
    }
};


//黑科技 使用位集合bitset 处理
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        bitset<200001> v;//针对-10000-10000的整数需要开这么大长度的位
        size_t cnt = 0;
        for (int i : candies) {
           cnt += !v.test(i + 100000);//检测是否对应位为1
           v.set(i + 100000);//将有的位置1
        }
        return min(cnt, candies.size() / 2);
    }
};
//位集合的操作快与我的方法 但是也是采用的空间换取时间的方式
//需要知道数据的范围 且不能动态扩充 而且需要的位也非常的多

//写法比我简单，，，，思路一致
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kds(candies.begin(), candies.end());
        //初始化set的方式 可以传入两个迭代器的方式实现构造 
        return min(kds.size(), candies.size()/2);

    }
};