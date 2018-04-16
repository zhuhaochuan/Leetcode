/*
分析：a,e,i,o,u
调转输入字符串中的元音顺序
eeoe
eoee
abcde
edcba
*/
class Solution {
public:
    string reverseVowels(string s) {
        if(!s.size()) return string();
        int len = s.size();
        int l = 0,r = len;
        while(l<r) {
        	bool tag1 = isvowel(s[l]),tag2 = isvowel(s[r]);
            if(tag1&&tag2) {
            	char temp = s[l];
            	s[l] = s[r];
            	s[r] = temp;
            	++l;
            	--r;
            }
            else if(tag1&&!tag2)
            	--r;
            else if(!tag1&&tag2)
            	++l;
            else {
            	++l;
            	--r;
            }
        }
        return s;
    }

    bool isvowel(char c) {
    	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    		return true;
    	else return false;
    }
};



class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};

//switch空间换时间有一个跳表 在能够找到元素的前提条件下switch的效率更高
//在找不到元素的条件下 二者的效率差不多
class Solution {
public:
    bool isVowel(char c) {
        switch (tolower(c)) {//使用tolower 和toupper 使得字母全部转换为小写或者大写 这样在判断不用大小写区分的问题可以减少一半的判断
            case 'a':
            case 'i':
            case 'e':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }
    string reverseVowels(string s) {
        int size = s.size();
        if (size == 0)
            return s;

        int i = 0, j = size - 1;
        while (i < j) {
            char c1 = s[i];
            char c2 = s[j];
            if (!isVowel(c1)) {
                i++;
                continue;
            }
            if (!isVowel(c2)) {
                j--;
                continue;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};