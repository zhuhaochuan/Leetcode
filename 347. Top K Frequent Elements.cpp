/*
给出一个数组找出出现频率最高的k个元素
时间复杂度需要比o(nlog(n))低
Given [1,1,1,2,2,3] and k = 2, return [1,2].
首先需要遍历一遍数组 构建一个map<元素，出现次数>
简单来说再次遍历一遍map就能够得到出现次数最多的几个元素

 */
//错误答案
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(!nums.size()) return vector<int>();
        map<int,int> table;
        for(int e : nums)
        	++table[e];
        //标准库的sort采用的是快速排序 如果对于容器当中的元素排序该容器必须支持随机访问的迭代器 只有vector和list支持随机访问迭代器
        sort(table.begin(),table.end(),[](pair<int,int>& a,pair<int,int>& b){
        	if(a.second>b.second)
        		return false;
        	else return true;
        });
        vector<int> res;
        int j=0;
        //map支持的是双向迭代器
        for(map<int,int>::iterator i=table.begin();j<k;++i,++j) {
        	res.push_back((*i).second);
        }
        return res;
    }
};

//采用priority_queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(!nums.size()) return vector<int>();
        vector<int> res;
        unordered_map<int,int> table;
        for(int e :nums) {
        	++table[e];
        }
        priority_queue<pair<int,int>> heap;
        for(auto e : table) {
        	heap.push(make_pair(e.second,e.first));
        }
        for(int i=0;i<k;++i) {
        	res.push_back(heap.top().second);
        	heap.pop();
        }
        return res;
    }
};

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(!nums.size()) return vector<int>();
        vector<int> res;
        unordered_map<int,int> table;
        for(int e :nums) {
        	++table[e];
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;//注意对于元素是pair对按照第一个元素的大小进行排序所以底层实现的模板参数都得是pair类型
        for(auto e : table) {
        	heap.push(make_pair(e.second,e.first));
            if(heap.size()>k)//采用的是小根堆的实现，所以最大的在最底下，如果堆的元素超过了k说明堆顶的元素必然不是我们需要的范围内，直接pop掉，减少后续插入元素的比较次数
        		heap.pop();
        }
        for(int i=0;i<k;++i) {
        	res.insert(res.begin(),heap.top().second);//注意这里第一个参数是迭代器
        	heap.pop();
        }
        return res;
    }
};




class Solution {
public:
    class MyComp
    {
        public:
            bool operator ()(const std::pair<int, int>& a, const std::pair<int, int>& b)
            {
                return a.second > b.second;
            }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 0)   return {};

        std::unordered_map<int, int> myMap;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, MyComp> pq;

        for (auto& n : nums)
        {
            auto mp = myMap.find(n);

            if (mp == myMap.end())
            {
                myMap.emplace(n, 1);
            }
            else
            {
                mp->second += 1;
            }
        }

        for (auto& mp : myMap)
        {
            if (pq.size() < k)
                pq.emplace(mp.first, mp.second);
            else
            {
                if (mp.second > pq.top().second)
                {
                    pq.pop();
                    pq.emplace(mp.first, mp.second);
                }
            }
        }

        std::vector<int> res;

        while (pq.size() > 0)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};



