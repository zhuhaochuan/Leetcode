static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0,max = INT_MIN,n = nums.size();
        int l = 1,r = k;
        sum = accumulate(nums.begin(),nums.begin()+k,0);
        max = sum;
        while(r<n) {
            sum += nums[r];
            sum -= nums[l-1];
            if(sum>max) max = sum;
            ++l;
            ++r;
        }
        return (double) max / k;
    }
};