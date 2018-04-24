

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(!ransomNote.size()) return true;
        if(ransomNote.size()&&!magazine.size()) return false;
        unordered_map<char,int> table;//不需要排序的时候 使用unordered
        for(char c : magazine) {
            ++table[c];
        }
        for(char c : ransomNote) {
            if(!table[c]) return false;
            else
                --table[c];
        }
        return true;
    }
};




class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);

        for (auto a : ransomNote) ++count[a - 'a'];
        for (auto a : magazine) --count[a - 'a'];

        for (int i = 0; i < 26; i++) if (count[i] > 0) return false;

        return true;
    }
};