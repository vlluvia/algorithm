#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

int n, m;
int data[210][210]={0};

void pat1122() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        data[a][b] = 1;
        data[b][a] = 1;
    }
    int cnt;
    cin>>cnt;
    for (int i = 0; i < cnt; ++i) {
        int k;
        cin >> k;
        vector<int> v(k);
        set<int> s;
        int flag1 = 1, flag2 = 1;
        for(int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if(s.size() != n || k - 1 != n || v[0] != v[k-1]) flag1 = 0;
        for(int i = 0; i < k - 1; i++)
            if(data[v[i]][v[i+1]] == 0) flag2 = 0;
        printf("%s",flag1 && flag2 ? "YES\n" : "NO\n");
    }

}

int main() {
    pat1122();
    return 0;
}