class Solution {
public:
    bool flag = false;
    int k1 = 0;
    vector<int> t;
    string getPermutation(int n, int k) {
        vector<int> temp;
        vector<int> vis(n+1, 0);
        dfs(0, n,k, temp, vis);
        string res="";
        for(int i=0;i<t.size();i++){
            res+=to_string(t[i]);
        }
        return res;
    }
    void dfs(int ind, int n,int k, vector<int>& temp, vector<int>& vis){
        if(flag) return;
        if(ind == n){
            k1++;
            if(k1 == k){
                t = temp;
                flag = true;
                return;
            }
            return;
        }
        for(int i = 1; i <= n;i++){
            if(vis[i]==0){
                vis[i] = 1;
                temp.push_back(i);
                dfs(ind+1, n, k, temp, vis);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }
};