//给2n个整数，将其分成n组 对每一组两个数求最小值 将n个最小值加起来
//求这个最大和。

//输入数据是一个数组
//输入数据是无序的 输入数据必然是偶数个
//第一步先排序从小到大 排序方案的选择 冒泡排序？ 冒泡排序复杂度为O(n^2)
//选择0,2,4,6，。。。。求和就是答案
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
    	for(int j=nums.size();j>1;j--) {
	    	for(int i = 0;i<j-1;i++) {
	    		if(nums[i]>nums[i+1]) {
	    			int temp = nums[i+1];
	    			nums[i+1] = nums[i];
	    			nums[i] = temp;
	    		}
	    	}
    	}
    	int sum = 0;
    	for(int i = 0;i<(nums.size()/2);i++) {
    		sum += nums[2*i];
    	}
    	return sum;  
    }
};//超过时间限制

//反思。。为啥要选择冒泡排序呢？采用标准库的算法  83ms 复杂度 N*log2(N)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
    	int sum = 0;
    	for(int i = 0;i<(nums.size()/2);i++) {
    		sum += nums[2*i];
    	}
    	return sum;  
    }
};


//o(n)的复杂度
//with the range of numbers,it is easy to using vector,and if we don't know the range of numbers,maybe using STL multiset,but using multiset is O(nlogn).
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> hashtable(20001,0);
        for(size_t i=0;i<nums.size();i++)
        {
            hashtable[nums[i]+10000]++;
        }
        int ret=0;
        int flag=0;
        for(size_t i=0;i<20001;){
            if((hashtable[i]>0)&&(flag==0)){
                ret=ret+i-10000;
                flag=1;
                hashtable[i]--;
            }else if((hashtable[i]>0)&&(flag==1)){
                hashtable[i]--;
                flag=0;
            }else i++;
        }
        return ret;
    }
};

//Java的代码 
//和我的思路一致啊！将给定的数组排序 
//然后将0,2,4，。。。的加起来
public class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int result = 0;
        for (int i = 0; i < nums.length; i += 2) {
            result += nums[i];
        }
        return result;
    }
}

//算法复杂度为O(N) 
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int count[20001];
        int sum=0;
        memset(count,0,sizeof(count));//将count全设为0
        for (int i=0;i<nums.size();i++){
            count[nums[i]+10000]++;
        }//从count[10000]开始将所有出现的位置全部置1
        bool odd=true;
        for (int j=0;j<20001;j++){
            while(count[j]>0){//只有当前位置大于0才表示我们当前这个位置对应的值在数组中出现了（可能出现多次）
                if (odd){
                    sum+=j-10000;
                }
                odd = !odd; //odd交替变化 相当于我们只取偶数次访问的元素
                count[j]--;//这个对应的位置可能有多个 
            }
        }
        return sum;
    }
};

//23ms
int x=[](){
   std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int count[20001];
        int sum=0;
        bool odd=true;
        memset(count,0,sizeof(count));
        for(int i=0;i<nums.size();i++){
            count[nums[i]+10000]++;
        }
        for(int j=0;j<20001;j++){
            while(count[j]>0){
                if (odd){
                    sum+=j-10000;
                }
                odd = !odd;
                count[j]--;
            }
        }
        return sum;
    }
};