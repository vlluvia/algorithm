#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

struct node {
    int x, y;
};

void pat1128() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<node> data;
        int t;
        cin >> t;
        for (int j = 1; j <= t; ++j) {
            int num;
            cin >> num;
            data.push_back({j, num});
        }
        bool flag = true;
        for (int j = 0; j < data.size() ; ++j) {
            for (int k = j + 1; k < data.size(); ++k) {
                if (data[j].x == data[k].x || data[j].y == data[k].y ||
                    abs(data[j].x - data[k].x) == abs(data[j].y - data[k].y)) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}

int main() {
    pat1128();
    return 0;
}