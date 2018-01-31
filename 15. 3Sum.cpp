/*
分析：一组数组当中 有三个数相加和为0
找到所有这样的组合
S = [-1, 0, 1, 2, -1, -4]
排序 -4 -1 -1 0 1 2

 */


class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        int first = 0, begin = 0, end = 0,len = nums.size();
        for(int i=0;i<len-2;i++) {
        	first = nums[i];
        	if(first > 0) break;
        	begin = i+1;
        	end = len-1;
            unordered_map<int,int> table;
        	while(begin<end) {
                if(i>0&&nums[i]==nums[i-1])
                    break;
        		if((nums[begin]+nums[end])==(-first)&&table.find(nums[begin])==table.end()) {
        			vector<int> temp = {first,nums[begin],nums[end]};
        			res.push_back(temp);
        			table[nums[begin]] = 1;
                    begin++;end--;
        		}
        		else if((nums[begin]+nums[end])<(-first)) {
        			begin++;
        		}
        		else if((nums[begin]+nums[end])>(-first)) {
        			end--;
        		}
                else {//条件判断需要注意死循环 少一个情况的描述 就会带来这样的问题
                    begin++;end--;
                }
        	}
        }
        return res;
    }
};



//写的清晰明了 值得学习
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0) break;//对的 当前第一个数大于0 必然后面都大于0 不需要再找
            if(i>0&&nums[i]==nums[i-1]) continue;
            int target = -1*nums[i];
            int left = i+1, right = nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]==target){
                    result.push_back({nums[i], nums[left++], nums[right--]});
                    while(left<right&&nums[left]==nums[left-1])  left++;//直接跳过
                    while(left<right&&nums[right]==nums[right]+1) right--;
                }
                else if(nums[left]+nums[right]<target) left++;
                else right--;
            }
        }
        return result;
    }
};