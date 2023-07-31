vector<string> generateParenthesis(int n) {
    vector<string> res;
    dfs(res, n, 0, 0, "");
    return res;
}

void dfs(vector<string> &res, int n, int left, int right, string str){

    if(left > n || right > n) return;

    if(n == left && n == right){
        res.push_back(str);
        return;
    }

    if(left >= right){
        dfs(res, n,  left+1, right, str+"(");
        dfs(res, n,  left, right+1, str+")");
    }
}