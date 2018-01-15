/*
分析：给定一个字符串 按照出现的频率递减输出
	区分大小写
	相同出现频率的字符先后都可以
	unordered_map<char,string>
	再对这个map排序
 */


class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char,string> table;
        multimap<int,string> m;
        for(auto each : s) {
        	table[each] += each;
        }
        for(auto each : table) {
            m.insert(pair<int,string>(each.second.size(),each.second));
        }
        multimap<int,string>::reverse_iterator it = m.rbegin();//逆序迭代器的定义和使用
        for(;it!=m.rend();it++) {
        	res += it->second;
        }
        return res;
    }
};

class Solution {
public:
    string frequencySort(string s)
    {
        string ans;
        pair<char, int> freq[256] = { {0, 0} };

        /* Loop through the characters in string and store the character and frequency into the pair */
        for (const auto &c : s) {
            freq[c].first = c;
            ++freq[c].second;
        }
        /* Sort the pair based on frequency from previous loop */
        sort(begin(freq), end(freq),
            [](pair<char, int>& l, pair<char, int>& r) {
            return l.second > r.second;
        });//因为数组支持随机访问所以可以使用sort算法
        /* Append the pair into the string */
        for (auto i = begin(freq); i != end(freq); ++i)
            ans.append(i->second, i->first);//增加多个相同字符组成的字符串
        return ans;
    }
};