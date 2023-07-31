#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n, k;
vector<string> result[2505];

bool cmp(string a, string b) {
    return a < b;
}

void pat1047() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        string name;
        int a = 0;
        cin >> name >> a;
        for (int j = 0; j < a; ++j) {
            int cls;
            cin >> cls;
            result[cls].push_back(name);
        }
    }
    for (int i = 1; i <= k; ++i) {
        int s = result[i].size();
        printf("%d %d\n", i, s);
        sort(result[i].begin(), result[i].end());
        for (int l = 0; l < s; ++l) {
//            cout << result[i][l] << endl;
            printf("%s\n", result[i][l].c_str());
        }
    }
}


//int main() {
//    pat1047();
//    return 0;
//}