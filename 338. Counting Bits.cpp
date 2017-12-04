//For num = 5 you should return [0,1,1,2,1,2].
//00 01 10 11   100 101 110 111   1000 1001 1010 1011   1100 1101 1110 1111
//10000 10001 10010 10011 
// 0 1 1 2  1 2 2 3   1 2 2 3  2 3 3 4    1 2 2 3  2 3 3 4  2 3 3 4  3 4 4 5
//0 1 
// 4 4 8 16 32 64 。。。。
// 2 3 4 5 6 。。。 101 10
// 89 89/2 敏捷devops
//79ms
class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> ans;

    	for(int i=0;i<=num;i++) {
    		int count = 0;
    		int j = i;
    		while(j) {
    			count += j%2;
    			j = j >> 1;
    		}
    		ans.push_back(count);
    	}
        return ans;
    }
};

//59ms
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};