class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(!candidates.size()) return vector<vector<int>>();
        vector<vector<int>> result;
        vector<int> path;
        dfs(path,result,0,0,candidates,target);
        return result;
    }

    void dfs(vector<int>& path,vector<vector<int>>& result, int sum, int index, vector<int>& candidates, int target) {
    	if(sum == target) {
    		result.push_back(path);
    		return;
    	}
    	else if(sum>target)
    		return;
    	else {
    		for(int i=index;i<candidates.size();++i) {
    			path.push_back(candidates[i]);
    			dfs(path,result,sum+candidates[i],i,candidates,target);
    			path.pop_back();
    		}
    	}
    }
};

/*
dfs思想：采用回溯的思想 枚举每一种可能
求解的过程看做找到一个合适的路径
使用path去记录每一条可行路径
每一条可行路径都是一个向量
用dfs搜索并且记录路径的方法
 */


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int length = candidates.size();
        if (!length)
            return {{}};
        sort(candidates.begin(), candidates.end());//先排序
        sorted = candidates;
        vector<vector<int>> res;
        vector<int> path;
        backtracking(res, target, path, 0);
        return res;
    }
private:
    void backtracking(vector<vector<int>> &res, int target, vector<int> &path, int index){
        for ( ;index < sorted.size() && sorted[index] <= target; ++index){
            path.push_back(sorted[index]);
            if(sorted[index] == target)
                res.push_back(path);
            else
                backtracking(res, target - sorted[index], path, index);
            path.pop_back();
        }
    }

    vector<int> sorted;
};