#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct Node {
    int id;
    int layer;
};

vector<Node> Adj[1010];
bool inq[1010] = {false};

int bfs(int s, int l) {
    int numForward = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        for (int i = 0; i < Adj[u].size(); ++i) {
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if (inq[next.id] == false && next.layer <= l) {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }

        }
    }
    return numForward;
}

void pat1076() {
    Node user;
    int n, l, numFollow, idFollow;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        user.id = i;
        cin >> numFollow;
        for (int j = 0; j < numFollow; ++j) {
            cin >> idFollow;
            Adj[idFollow].push_back(user);
        }
    }
    int numQuery, s;
    cin >> numQuery;
    for (int i = 0; i < numQuery; ++i) {
        memset(inq, false, sizeof(inq));
        cin >> s;
        int numForward = bfs(s, l);
        cout << numForward << endl;
    }
}


//int main() {
//    pat1076();
//    return 0;
//}