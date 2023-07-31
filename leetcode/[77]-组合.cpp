class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> data;
        vector<bool> vis(n, false);

        dfs(1, k, n, temp, vis, data);
        return data;
    }

    void dfs(int ind, int k,int n, vector<int> &temp, vector<bool> &vis, vector<vector<int>> &data){
        if(temp.size() == k){
            data.push_back(temp);
            return;
        }
        int r = 10000;
        for(int i=ind; i<= n;i++){
            if(vis[i] == 1) continue;
            r = i;
            vis[i] = 1;
            temp.push_back(i);
            dfs(i+1, k , n, temp, vis, data);
            vis[i] = 0;
            temp.pop_back();
        }
    }
};