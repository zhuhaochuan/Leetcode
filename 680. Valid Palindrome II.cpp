/*删除最多一个字符 判断可否形成回文字符串
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
"abaadba"
*/
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        if(n<3) return true;
        int l = 0,r = n-1,tag = 0;
        return helper(s,0,n-1,0);
    }

    bool helper(string& s,int l,int r,int tag) {
    	if(l>=r) return true;
    	if(s[l]!=s[r]&&tag) {
    		return false;
    	}
    	else if(s[l]!=s[r]&&!tag) {
    		return helper(s,l+1,r,1)||helper(s,l,r-1,1);
    	}
    	else if(s[l]==s[r]) {
    		return helper(s,l+1,r-1,tag);
    	}
    }
};


class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]) return isValid(s, left, right - 1) || isValid(s, left + 1, right);
            ++left; --right;
        }
        return true;
    }

    bool isValid(string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right])  return false;
            ++left; --right;
        }
        return true;
    }
};