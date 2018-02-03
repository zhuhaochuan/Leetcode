/*
分析：找出四个数的和为目标数 得到所有的解 不能重复
先对所有的元素进行排序
将4sum转化为3sum
将3sum转化为2sum

想法ok
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size()==0) return res;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=0;i<len-3;i++) {
            if(i>0&&nums[i]==nums[i-1]) continue;//跳过重复
        	int target3sum = target - nums[i];
            if((nums[i]>0)&&(target3sum<0)) break;//提前终止
        	for(int j=i+1;j<len-2;j++) {
                if(j!=i+1&&nums[j]==nums[j-1])
                    continue;
        		int target2sum = target3sum - nums[j];
                if(nums[j]>0&&target2sum<0) break;
        		int l = j+1,r = len-1;
        		while(l<r) {
        			if(l!=j+1&&nums[l]==nums[l-1]) {
                        ++l; continue;
                    }
        			if(target2sum == nums[l]+nums[r]) {
        				vector<int> temp{nums[i],nums[j],nums[l],nums[r]};
        				res.push_back(temp);
                        ++l;--r;
        			}
        			else if(target2sum < nums[l]+nums[r]) --r;
        			else if(target2sum > nums[l]+nums[r]) ++l;
        		}
        	}
        }
        return res;
    }
};



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};//这特么可以？
        vector<vector<int>> res;
        auto v = nums;
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && v[i] == v[i - 1]) continue;
            /*
            就是说 如果前四项相加的和已经大于目标数 当前以及后面的数都不能满足直接break
            如何这项加上最后三项的和小于目标 说明当前的数小了直接continue跳过这个数
             */
            if (v[i] + v[i + 1] + v[i + 2] + v[i + 3] > target) break;
            if (v[i] + v[n - 3] + v[n - 2] + v[n - 1] < target) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && v[j] == v[j - 1]) continue;
                if (v[i] + v[j] + v[j + 1] + v[j + 2] > target) break;
                if (v[i] + v[j] + v[n - 2] + v[n - 1] < target) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int sum = v[i] + v[j] + v[l] + v[r];
                    if (sum < target) {
                        ++l;
                    } else if (sum > target) {
                        --r;
                    } else {
                        res.push_back({ v[i], v[j], v[l], v[r] });
                        for (++l; l < r && v[l] == v[l - 1]; ++l) continue;
                        for (--r; l < r && v[r] == v[r + 1]; --r) continue;
                    }
                }
            }
        }
        return res;
    }
};