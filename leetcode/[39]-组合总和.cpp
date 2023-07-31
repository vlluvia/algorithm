class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;
    void dfs(vector<int>& candidates,int ind, int sum, int target){
        if(sum > target){
            return;
        }else if(sum == target){
            res.push_back(temp);
            return;
        }

        for(int i=ind;i < candidates.size();i++){
            temp.push_back(candidates[i]);
            dfs(candidates, i, sum + candidates[i], target);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(int i = 0;i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            dfs(candidates, i, candidates[i], target);
            temp.pop_back();
        }
        return res;
    }
};