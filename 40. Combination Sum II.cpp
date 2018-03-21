/*
这里和上一个有唯一的条件不同
就是每一组可行的路径当中 一个可选元素只能使用一次 不可重复使用
原数组 全是正整数 可能含有重复元素 这会导致重复的答案
需要去除重复 或者避免重复 我一开始采用的是使用set判断是否存在当前路径
如果不存在就加入 否则就不加入 使用set是一个非常消耗时间and空间开销的事情
在set当中还需要逐个的去判断是否存在。。。

在循环当中去判断当前处理的元素是否和上一个处理的元素是否一样
如果一样就跳过
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(!candidates.size()) return vector<vector<int>> ();
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        set<vector<int>> table;
        dfs(res,path,target,candidates,0,0,table);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, int target, vector<int>& candidates, int index, int sum,set<vector<int>>& table) {
    	if(sum == target) {
            if(table.find(path)==table.end()) {
                table.insert(path);
    		    res.push_back(path);
            }
    		return;
    	}
    	else if(sum>target) return;
        else {
            for(int i=index;i<candidates.size();++i) {
            	if(i!=0&&i!=index&&candidates[i]==candidates[i-1]) continue;
                path.push_back(candidates[i]);
                dfs(res,path,target,candidates,i+1,sum+candidates[i],table);
                path.pop_back();
            }
        }
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> bom;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        combinationSumRecursion(candidates,target,res,bom,0);
        return res;
    }
    void combinationSumRecursion(vector<int>& candidates,int target,vector<vector<int>>& res,vector<int> bom,int begin){
        if (target == 0){
            res.push_back(bom);
        }
        for (int i=begin;i<candidates.size() && candidates[i] <= target;i++){
            if (i !=0 && i!=begin && candidates[i] == candidates[i-1])
            	continue;
            bom.push_back(candidates[i]);
            combinationSumRecursion(candidates,target-candidates[i],res,bom,i+1);
            bom.pop_back();

        }
        return;
    }
};