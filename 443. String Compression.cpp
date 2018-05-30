//压缩字符串
//["a","a","b","b","c","c","c","a"]
//["a","2","b","2","c","3","a"]

class Solution {
public:
    int compress(vector<char>& chars) {
        if(!chars.size()) return 0;
        int n = chars.size();
        int count = 1,j = 1;
        for(int i=1;i<n;++i) {
        	if(chars[i]==chars[i-1]) {
        		++count;
        	}
        	else {
        		if(count>1) {
        			string ss = to_string(count); //转换成string在从头赋值这样就搞定了
        			for(auto e:ss) {
        				chars[j] = e;
        				++j;
        			}
	        	}
        		chars[j] = chars[i];
        		++j;
        		count = 1;
        	}
        }
        chars[j] = chars[n-1];
        if(count>1) {
			string ss = to_string(count);
			for(auto e:ss) {
				chars[j] = e;
				++j;
			}
    	}
    	return j;
    }
};