class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n = nums.size();
        int res = 0,temp = 0;
        for(int i=0;i<n;++i) {
            if(nums[i]>=0) {
                ++temp;
                int next = nums[i];
                nums[i] = nums[i]==0?-1:-nums[i];
                while(next>=0&&nums[next]>=0) {
                    int t = nums[next];
                    nums[next] = nums[next]==0?-1:-nums[next];
                    next = t;
                    ++temp;
                }
                res = max(temp,res);
                temp = 0;
            }
        }
        return res;
    }
};


class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        size_t maxsize = 0;
        for (int i = 0; i < nums.size(); i++) {
            size_t size = 0;
            for (int k = i; nums[k] >= 0; size++) {//巧用循环判断条件
                int numk = nums[k];
                nums[k] = -1; // mark nums[k] as visited;
                k = numk;
            }
            maxsize = max(maxsize, size);
        }

        return maxsize;
    }
};