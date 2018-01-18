/*
分析：给定一个数组 和一个目标值
返回数组中哪2个值得和可以得到这个目标值 返回对应的下标
这样的结果只有一组 一个元素不能使用两次 也就是返回的两个下标必然不同

想法：没说这些数是正整数 可能出现0和负数
	遍历一遍数组 将数组当中的元素和该元素-目标的差值放进multimap当中
	最后遍历一遍map取出出现两次的元素

	最后的结果就是思路和最后的实现表明整个算法的思路是完全ok的 时间复杂度也就是o(n)
	但是问题出现在写的过程中出现了一些bug 由于可能原始数组当中会出现重复的数字
	那么在判断是否出现过就需要追加判断 和是否满足等于target 否则不是我们需要的结果
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,pair<int,int>> table;//成对的不用再写个结构体 直接用pair模板类
        vector<int> res(2,-1);//vector最好先初始化
        for(int i=0;i<nums.size();i++) {
        	unordered_map<int,pair<int,int>>::iterator it = table.find(nums[i]);
        	if(it==table.end())
        		table[nums[i]] = pair<int,int>(i,1);//这里注意生成一个临时变量
        	else {
        		if(it->second.second&&nums[i]+nums[it->second.first]==target) {//对于多种情况的考虑 是否出现重复
        			res[0] = it->second.first;
        			res[1] = i;
        			return res;//找到的时候及时终止返回结果
        		}
        		table.find(nums[i])->second.second++;
        	}
        	int temp = target - nums[i];
        	if(table.find(temp)==table.end()) {
        		table[temp] = pair<int,int>(i,1);
        	}
        }
        return res;
    }
};

//思路我看一致。。但是为啥他这么简单
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        using vType = remove_reference_t<decltype(nums)>::size_type;

        unordered_map<int,vType> m ;

        for (int i = 0; i < nums.size(); ++i) {
            const auto it = m.find(target - nums[i]);
            if (it != m.end())
                    return vector<int> {it->second,i};
            m.emplace(nums[i],i);
        }
        throw std::runtime_error("no solutions:") ;
    }
};