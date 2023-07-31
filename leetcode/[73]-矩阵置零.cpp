class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> data(matrix.size(), vector<int>(matrix[0].size(), 1));
        for(int i=0; i< matrix.size(); i++){
            for(int j=0; j< matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    for(int i1=0; i1< matrix.size(); i1++){
                        data[i1][j] = 0;
                    }
                    for(int i1=0; i1< matrix[0].size(); i1++){
                        data[i][i1] = 0;
                    }
                }
            }
        }
        for(int i=0; i< matrix.size(); i++){
            for(int j=0; j< matrix[0].size(); j++){
                if(data[i][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};