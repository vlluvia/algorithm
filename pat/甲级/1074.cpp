#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct node {
    string last;
    int data;
    string after;
};
string first_node;
int n, k;
vector<node> nodes;
map<string, node> a;

void pat1074() {
    cin >> first_node >> n >> k;
    for (int i = 0; i < n; ++i) {
        string last, after;
        int data;
        cin >> last >> data >> after;
        node nod = {
                last, data, after
        };
        a[nod.last] = nod;
    }
    while (true) {
        if (first_node == "-1")break;
        nodes.push_back(a[first_node]);
        first_node = a[first_node].after;
    }

    int kao = 0;
    for (int i = 0; i < nodes.size() / k; i++) {
        reverse(nodes.begin() + kao, nodes.begin() + kao + k);
        kao = kao+k;
    }
    for (int i = 0; i < nodes.size(); ++i) {
        if (i != nodes.size()-1)
            printf("%s %d %s\n",nodes[i].last.c_str(),nodes[i].data,nodes[i+1].last.c_str());
        else
            printf("%s %d -1\n", nodes[i].last.c_str(), nodes[i].data);

    }
}


//int main() {
//    pat1074();
//    return 0;
//}