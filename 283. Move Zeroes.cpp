/*
分析：将所有数组当中的0移动到数组的最后[0, 1, 0, 3, 12]
[1, 3, 12, 0, 0]


 */

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(!nums.size()) return;
        int j = 0,n = nums.size();
        for(int i=0;i<n;++i) {
        	if(nums[i]) {
        		nums[j] = nums[i];
        		++j;
        	}
        }
        if(j<=n) {
        	for(;j<n;++j)
        		nums[j] = 0;
        }
        return;
    }
};



class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        for(int prevZero = 0, currPos = 0; prevZero < nums.size(); ++prevZero){
            if(nums[prevZero]){
                if( prevZero != currPos){
                    swap(nums[prevZero],nums[currPos++]);
                } else {
                    currPos++;
                }
            }
        }
    }
};