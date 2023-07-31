class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp, vis(nums.size(),0);
        dfs(vis, nums, temp, res);
        return res;
    }
    void dfs(vector<int>& vis, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i< nums.size(); i++){
            if(vis[i] == 1) continue;
            vis[i] = 1;
            temp.push_back(nums[i]);
            dfs(vis, nums, temp, res);
            temp.pop_back();
            vis[i]=0;
        }
    }
};