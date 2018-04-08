/*
分析：将两个排好序的数组，组合成一个新的排好序的数组
1 3 4 5
2 4 5 7
1 2 3 4 4 5 5 7
*/
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        queue<int> q;
        int i = 0,j = 0;
        while(i<m&&j<n) {
            if(nums1[i]<nums2[j]) {
                q.push(nums1[i]);
                ++i;
            }
            else if(nums1[i]>nums2[j]) {
                q.push(nums2[j]);
                ++j;
            }
            else {
                q.push(nums1[i]);
                q.push(nums2[j]);
                ++i;
                ++j;
            }
        }
        for(;i<m;++i) {
            q.push(nums1[i]);
        }
        for(;j<n;++j) {
            q.push(nums2[j]);
        }
        int k = 0;
        while(!q.empty()) {
            nums1[k] = q.front();
            q.pop();
            ++k;
        }
    }
};

//不使用额外空间，从后向前填充
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1;
        int j = n-1;
        int k = m-1;

            while(j>=0 && k>=0){
                if(nums2[j]>nums1[k])
                    nums1[i--]=nums2[j--];
                else
                    nums1[i--]=nums1[k--];
            }

            while(j>=0){
                nums1[i--]=nums2[j--];
            }
        //}
    }
};