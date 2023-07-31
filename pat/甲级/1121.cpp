#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

int n;
map<int, int> gtob, btog;
int sign[100000] = {0};
vector<int> temp, res;

void pat1121() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int g, b;
        cin >> g >> b;
        gtob[g] = b;
        btog[b] = g;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int q;
        cin >> q;
        sign[q] = 1;
        temp.push_back(q);
    }

    for (int i = 0; i < k; ++i) {
        auto la = gtob.find(temp[i]);
        auto lb = btog.find(temp[i]);
        if (la == gtob.end() && lb == btog.end()) {
            res.push_back(temp[i]);
            continue;
        }
        if (la != gtob.end() && sign[gtob[temp[i]]] == 0) {
            res.push_back(temp[i]);
            continue;
        }

        if (lb != btog.end() && sign[btog[temp[i]]] == 0) {
            res.push_back(temp[i]);
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        printf("%05d", res[i]);
        if (i != res.size() - 1) {
            cout << " ";
        }
    }
}

int main() {
    pat1121();
    return 0;
}