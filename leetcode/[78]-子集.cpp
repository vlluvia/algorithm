class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> data;
        vector<bool> vis(nums.size(), false);

        dfs(0, nums, temp, vis, data);
        return data;
    }
    void dfs(int ind, vector<int>& nums, vector<int> &temp, vector<bool> &vis, vector<vector<int>> &data){
        data.push_back(temp);

        for(int i=ind; i< nums.size();i++){
            if(vis[i] == 1) continue;
            vis[i] = 1;
            temp.push_back(nums[i]);
            dfs(i+1,nums,  temp, vis, data);
            vis[i] = 0;
            temp.pop_back();
        }
    }
};