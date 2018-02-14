/*
分析：给定一个数组，删除所有给出的数字
返回删除后的数组的长度len 并且将数组的前len个元素构造成新的数组

 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(!nums.size()) return 0;
        int len = nums.size(),count = 0;
        for(int i=0;i<len;i++) {
        	if(nums[i]!=val) {
        		nums[count++] = nums[i];
        	}
        }
        return count;
    }
};



class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        if( sz == 0 ) return 0;
        while( nums[sz-1] == val && sz >0 ) sz--;
        for( int i=0; i<sz; ++i){
            if( nums[i] == val ) {
                nums[i] = nums[sz-1];
                sz--;
                while( nums[sz-1] == val ) sz--;
            }
        }
        nums.resize(sz);
        return sz;
    }
};