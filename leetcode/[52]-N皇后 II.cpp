class Solution {
public:
    int res = 0;
    int totalNQueens(int n) {
        vector<int> record(n);
        dfs(0, n,record);
        return res;
    }

    void dfs(int ind, int n,  vector<int>& record){
        if(ind == n){
            res++;
            return;
        }
        for(int i=0;i< n;i++){
            record[ind] = i;
            if(isOk(record, ind)){
                dfs(ind+1, n,record);
            }
        }
    }

    bool isOk(vector<int> record, int row){
        for(int i=0;i<row; i++){
            if(record[i] == record[row] || row -record[row] == i - record[i] || row +record[row] == i + record[i]) return false;
        }
        return true;
    }
};