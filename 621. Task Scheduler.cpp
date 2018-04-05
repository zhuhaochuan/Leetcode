/*
分析：给出一串字符串，字符串代表一串不同的任务
每一个时间片段只能执行一个任务，但是没两个相同的任务之间必须有一定的间隔n
这个间隔可以执行别的任务也可以使用休息间隔填充。
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

 */


//这里其实不能使用map因为map不能使用sort进行排序
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(!tasks.size()) return 0;
        map<char,int> table;
        for(char each : tasks) {
        	++table[each];
        }
        int f = (*table.begin()).second,i=0;
        for(auto each : table) {
        	if(each.second==f)
        		++i;
        }
        return max(int(tasks.size()),(f-1)*(n+1) + i);
    }
};



//采用字母ASCII码和下标的映射关系构建一个map
//key是下标 value是元素值
//思路就是先放出现频率最高的元素，划分好区域在计算
//其次给定的n大于等于给出的任务种类数
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            ++cnt[task - 'A'];
        }
        sort(cnt.begin(), cnt.end());
        int i = 25, mx = cnt[25], len = tasks.size();
        while (i >= 0 && cnt[i] == mx) --i;
        return max(len, (mx - 1) * (n + 1) + 25 - i);
    }
};