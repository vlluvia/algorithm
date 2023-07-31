#include<bits/stdc++.h>
#include<string>

#define INF 1<<29
using namespace std;

int n, m;
vector<int> temp1[10005], temp2[10005];

void pat1134() {
    int n, m, k, nv, a, b, num;
    scanf("%d%d", &n, &m);
    vector<int> v[n];
    for (int i = 0;i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &nv);
        int flag = 0;
        vector<int> hash(m, 0);
        for (int j = 0; j < nv; j++) {
            scanf("%d", &num);
            for (int t = 0; t < v[num].size(); t++)
                hash[v[num][t]] = 1;
        }
        for (int j = 0; j < m; j++) {
            if (hash[j] == 0) {
                printf("No\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("Yes\n");
    }

}

int main() {
    pat1134();
    return 0;
}