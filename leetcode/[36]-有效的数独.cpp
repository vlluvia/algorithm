bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rows(10, vector<int>(10, 0));
    vector<vector<int>> columns(10, vector<int>(10, 0));
    vector<vector<int>> grid(10, vector<int>(10, 0));

    for(int i=0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            if(board[i][j] != '.'){
                int num = board[i][j]-'0';
                if(rows[i][num] ==1 || columns[j][num] == 1 || grid[i/3*3+j/3][num] == 1){
                    return false;
                }
                rows[i][num]++;
                columns[j][num]++;
                grid[i/3*3+j/3][num]++;

            }
        }
    }
    return true;
}