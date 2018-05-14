//分析:将一个数组分成几个部分，每个部分单独排序
//然后再拼起来就得到排好序的数组
//排序是从小到大排序
//求可以分成的最大组数

//时间复杂度o(n) 空间复杂度o(1)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(!n) return 0;
        if(n==1) return 1;
        int count = 0;
        for(int i=0;i<n;++i) {
        	int temp = arr[i] - i;
        	arr[i] = temp;
        }
        int sum = 0;
        for(int i=0;i<n;++i) {
        	sum += arr[i];
        	if(sum==0) ++count;
        }
        return count;
    }
};


//此方法更好
//理解：使用一个imax进行标识
//从0开始如果遍历到的元素大于imax，imax就被修改为当前元素值
//说明到imax位置之间的数都在一组
//当当前i等于imax的时候说明前面所有的元素中的最大值等于i说明后面的元素与前面的元素
//不在一组，此时组数加一
//只需要一次遍历，不用改变原始数组
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ret = 0, imax = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(imax < arr[i]) imax = arr[i];
            if(imax == i) ++ret;
        }
        return ret;
    }
};