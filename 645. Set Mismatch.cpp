
/*
分析：先找到重复的元素，再找到丢失的元素
2 3 3 4 5 6
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        if(!nums.size()) return vector<int> ();
        sort(nums.begin(),nums.end());
        vector<int> res;
        int n = nums.size();
        int pre = nums[0],sum = (n+1)*n/2 - nums[0];
        for(int i=1;i<n;++i) {
            sum -= nums[i];
            if(nums[i]==pre) {
                res.push_back(nums[i]);
            }
            pre = nums[i];
        }
        res.push_back(sum+res[0]);
        return res;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        int missingNo = 0;
        int dupNo = 0;
        for(int i = 0;  i < nums.size(); i++){
            if(nums[abs(nums[i])-1] > 0){
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }else{
                dupNo = abs(nums[i]);
            }
        }
        cout<<dupNo;
        for(int i = 0;  i < nums.size(); i++){
            if(nums[i] > 0){
                missingNo = i+1;
                break;
            }
        }
        result.push_back(dupNo);
        result.push_back(missingNo);
        return result;
    }
};