#include<bits/stdc++.h>

#define INF 1<<30
using namespace std;

int n, m;
map<string, vector<string>> data;

void bfs(string start) {
    queue<string> q;
    q.push(start);
    while (1) {
        queue<string> tempQ;
        int sum = 0;
        while (q.size() != 0) {
            string now = q.front();
            q.pop();
            if (data.find(now) != data.end()) {
                for (int i = 0; i < data[now].size(); ++i) {
                    string a = data[now][i];
                    tempQ.push(a);
                }
            } else {
                sum++;
            }
        }
        printf("%d", sum);
        if (tempQ.size() == 0) {
            return;
        } else {
            printf(" ");
            q = tempQ;
        }
    }
}

void pat1003() {
    cin >> n >> m;
    string a, b;
    int t;
    for (int i = 0; i < m; ++i) {
        cin >> a >> t;
        for (int j = 0; j < t; ++j) {
            cin >> b;
            data[a].push_back(b);
        }
    }
    bfs("01");
}

int main() {
    pat1003();
    return 0;
}
