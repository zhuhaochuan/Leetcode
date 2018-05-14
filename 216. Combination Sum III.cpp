//分析：使用k个1-9之间的数构成目标数n
//每组可行解当中不能包含重复的数
//求解所有可行解


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n<1||k<1||n<k) return vector<vector<int>> ();
        vector<vector<int>> res;
        helper(k,n,res,1,vector<int> ());
        return res;
    }

    void helper(int k,int n,vector<vector<int>>& res,int l,vector<int> v) {
    	if(k<0||n<0) return;
    	if(k==0&&n==0) {
    		res.push_back(v);
    		return;
    	}

    	for(int i=l;i<=9;++i) {
    		if(n-i<0) break;
    		v.push_back(i);
    		helper(k-1,n-i,res,i+1,v);
            //v.erase(v.end()-1);//还原现场
            v.pop_back();
    	}
    	return;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp(k, 0);
        int depth = 0;
        int sum = 0;
        while (depth >= 0) {
            if (depth == k) {
                if (sum == n) {
                    result.push_back(temp);
                }
                depth--;
                continue;
            }

            if (depth > 0 && temp[depth] == 0) {
                temp[depth] = temp[depth - 1] + 1;
                sum += temp[depth];
            } else {
                temp[depth]++;
                sum++;
            }

            if (temp[depth] == 10) {
                sum -= temp[depth];
                temp[depth] = 0;
                depth--;
                continue;
            }

            depth++;
        }

        return result;
    }
};