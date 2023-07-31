class Solution {
public:
    bool flag = true;
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(dfs(i, j, 0, word, vis, board)){
                    return true;
                }
        return false;
    }

    bool dfs(int x, int y, int sum, string word, vector<vector<bool>> &vis, vector<vector<char>>& board){
        if(sum  == word.size()){
            return true;
        }
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || word[sum] != board[x][y]){
            return false;
        }
        if(vis[x][y] == 0){
            vis[x][y] = 1;
            if(dfs(x, y+1, sum+1, word, vis, board)
               || dfs(x, y-1, sum+1, word, vis, board)
               || dfs(x+1, y, sum+1, word, vis, board)
               || dfs(x-1, y, sum+1, word, vis, board)){
                return true;
            }
            vis[x][y] = 0;
        }
        return false;
    }

};