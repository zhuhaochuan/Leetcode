class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(!nums.size()) return vector<vector<int>> ();
        vector<vector<int>> res;
        int n =  nums.size();
        for(int i=0;i<n;++i) {
        	int m = res.size();
        	for(int j=0;j<m;++j) {
        		vector<int> temp = res[j];
        		temp.push_back(nums[i]);
        		res.push_back(temp);
        	}
        	res.push_back(vector<int> (1,nums[i]));
        }
        res.push_back(vector<int>());
        return res;
    }
};
