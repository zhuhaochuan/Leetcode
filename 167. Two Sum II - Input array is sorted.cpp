/*
分析：返回数组当中和为目标值的元素的位置，相对位置
每个元素只能使用一次,原始数组是升序排序。
 */

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size()<2) return vector<int> ();
        int n = numbers.size();
        int begin = 0, end = n-1;
        vector<int> res(2,0);
        while(begin<end) {
        	if(numbers[begin]+numbers[end]<target)
        		++begin;
        	else if(numbers[begin]+numbers[end]>target)
        		--end;
        	else {
        		res[0] = begin+1;
        		res[1] = end+1;
                break;
        	}
        }
        return res;
    }
};