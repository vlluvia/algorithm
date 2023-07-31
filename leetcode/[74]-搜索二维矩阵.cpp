class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int min=0, max = m*n -1;
        while(min < max){
            int mid = (min +max)/2;
            int x = mid / n , y = mid%n;
            if(matrix[x][y] > target) max = mid;
            else if(matrix[x][y] < target) min =mid + 1;
            else return true;
        }
        int x = min / n , y = min%n;
        if(matrix[x][y] == target){
            return true;
        }else
            return false;
    }
};