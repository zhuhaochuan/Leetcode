static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()<2) return 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        int res = 0,pre = nums[0]-1;
        for(int i=0;i<n;++i) {
            //m[nums[i]]=1;
            if(nums[i]!=pre&&m[nums[i]-k]==1) {
                m[nums[i]-k] = 0;
                ++res;
                pre = nums[i];
            }
            m[nums[i]]=1;
        }
        return res;
    }
};