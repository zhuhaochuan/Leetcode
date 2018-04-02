/*
分析：求两个集合的交集
输出没有顺序
 */

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size()||!nums2.size()) return vector<int>();
        map<int,int> table;
        for(int e : nums1) {
        	++table[e];
        }
        vector<int> res;
        for(int e : nums2) {
        	if(table[e]) {
        		res.push_back(e);
        		--table[e];
        	}
        }
        return res;
    }
};


//先排序，再使用2个指针的方式进行
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ret;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); )
        {
            if (nums1[i] == nums2[j])
            {
                ret.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ret;
    }
};