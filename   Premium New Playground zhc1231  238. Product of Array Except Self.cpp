class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(!nums.size()) return vector<int> ();
        int n = nums.size();
        vector<int> res(n,0);
        int temp = 1;
        res[0] = 1;
        for(int i=1;i<n;++i) {
            res[i] = nums[i-1] * res[i-1];
        }
        for(int i=n-1;i>=0;--i) {
            res[i] *= temp;
            temp *= nums[i];
        }
        return res;
    }
};