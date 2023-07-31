#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n, k;
map<string, vector<int>> data;

bool cmp(int a, int b) {
    return a < b;
}

void pat1039() {

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < b; ++j) {
            string name;
            cin >> name;
            data[name].push_back(a);
        }
    }

    for (int i = 0; i < n; ++i) {
        string query_name;
        cin >> query_name;
        cout << query_name;
        cout << " " << data[query_name].size();
        sort(data[query_name].begin(), data[query_name].end(), cmp);
        for (int j = 0; j < data[query_name].size(); ++j) {
            cout<<" "<<data[query_name][j];
        }
        cout << endl;
    }
}


    //int main() {
    //    pat1039();
    //    return 0;
    //}