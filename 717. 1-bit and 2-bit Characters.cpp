/*
分析：判断最后一个字符是否能识别为一个单bit字符

 */
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(!bits.size()) return false;
        int n = bits.size();
        if(n==1) return bits[0]==0;
        for(int cur=0;cur<n;) {
        	if(bits[cur]==1) {
        		cur += 2;
        		if(cur==n) return false;
        	}
        else ++cur;
        }
        return true;
    }
};


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ones = 0;
        //Starting from one but last, as last one is always 0.
        for (int i = bits.size() - 2; i >= 0 && bits[i] != 0 ; i--) {
            ones++;
        }
        if (ones % 2 > 0) return false;
        return true;
    }
};