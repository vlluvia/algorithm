// 劣质代码

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> tempRes,res;
    void dfs(vector<int>& candidates,int ind, int sum, int target){
        if(sum > target){
            return;
        }else if(sum == target){
            tempRes.push_back(temp);
            return;
        }

        for(int i=ind+1;i < candidates.size();i++){
            temp.push_back(candidates[i]);
            dfs(candidates, i, sum + candidates[i], target);
            temp.pop_back();
        }
    }
    void cleanRes(){
        for(int i=0;i<tempRes.size();i++){
            bool flag = true;
            for(int j=i+1;j<tempRes.size();j++){
                if(tempRes[i].size() == tempRes[j].size()){
                    bool flag2 = false;
                    for(int k = 0; k < tempRes[i].size(); k++){
                        if(tempRes[i][k] != tempRes[j][k]) {
                            flag2 = true;
                        }
                    }
                    if(flag2 == false){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                res.push_back(tempRes[i]);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(int i = 0;i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            dfs(candidates, i, candidates[i], target);
            temp.pop_back();
        }
        cleanRes();
        return res;
    }
};