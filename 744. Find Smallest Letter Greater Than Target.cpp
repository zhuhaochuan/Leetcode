/*
分析：从给定的字母列表里找到第一个比目标字母大的字母
所有的字母都已经排好序

 */

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0);return 0;}();
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(!letters.size()) return char();
        int begin = 0, end = letters.size()-1;
        int mid = 0;
        if(target>=letters[letters.size()-1]) return letters[0];
        while(begin<=end) {//此处必须有等号
        	mid = begin + ((end - begin)>>1);
        	if(letters[mid]>target) {
                end = mid - 1;//end 最终的位置的元素可能小于等于目标值
            }
        	else {
                begin = mid + 1;//如果mid小于等于目标值 那么begin就为mid+1：begin最终肯定是大于目标值的最小的那个位置
            }
        }
        return letters[begin];
    }
};