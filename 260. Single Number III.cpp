/*
分析：找到数组当中只出现一次的两个数其他的都出现2次
要求线性的复杂度和常数空间复杂度
之前的方式是采用map的方式 这样的话空间复杂度就不是常数

还有一种方式是异或
1 2 3 4 0 7 8 0 5 6 7 8 5
[1, 2, 1, 3, 2, 5, 4, 4]
12
1123
11223445
[11223445]
[1, 2, 1, 3, 2, 5, 1, 2, 1, 3, 2, 5]
中间的异或值如果是0表示目前为止没有找到单个的
用一个变量保存中间值如果上一个值为0就保存否则不变
这样就可以得到第一个数
最后再反解出第二个数

任意一个数（不管奇偶），都可以表示成 2^t + 2^y + 2^z+......，
如果z是t y z中的min，那么x&(-x)=2^z，奇数只不过是min=0时候的一个特例，按比特表示时候，表现为获取最后一个bit（代表的数

 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;int b = 0;
        vector<int> res;
        for(auto each : nums) {
        	int t = b;
        	b = b^each;
        	if(t==0&&b!=0)
        		temp = b;
        }
        res.push_back(temp);
        res.push_back(b^temp);
        return res;
    }
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r = 0, n = nums.size(), i = 0, last = 0;
        vector<int> ret(2, 0);

        for (i = 0; i < n; ++i)
            r ^= nums[i];//r为要求的两个数的异或值

        last = r & (~(r - 1));//r中最后一位为1的位 将其余位置为0
        for (i = 0; i < n; ++i)//将其与所有的数相异或 会将所有的数分为两类一类是该位为1 一类该位为0
        {
            if ((last & nums[i]) != 0)
                ret[0] ^= nums[i];//所有该位为1的必然包含一个单独的数其余都是一对
            else
                ret[1] ^= nums[i];
        }

        return ret;
    }
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        if (nums.size() < 2) {
            return result;
        }
        int x = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            x ^= nums[i];
        }
        x &= (-x);//得到最后一位为1的位
        //这个是得到x最后一位为1的位构成的数 这个数只有这一位为1
        //对于奇数得到的结果就是1
        //对于偶数得到的就是最后一位为1的位
        for (auto i : nums) {
            if (i & x) {
                result[0] ^= i;
            } else {
                result[1] ^= i;
            }
        }
        return result;
    }
};