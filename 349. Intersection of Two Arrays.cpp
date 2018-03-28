/*
求两个集合的交集
交集中每个元素只出现一次
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> table;
        vector<int> res;
        for(int e : nums1) {
        	++table[e];
        }
        for(int e : nums2) {
        	if(table[e]==-1) continue;
        	if(table[e]){
        		table[e] = -1;
        		res.push_back(e);
        	}
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
        if (m.count(a))
        {
            res.push_back(a);
            m.erase(a);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s(nums1.begin(),nums1.end());
        vector<int> res;
        for(int i=0;i<nums2.size();i++)
            if(s.count(nums2[i]))
            {
                res.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        return res;
    }
};