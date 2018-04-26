
//分析：删除原字符串当中某些字符得到字典当中最长的且靠前的匹配字符串
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        if(!s.size()) return "";
        sort(d.begin(),d.end(),[](const string& a,const string& b) {
            if(a.size()>b.size())
                return true;
            if(a.size()==b.size())
                return a<b;
            else return false;
        });
        for(string each : d) {
            if(helper(each,s))
                return each;
        }
        return "";
    }
    bool helper(const string& c,const string& s ) {
        if(c.size()>s.size()) return false;
        int id = -1;
        for(int i=0;i<c.size();++i) {
            if(id==s.size()) return false;
            for(id = id + 1;id<s.size();++id) {
                if(c[i]==s[id])
                    break;
            }
        }
        return !(id==s.size());
    }
};
