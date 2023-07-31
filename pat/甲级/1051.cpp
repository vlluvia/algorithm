#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1051() {
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        vector<int> v(n);
        stack<int> s;
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        int index = 0;
        for (int j = 0; j < n; ++j) {
            s.push(j + 1);
            if (s.size() > m) break;
            while (!s.empty() && s.top() == v[index]) {
                s.pop();
                index++;
            }
        }
        if (index == n) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}

//int main() {
//    pat1051();
//    return 0;
//}