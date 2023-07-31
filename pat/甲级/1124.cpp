#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

void pat1124() {
    int m, n, s;
    vector<string> data(1005);
    set<string> res;
    cin >> m >> n >> s;
    if (m < s) {
        cout << "Keep going..." << endl;
        return;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> data[i];
    }
    for (int i = s; i <= m;) {
        if (res.find(data[i]) == res.end()) {
            cout<<data[i]<<endl;
            res.insert(data[i]);
            i += n;
        }else{
            i++;
        }
    }
}

int main() {
    pat1124();
    return 0;
}