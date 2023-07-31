class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        for(int i=0;i < n;i++){
            s+='.';
        }
        vector<int> record(n);
        vector<string> temp(n, s);
        dfs(0,n, temp , record);
        return res;
    }

    void dfs(int ind, int n, vector<string>& temp, vector<int>& record){
        if(ind == n){
            res.push_back(temp);
            return;
        }
        for(int i=0;i < n; i++){
            record[ind] = i;
            if(isOk(record, ind)){
                temp[ind][i] = 'Q';
                dfs(ind+1, n, temp, record);
                temp[ind][i] = '.';
            }
        }
    }

    bool isOk(vector<int>& record, int ind){
        for(int i=0;i<ind;i++){
            if(record[i] == record[ind] || ind - record[ind] == i - record[i] ||ind + record[ind] == i + record[i]) return false;
        }
        return true;
    }
};