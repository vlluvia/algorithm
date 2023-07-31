#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct node {
    string address;
    int key;
    string next;
};
bool flag[10010] = {false};

void pat1097() {
    string begin;
    int n;
    map<string, node> data;
    vector<node> output, remove;
    cin >> begin >> n;
    for (int i = 0; i < n; ++i) {
        string address, next;
        int key;
        cin >> address >> key >> next;
        data[address] = {address, key, next};
    }

    while (begin != "-1") {
        if (!flag[abs(data[begin].key)]) {
            output.push_back(data[begin]);
            flag[abs(data[begin].key)] = true;
        } else {
            remove.push_back(data[begin]);
        }
        begin = data[begin].next;
    }
    for (int i = 0; i < output.size(); ++i) {
        printf("%s %d ", output[i].address.c_str(), output[i].key);
        if (i != output.size() - 1)
            printf("%s\n", output[i + 1].address.c_str());
        else
            printf("-1\n");
    }
    for (int i = 0; i < remove.size(); ++i) {
        printf("%s %d ", remove[i].address.c_str(), remove[i].key);
        if (i != remove.size() - 1)
            printf("%s\n", remove[i + 1].address.c_str());
        else
            printf("-1\n");
    }
}

int main() {
    pat1097();
    return 0;
}