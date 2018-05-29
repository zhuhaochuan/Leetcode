//找出除了禁止单词列表当中出现次数最多的单词
//原始段落部分大小写，不在意标点符号
//paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
//banned = ["hit"]
//Output: "ball"

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        if(!paragraph.size()) return string ();
        int n = paragraph.size(),m = banned.size();
        string res,temp;
        unordered_map<string,int> table;
        for(int i=0;i<n;++i) {
        	if(paragraph[i]>='a'&&paragraph[i]<='z'||paragraph[i]>='A'&&paragraph[i]<='Z') {
        		temp.push_back(tolower(paragraph[i]));
        	}
        	else {
        		if(temp.size()) ++table[temp];
        		string s;
        		temp = s;
        	}
        }
        for(auto e : banned) {
        	table[e] = -1;
        }
        if(temp.size()) ++table[temp];
        int count = 0;
        for(auto each : table) {
        	if(each.second>count) {
        		count = each.second;
        		res = each.first;
        	}
        }
        return res;
    }
};