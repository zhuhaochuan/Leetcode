/*
分析：找到数组当中需要排序之后原始数组也排好序的最短连续长度
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()<2) return 0;
        pair<int,int> max;
        int r = -1,l = 0;
        max.first = -1;
        max.second = INT_MIN;
        for(int i=0;i<nums.size();++i) {
            if(max.second>nums[i]) {
                if(r==-1)
                    l = max.first;
                r = i;
            }
            else if(max.second<nums[i]) {
                max.second = nums[i];
                max.first = i;
            }
        }
        return r-l+1;
    }
};


/*
分析：找到数组当中需要排序之后原始数组也排好序的最短连续长度
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()<2) return 0;
        stack<pair<int,int>> s;
        int max = nums[0],l = INT_MAX,r = -1;
        s.push(make_pair(nums[0],0));
        for(int i=1;i<nums.size();++i) {
            if(nums[i]>=s.top().first) {
                r = nums[i]<max?i:r;
                max = nums[i]>max?nums[i]:max;
                s.push(make_pair(nums[i],i));
            }
            else {
                int temp = l;
                while(!s.empty()&&nums[i]<s.top().first) {
                    temp = s.top().second;
                    s.pop();
                }
                l = temp<l?temp:l;
                s.push(make_pair(nums[i],i));
                r = i;
            }
        }
        if(l==INT_MAX&&r==-1)
            return 0;
        return r-l+1;
    }
};