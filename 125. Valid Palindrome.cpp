/*
分析：给出一个字符串，判断是不是回文串 忽略所有的空格和其他字符只考虑数组和字母，字母不区分大小写
"A man, a plan, a canal: Panama" is a palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        if(len<2) return true;
        int l = 0,r = len-1;
        while(l<r) {
        	if(isalnum(s[l])&&isalnum(s[r])) {
        		if(!isdigit(s[l])&&tolower(s[l])!=tolower(s[r]))
        			return false;
                else if(isdigit(s[l])&&s[l]!=s[r])
                    return false;
        		++l;
        		--r;
        	}
        	else if(isalnum(s[l])&&!isalnum(s[r]))
        		--r;
        	else if(!isalnum(s[l])&&isalnum(s[r]))
        		++l;
        	else {
        		++l;
        		--r;
        	}
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        else
        {
            auto pf=s.begin(),pl=s.end()-1;
            while(pf<pl)
            {
                if(isalnum(*pf)&&isalnum(*pl))
                {
                    if(tolower(*pf)==tolower(*pl))//如果不是字母字符返回自己
                    {
                        pf++;
                        pl--;
                        continue;
                    }
                    else
                        return false;
                }
                else
                {
                    if(!isalnum(*pf)) pf++;
                    if(!isalnum(*pl)) pl--;
                }
            }
            return true;
        }
    }
};