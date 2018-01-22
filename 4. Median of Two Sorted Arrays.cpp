/*
分析：给定两个数组 从小到大已经排好序
得到这两个数组组成的新的序列的中位数

 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size(),len = 0;
        vector<int> a,b;
        if(m<=n) {
        	len = m;
            a = nums1;
        	b = nums2;
        }
        else {
            int temp = m;
            m = n;
            n = temp;
        	len = m;
        	a = nums2;
        	b = nums1;
        }
        int min = 0,max = len,i = 0,j=0;

        while(min<=max) {
            i = (min + max)/2;
        	j = (m + n + 1)/2 - i;
        	if(i>min&&a[i-1]>b[j]) max = i-1;
        	else if(i<max&&b[j-1]>a[i]) min = i+1;
            else break;
        }
        int lmax = 0,rmin = 0;
        if(i==0) lmax = b[j-1];
        else if(j==0) lmax = a[i-1];
        else lmax = a[i-1]>b[j-1]?a[i-1]:b[j-1];

        if(i==m) rmin = b[j];
        else if(j==n) rmin = a[i];
        else rmin = a[i]<b[j]?a[i]:b[j];

        if((n+m)%2)
        	return (double)lmax;
        else return (double) (lmax + rmin)/2;
    }
};



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size(),len = m;
        if(m>n)//处理不知道哪个大哪个小的时候可以采用递归调用一次调换参数位置的方式
            return findMedianSortedArrays(nums2,nums1);
        int min = 0,max = len,i = 0,j=0;
        vector<int>& a = nums1,b = nums2;
        //核心就是二分搜索log(n)的时间复杂度
        while(min<=max) {
            i = (min + max)/2;
        	j = (m + n + 1)/2 - i;
        	if(i>min&&a[i-1]>b[j]) max = i-1;
        	else if(i<max&&b[j-1]>a[i]) min = i+1;
            else break;
        }
        //处理边界一定要注意
        int lmax = 0,rmin = 0;
        if(i==0) lmax = b[j-1];
        else if(j==0) lmax = a[i-1];
        else lmax = a[i-1]>b[j-1]?a[i-1]:b[j-1];

        if(i==m) rmin = b[j];
        else if(j==n) rmin = a[i];
        else rmin = a[i]<b[j]?a[i]:b[j];

        if((n+m)%2)
        	return (double)lmax;
        else return (double) (lmax + rmin)/2;
    }
};