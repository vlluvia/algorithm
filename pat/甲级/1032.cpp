#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct node {
    char data;
    int next;
    bool flag;
} nodes[100010];

void pat1032() {
    for (int i = 0; i < 100010; ++i) {
        nodes[i].flag = false;
    }
    int s1, s2, n;
    cin >> s1 >> s2 >> n;
    int address, next;
    char data;
    for (int i = 0; i < n; ++i) {
        cin >> address;
        cin >> data;
        cin >> next;
        nodes[address].data = data;
        nodes[address].next = next;
    }

    int p;
    for (p = s1; p != -1; p = nodes[p].next) {
        nodes[p].flag = true;
    }
    for (p = s2; p != -1; p = nodes[p].next) {
        if (nodes[p].flag == true) break;
    }
    if (p != -1) {
        printf("%05d\n", p);
    } else {
        printf("-1\n", p);
    }
}


//int main() {
//    pat1032();
//    return 0;
//}