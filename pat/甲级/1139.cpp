#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
unordered_map<int, bool> e;
struct node{
    int a, b;
};
vector<vector<int> > f(10000);
bool cmp(node a, node b){
    return a.a != b.a ? a.a < b.a : a.b < b.b;
}
int n, m, k;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        string a, b;
        cin >> a >> b;
        if(a.size() == b.size()){
            f[abs(stoi(a))].push_back(abs(stoi(b)));
            f[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        e[abs(stoi(a)) * 10000 + abs(stoi(b))] = e[abs(stoi(b))* 10000 + abs(stoi(a))] = true;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        vector<node> ans;
        for(int t = 0; t < f[abs(a)].size(); ++t)
            for(int j = 0; j < f[abs(b)].size(); ++j){
                if(f[abs(a)][t] == abs(b) || f[abs(b)][j] == abs(a)) continue;
                if(e[f[abs(a)][t] * 10000 + f[abs(b)][j] ])
                    ans.push_back({f[abs(a)][t], f[abs(b)][j]});
            }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for(int j = 0; j < ans.size(); ++j)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}