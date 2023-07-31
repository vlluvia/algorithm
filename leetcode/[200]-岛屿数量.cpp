class Solution {
public:
    int n = 0;
    int m = 0;
    int cos[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0 ;
        n = grid.size();
        m = grid[0].size();
        int sum = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(vis[i][j] == false && grid[i][j] == '1'){
                    vis[i][j] = true;
                    grid[i][j] = '2';
                    dfs(i, j, vis, grid);
                    sum++;
                }
            }
        }
        return sum;
    }
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& grid){

        for(int ind=0;ind < 4;ind++){
            int x = i + cos[ind][0];
            int y = j + cos[ind][1];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(vis[x][y] == false && grid[x][y] == '1'){
                vis[x][y] = true;
                grid[x][y] = '2';
                dfs(x, y, vis, grid);
            }
        }
    }
};