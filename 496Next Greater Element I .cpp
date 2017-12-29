/*
分析：简单的暴力匹配算法的时间复杂度必然是很高的
首先肯定是需要遍历要匹配的数组
需要先找到当前处理到的这个值在原数组中的位置
可以用一个map取存储<当前处理的值，在原数组的位置>这样的键值对
在处理前面的数的时候就将过程中的直接插入到map当中
这样后面遇到的数也许就不要再遍历原数组
其次就是找到了位置之后需要找到这个位置后第一个比这个数大的数的值
这个就需要往后一个一个比较大小 如果有就得到值如果没有就返回-1

直接遍历整个原始数组将所有的值和位置都插入map当中不是更好么。。。
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if(!nums.size()) return nums;
        int len = nums.size();
        unordered_map<int,int> m;
        vector<int> v;

        for(int i=0;i<len;i++) m[nums[i]] = i;
        for(each : findNums) {
        	if(m[each]==len-1)
        		v.push_back(-1);
    		else {
    			for(int i=m[each]+1;i<len;i++) {
    			m[nums[i]] = i;
    			if(nums[i]>each) {
    				v.push_back(nums[i]);
    				break;
    			}
    			if(i==len-1&&each>=nums[i])
    				v.push_back(-1);
    			}
    		}
        }
        return v;
    }
};


//这个答案和我想法一致 都是用一个map将所有的已知的数和位置的键值对存储起来
//在对于没有找到情况下的处理这个答案写的很好 先设置一个默认值 -1当找到了就修改
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]=i;

        for(int i=0; i<findNums.size(); i++){
            int newval=-1;
            for(int j=mp[findNums[i]]+1; j<nums.size(); j++){
                if(findNums[i]<nums[j]) {
                    newval=nums[j];
                    break;
                }
            }
            res.push_back(newval);
        }
        return res;
    }
};



