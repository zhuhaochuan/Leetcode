/*
分析：找到数组当中下一个比当前数字大的数字
可以循环搜索整个数组
如果不存在比这个数大的数返回-1
Input: [1,2,1]
Output: [2,-1,2]
[1,2,1,2,3,2,4,2,1]
4
比当前数下一个大的有这样几种情况：
1.当前数后面有数比他大，那么这个下一个数就在当前数的后面
2.如果当前数后面没有比这个数大的数，那么有两种可能比这个数大的数可能在这个数前面。也可能这个数就是当前数组当中最大的数
 */

//暴力解：o(n*n)时间复杂度
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(!nums.size()) return vector<int> ();
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n;++i) {
        	for(int j=(i+1)%n;j<n;j =(j+1)%n) {
        		if(j==i) {
        			res.push_back(-1);
        			break;
        		}
        		else if(nums[j]>nums[i]) {
        			res.push_back(nums[j]);
                    break;
                }
        	}
        }
        return res;
    }
};

//使用栈将事件复杂度下降到o(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(!nums.size()) return vector<int> ();
        int n = nums.size(),count = 1;//count计数，如果超过2n就停止

        vector<int> res(nums);
        stack<pair<int,int>> s;
        s.push(pair<int,int>(0,nums[0]));

        for(int i=1;count<=2*n-1&&i<n;i = (i+1)%n) {
            ++count;
        	while(!s.empty()&&nums[i]>s.top().second) {//每次进来的数将前面所有小于这个数的元素压出栈
        		if(res[s.top().first]==nums[s.top().first]) {
        			res[s.top().first] = nums[i];
        		}
        		s.pop();
        	}
        	s.push(pair<int,int> (i,nums[i]));//当前元素入栈
        }

        while(!s.empty()) {//将栈中剩下的最大的数对应的位置赋值为-1
            res[s.top().first] = res[s.top().first]==nums[s.top().first]?-1:res[s.top().first];
            s.pop();

        }
        return res;
    }
};

//另一种思路 从后向前将元素进栈
//
class Solution {
/*
*  0 2 3 1 5   moni decrease stack
*->2 3 5 5 -1
5

* while cur >= stack.top():
*     stack.pop()
* stack.push(cur)
*
*/
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return nums;

        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        st.push(nums[n-1]);

        for (int i = 2*n-2; i>=0; i--) {
            while (!st.empty() && nums[i%n] >= st.top()) {
                st.pop();
            }

            if (!st.empty()) res[i%n] = st.top();

            st.push(nums[i%n]);
        }

        return res;
    }
};