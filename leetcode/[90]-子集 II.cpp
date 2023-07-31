class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> data;
        vector<int> vis(nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(0, temp, vis, nums, data);
        return data;
    }

    void dfs(int ind, vector<int> &temp, vector<int> &vis,vector<int>& nums, vector<vector<int>> &data){
        data.push_back(temp);
        for(int i=ind;i< nums.size();i++){
            if(i > ind && nums[i-1] == nums[i]) continue;
            temp.push_back(nums[i]);
            dfs(i+1, temp, vis, nums, data);
            temp.pop_back();
        }
    }
};