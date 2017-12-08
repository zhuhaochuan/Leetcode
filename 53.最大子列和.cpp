
//最大子列和
//9ms
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	if(nums.size()==1) return nums[0];
        int max = -1000;
        int cur = 0;
        for(int i=0;i<nums.size();i++) {
   			cur += nums[i];
   			if(cur>max) 
   				max = cur;
   			if(cur<0)
   				cur = 0;     	
        }
        return max;
    }
};


//6ms  递归分治
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = nums[0], sum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};