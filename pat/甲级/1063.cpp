#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n, k;
set<int> data[55];

void pat1063() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l;
        scanf("%d", &l);
        for (int j = 0; j < l; ++j) {
            int num;
            scanf("%d", &num);
            data[i].insert(num);
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a, b, temp = 0;
        scanf("%d %d", &a, &b);
        for (int it : data[a - 1]) {
            if (data[b - 1].find(it) != data[b - 1].end()) {
                temp++;
            }
        }
        int all = data[a - 1].size() + data[b - 1].size();
        float res = (temp * 1.0) / (all - temp) * 100;
        printf("%.1f%\n", res);
    }

}

//int main() {
//    pat1063();
//    return 0;
//}