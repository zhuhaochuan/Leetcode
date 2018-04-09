/*
k步旋转数组
with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
简单来说就是将最后的k个元素和前n-k个元素调换位置
只能在原始数组上进行更改
 */


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return;
        for(int i=1;i<=k;++i) {
        	vector<int> temp(nums.begin(),nums.end()-1);
        	temp.insert(temp.begin(),nums[n-1]);
        	nums.swap(temp);
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();//等效操作因为如果k==n相当于没有操作
        vector<int> temp = nums;
        for (int i=0;i<nums.size();++i) {
            temp.at(i) = nums.at((i+nums.size()-k)%nums.size());//神操作 循环到数组的头部 使用对长度取余的操作
        }
        nums = temp;
    }
};
