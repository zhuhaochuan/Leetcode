/*
分析：给出一组正整数 连续相除 添加适当的括号改变优先级 使得结果最大
原本优先级是从左往右
关键点1：最后一次的除法的被除数必然不会大于数组第一个数
关键点2：其实就是使用优先级的不同让后面的数计算出一个最小的数
那么问题现在变成求nums[1]..nums[n]组成的最小值
那么如果改变之后的优先级 带来的结果就是nums[1]除的数变小结果必然不会比不改变这些优先级来的小
比如 100 10 4 100 2
100/(100/10/4/100/2)

 */


class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(!nums.size()) return NULL;
        string res; int len = nums.size();
        //两种特殊长度不需要添加括号 特殊处理
        if(len==1) return res+=to_string(nums[0]);
        if(len==2) {
        	res += to_string(nums[0]);
        	res += '/';
        	res += to_string(nums[1]);
            return res;
        }
        //一般情况
        res += to_string(nums[0]);
        res += '/';
        res += '(';
        for(int i=1;i<len;i++) {
            if(i>1)
                res += '/';
        	res += to_string(nums[i]);
        }
        res += ')';
        return res;
    }
};


class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        if(!nums.size()) return ans;
        ans = to_string(nums[0]);
        if(nums.size()==1) return ans;
        if(nums.size()==2) return ans + "/" + to_string(nums[1]);
        ans += "/(" + to_string(nums[1]);
        for(int i = 2; i < nums.size();++i)
            ans += "/" + to_string(nums[i]);
        ans += ")";
        return ans;
    }
};