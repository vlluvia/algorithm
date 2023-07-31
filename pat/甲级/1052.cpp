#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct node {
    int address, data, next;
    bool flag;
} nodes[100010];

bool cmp(node a, node b) {
    if (!a.flag || !b.flag) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

void pat1052() {
    for (int i = 0; i < 100010; ++i) {
        nodes[i].flag = false;
    }
    int n, begin, address;
    cin >> n >> begin;
    for (int i = 0; i < n; ++i) {
        int add, data, next;
        cin >> add;
        cin >> data;
        cin >> next;
        nodes[add].data = data;
        nodes[add].next = next;
        nodes[add].address = add;
    }
    int count = 0, p = begin;
    while (p != -1) {
        nodes[p].flag = true;
        count++;
        p = nodes[p].next;
    }
    if (count == 0) {
        cout << "0 -1";
    } else {
        sort(nodes, nodes + 100010, cmp);
        printf("%d %05d\n", count, nodes[0].address);
        for (int i = 0; i < count; ++i) {
            if (i != count - 1) {
                printf("%05d %d %05d\n", nodes[i].address, nodes[i].data, nodes[i + 1].address);
            } else {
                printf("%05d %d -1\n", nodes[i].address, nodes[i].data);
            }
        }
    }
}


//int main() {
//    pat1052();
//    return 0;
//}