//找到一组无序的整型数组当中未出现的正整数当中最小的那个
//使用o(n)的时间复杂度 和常数的空间
//找到数组当中最小的整数值然后

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 1;

        for(int i=0;i<n;++i) {
        	if(nums[i]==i+1) continue;
        	while(nums[i]<=n&&nums[i]>0&&nums[i]!=nums[nums[i]-1]) {
        		int temp = nums[nums[i]-1];
        		nums[nums[i]-1] = nums[i];
        		nums[i] = temp;
        	}
        }
        int i = 0;
        for(i=0;i<n;++i) {
        	if(nums[i]!=i+1)
        		break;
        }
        return i+1;
    }
};