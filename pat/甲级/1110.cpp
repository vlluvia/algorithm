#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

struct node {
    int left, right;
};

int n;
node data[25];
int root = 0, last = -1;
int t[25] = {0};

bool bfs() {
    bool flag = true;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now != -1) {
            last = now;
            q.push(data[now].left);
            q.push(data[now].right);
        } else {
            while (!q.empty()) {
                int temp = q.front();
                q.pop();
                if (temp != -1) {
                    flag = false;
                }
            }
        }
    }
    return flag;
}

void pat1110() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string l, r;
        cin >> l >> r;
        if (l != "-") {
            int temp_l;
            stringstream ss;
            ss << l;
            ss >> temp_l;
            data[i].left = temp_l;
            t[temp_l] = 1;
        } else {
            data[i].left = -1;
        }
        if (r != "-") {
            int temp_r;
            stringstream ss2;
            ss2 << r;
            ss2 >> temp_r;
            data[i].right = temp_r;
            t[temp_r] = 1;
        } else {
            data[i].right = -1;
        }
    }
    for (int i = 0; i < n; i++)
        if (t[i] != 1) {
            root = i;
            break;
        }
    if (bfs()) printf("YES %d\n", last);
    else printf("NO %d\n", root);
}

int main() {
    pat1110();
    return 0;
}