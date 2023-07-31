class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()/2;
        for(int i=0; i < n;i++){
            int n2 = matrix.size() - i * 2 -1;
            for(int j = 0; j < n2 ; j++){
                int temp = matrix[i][i+j];
                matrix[i][i+j] = matrix[ n2+i -j][i];
                matrix[n2+i -j][i] = matrix[n2+i][i+n2-j];
                matrix[n2+i][i+n2-j] = matrix[i+j][i+n2];
                matrix[i+j][i+n2] = temp;
            }
        }
    }
};