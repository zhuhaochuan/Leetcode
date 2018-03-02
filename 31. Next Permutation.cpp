/*
1 4 5 6
1 4 6 5
1 5 4 6
1 5 6 4
1 6 4 5
1 6 5 4
4 1 5 6
4 1 6 5
4 5 1 6
4 5 6 1
.......
6 5 4 1
将序列拆分
先将给定的数字进行排序
这道题目就是得到给定的数字排列的下一个排列
关键就是从后往前去寻找关键位置设定处理算法
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), i;
        for(i=len-1;i>0;) {
        	if(nums[i]<=nums[i-1]) --i;
        	else break;
        }//这里使用一个while循环更简洁
        cout << i << endl;
        if(i==0)
        	sort(nums.begin(),nums.end());
        else {
        	int temp = 0;
        	for(int j=len-1;j!=i-1;j--) {
        		if(nums[j]>nums[i-1]) {//这里可以采用swap函数交换两个变量的内容
        			int temp = nums[j];
        			nums[j] = nums[i-1];
        			nums[i-1] = temp;
        			break;
        		}
        	}
        	sort(nums.begin()+i,nums.end());
        }
    }
};


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), flag = 1, index = len - 1;
        for (int i = len - 1; i>0; i--){
            if (nums[i] <= nums[i - 1]) index--;
            else{
                for (int j = len - 1; j >= index; j--){
                    if (nums[j]>nums[i - 1]){
                        swap(nums[i - 1], nums[j]);
                        break;
                    }
                }
                sort(nums.begin() + i , nums.end());
                flag = 0;
                break;
            }
        }
        if (len&&flag) sort(nums.begin(), nums.end());
    }
};