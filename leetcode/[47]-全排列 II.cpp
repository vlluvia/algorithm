class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp, vis(nums.size(),0);
        sort(nums.begin(), nums.end());
        dfs(vis, nums, temp, res);
        return res;
    }
    void dfs(vector<int>& vis, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        int r = 100000;
        for(int i = 0; i< nums.size(); i++){
            if(vis[i] == 1 || nums[i] == r) continue;
            r = nums[i];
            vis[i] = 1;
            temp.push_back(nums[i]);
            dfs( vis, nums, temp, res);
            temp.pop_back();
            vis[i]=0;
        }
    }
};