/*
回文子串问题：找到一串字符串当中的最大回文子串
字符串 最大值 必然是动态规划
 */


//写的一坨屎
class Solution {
public:
    string longestPalindrome(string s) {
        string res;int max = 0;int l = 0,r = 0;
        for(int i=0;i<s.size();i++) {
        	int j=1,count = 1;
        	while(i-j>=0&&i+j<s.size()) {
        		if(s[i-j]==s[i+j])
        			count += 2;
        		else break;
        		j++;
        	}
        	if(s[i]==s[i-1]) {
        		int t = 0,temp = 0;
                while(i-1-t>=0&&i+t<s.size()) {
                	if(s[i-1-t]==s[i+t])
                		temp += 2;
                	else break;
                	t++;
                }
                if(temp>count&&temp>max) {
                	l = i - 1 - t + 1;
                	r = i + t - 1;
                	max = count = temp;
                }else if(count > max){
                	max = count;
                	l = i - j + 1;
                	r = i + j - 1;
                }
        	}
    	}
        return res = s.substr(l,r+1);
  	}
};

//dp 按照斜线从中间网上填充DP矩阵的描述方式
class Solution {
public:
    string longestPalindrome(string s) {
    	int n = s.size(),max = 0,index = 0;string res;
    	vector<vector<int>> dp(n,vector<int>(n,0));
    	for(int temp=0;temp<n;temp++) {
    		for(int i=0;i<n-temp;i++) {
    			int j = temp + i;
    			if(i==j) dp[i][j] = 1;
    			else if(j==i+1) {
    				if(s[i]==s[j]) {
		    			dp[i][j] = 1;
		    			if(max<1) {
		    				index = i;
		    				max = 1;
		    			}
		    		}
    			}
    			else if(dp[i+1][j-1]==1&&s[i]==s[j]) {
    				dp[i][j] = 1;
    				if(j-i>max) {
    					max = j-i;
    					index = i;
    				}
    			}
    		}
    	}
    	return res = s.substr(index,max+1);//这里注意加一
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
            if (s.size() -i <= max_len / 2) break;
            int j = i, k = i;
            while (k < s.size() && s[k+1] == s[k]) k++;
            i = k+1;
            while(k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j;}
            int new_len = k - j + 1;
            if (new_len > max_len) {min_start = j; max_len = new_len;}
        }
        return s.substr(min_start, max_len);

    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), len = 0, start = 0;
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            while(right < n && s[right+1] == s[right]) right++;
            i = right;
            while(left > 0 && right < n-1 && s[left-1] == s[right+1]){
                left--;
                right++;
            }

            if(len < right-left+1){
                len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, len);
    }
};