#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

int n, numTree = 0, birds = 0;
int father[10005], cnt[10005];
bool vis[10005];

int findFather(int x) {
    while (x != father[x]) {
        x = father[x];
    }
    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA > faB) {
        father[faA] = faB;
    } else if (faA < faB) {
        father[faB] = faA;
    }
}

void pat1118() {
    for (int i = 0; i < 10005; ++i) {
        father[i] = i;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k, id;
        cin >> k >> id;
        vis[id] = true;
        for (int j = 0; j < k - 1; ++j) {
            int num;
            cin >> num;
            Union(id, num);
            vis[num] = true;
        }
    }

    for (int i = 0; i < 10005; ++i) {
        if (vis[i]) {
            int f = findFather(i);
            cnt[f]++;
        }
    }

    for (int i = 0; i < 10005; ++i) {
        if (vis[i] && cnt[i] != 0) {
            numTree++;
            birds += cnt[i];
        }
    }
    cout << numTree << " " << birds << endl;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << (findFather(a) == findFather(b) ? "Yes" : "NO") << endl;
    }
}

int main() {
    pat1118();
    return 0;
}