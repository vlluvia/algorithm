class Solution {
public:
    vector<int> res;
    bool invalid = false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<vector<int>> data(numCourses, vector<int>(numCourses, 0));
        for(int i=0;i<prerequisites.size(); i++){
            data[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }
        for(int i = 0;i < numCourses;i++){
            if(vis[i] == 0){
                vis[i] = 1;
                dfs(i, numCourses, vis, data);
            }
        }
        if(invalid){
            return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(int ind, int numCourses, vector<int>& vis,vector<vector<int>> &data){

        for(int i=0; i< numCourses;i++){
            if(data[ind][i]==1 && vis[i] == 0){
                vis[i] = 1;
                dfs(i, numCourses, vis, data);
                if(invalid ) return;
            }else if(data[ind][i]==1 && vis[i] == 1){
                invalid = true;
                return;
            }
        }
        vis[ind] = 2;
        res.push_back(ind);
    }
};