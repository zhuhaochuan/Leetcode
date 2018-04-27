
//分析：一次遍历  按照大小从小到大排序0 1 2
//我原始的想法就是将遇到的0放在前面zero表示可以放0的下一个位置
//遇到2就放到最后two处，但是不可能将two处的元素直接覆盖如果是1倒是无所谓，但是如果是0
//那么覆盖掉就错了，我的想法是如果two位置是0就再讲其放到当前的zero处
//zero一定小于等于当前遍历到的i所以前面处理的元素一定不会出现2所以直接将zero处覆盖为0
//对于1我们是不处理的，最后在zero~two这个区间内的元素都是1
//最后需要遍历这个区间将其全部覆盖为1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return;
        int zero = 0, two = n-1;
        for(int i=0;i<=two;++i) {
            if(nums[i]==2) {
                while(nums[two]==2&&two>=i) --two;
                if(two<=i) break;
                if(nums[two]==0) {
                    nums[zero] = 0;
                    nums[two] = 2;
                    --two;
                    ++zero;
                }
                else {
                    nums[two] = 2;
                    --two;
                }
            }
            else if(nums[i]==0) {
                nums[zero] = 0;
                ++zero;
            }
        }
        for(int i=zero;i<=two;++i)
            nums[i] = 1;
        return;
    }
};

//这个方法是改进版本
//不需要再最后处理1的问题
//只需要处理在遇到2的时候将two位置元素和当前为2的元素交换位置，再将i-1
//下次继续判断交换过来的这个元素的值如果是0处理到0的位置也不会漏0如果是1就不会处理这样1就相当于被搬回对应的位置
//当遇到0的时候直接交换i和zero位置的元素就可，因为前面的2肯定被处理了不会再换过来2，所以i不用回去1位。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int zero_index = 0;
        int two_index = len-1;
        for(int i=0; i<=two_index; i++){
            if(nums[i]==0)
                swap(nums[i], nums[zero_index++]);
            else if(nums[i]==2)
                swap(nums[i--], nums[two_index--]);
        }
        return;
    }
};