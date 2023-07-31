#include<bits/stdc++.h>

using namespace std;

int n, m;
int depth=0;
int layer_sum[105];
map<string, vector<string>> mp;

void dfs(string str, int dep);

void pat1004() {
    cin >> n >> m;
    if(n == 0) return ;
    for (int i = 0; i < m; ++i) {
        string f, child;
        int k;
        cin >> f >> k;
        for (int j = 0; j < k; ++j) {
            cin >> child;
            mp[f].push_back(child);
        }
    }
    dfs("01", 0);
    cout << layer_sum[0];
    for (int l = 1; l <= depth; ++l) {
        cout << " "<<layer_sum[l] ;
    }
}

void dfs(string str, int dep) {
    depth = max(dep, depth);
    if (mp[str].size() == 0)
        layer_sum[dep]++;
    for (auto item:mp[str]) {
        dfs(item, dep + 1);
    }
}
//int main() {
//    pat1004();
//    return 0;
//}