class Solution {
public:
    vector<int> temp;
    vector<vector<int>> tempRes,res;
    void dfs(vector<int>& candidates,int ind,  int target){
        if(0 == target){
            res.push_back(temp);
            return;
        }

        for(int i=ind;i < candidates.size();i++){
            if(candidates[i] > target)
                return;
            if(i> ind && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            dfs(candidates, i+1, target- candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};