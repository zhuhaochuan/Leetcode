/*
分析：给出一系列的点 对这些点做x轴的垂线
找出使得两条线和x轴围成的面积最大的值。
给出的都是非负值n>=2

求最值问题
 */
//核心思想 从两边向中间 短边向里进
//时间复杂度为o(n)
//Two Pointer Approach 被称为两点法
class Solution {
public:
    int maxArea(vector<int>& height) {
    	int len = height.size();
        int max = min(height[0],height[len-1])*(len-1);
        int i=0,j=len-1;
        while(i<j) {
        	int temp = min(height[i],height[j])*(j-i);
        	if(temp>max) max = temp;
        	if(height[i]<height[j])
        		i++;
        	else j--;
        }
        return max;
    }
};


class Solution {
public:
    double area(vector<int>& height,int i,int j){
        double min=height[i]>height[j]?height[j]:height[i];
        return (j-i)*min*1.0;
    }
    int maxArea(vector<int>& height) {
        double answer=0;
        int i=0;int j=height.size()-1;
        while(i<j){
            double temp=area(height,i,j);
            answer=answer>temp?answer:temp;
            //compare
            if(height[i]<height[j]) i++;
            else j--;
        }
        return answer;
    }

};