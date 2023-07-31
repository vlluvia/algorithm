#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

#define rep(i,f,t) for(i= f;i<t;i++)
const int maxn = 2e5; //There is 1e4 nodes, 6e4 edges. There is 1.2e5 nodes at most in adjective table
int ft[maxn], nt[maxn], v[maxn], tot; // ft: first, nt:next, v:vertex, tot: total node number, new node = v[tot++]; 
int low[maxn],lowlink[maxn],t; // t: the index of dfs sequence
stack<int> s;

void tarjan(int x) {
    low[x] = lowlink[x] = ++t; // prevent give '0' to low[x];
    s.push(x);
    for (int i = ft[x]; i != -1; i = nt[i])
    {
        if (!low[v[i]]) {
            tarjan(v[i]);
            lowlink[x] = min(lowlink[x], lowlink[v[i]]);
        }
        else lowlink[x] = min(lowlink[x], low[v[i]]);
    }
    if (low[x] == lowlink[x]) {
        int u;
        do {
            u = s.top(); s.pop();
            lowlink[u] = lowlink[x];
        } while (u != x);
    }
}


int main()
{
    //freopen("out.txt", "w", stdout);
    int n, m, x, y, i;
    scanf("%d %d", &n, &m);
    tot = t = 0;
    rep(i, 1, n + 1) ft[i] = -1, low[i] = 0;
    while (m--) {
        scanf("%d %d", &x, &y);
        //new node in adjective table
        v[tot] = y; nt[tot] = ft[x]; ft[x] = tot++;
    }
    rep(i, 1, n + 1) if (!low[i]) tarjan(i);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &x, &y);
        printf("%s\n", lowlink[x] == lowlink[y] ? "Yes": "No");
    }
    return 0;
}
 