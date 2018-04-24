//妈卖比 理解错了意思
//分成的序列必须是连续的
//
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()<3) return false;
        int n = nums.size(),count = 0,pre = nums[0],flag = 1;
        for(int i=1;i<n;++i) {
        	if(nums[i]-pre>1) return false;
        	else if(nums[i]==pre) {
        		count += flag * 1;
        	}
        	else {
        		pre = nums[i];
        		flag *= -1;
        		if(flag&&count) return false;
        	}
        }
        return count == 0;
    }
};


//如果当前元素为i 而以i-1结尾的串存在
//那么当前元素就放进以i-1结尾的串 形成i结尾的串同时以i-1结尾的串不存在
//如果没有出现i-1结尾的串，那么必须新建一个串，此时需要判断 i+1 i+2是不是都存在
//如果不存在那么新建的串讲不可能构建一个满足长度大于等于3的子串返回false
//如果存在那么以i+2结尾的子串存在
//核心的思路是根据当前元素的前后之间在遍历到当前元素的时候直接判断当前元素是不是可以放进一个可行的子串当中
//如果每一个元素都可以放进那么才返回false。
bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnt, tails;//tails存放以对应元素为结尾的串是否出现
        for(int &i : nums) cnt[i]++;//在map当中记录所有元素出现的次数
        for(int &i : nums){
            if(!cnt[i]) continue;//这是和后面的判断配合 如果当前的元素在之前已经被用了那么就跳过
            cnt[i]--;
            if(tails[i-1] > 0){
                tails[i-1]--;//这里必须清零
                tails[i]++;
            }
            else if(cnt[i+1] && cnt[i+2]){
                cnt[i+1]--;//往后看两个元素是不是存在 如果存在需要将计数减1
                cnt[i+2]--;
                tails[i+2]++;
            }
            else return false;
        }
        return true;
    }