#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

map<int, int> data;

void pat1054() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m * n; ++i) {
        int a;
        scanf("%d",&a);
        if (data.find(a) != data.end()) {
            data[a]++;
        } else {
            data[a] = 1;
        }
    }
    int max = 0;
    int index = 0;
    for (auto &it : data) {
        if (it.second > max) {
            index = it.first;
            max = it.second;
        }
    }
    cout << index << endl;
}

//int main() {
//    pat1054();
//    return 0;
//}