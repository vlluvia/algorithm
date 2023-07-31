#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct node {
    vector<int> child;
};

int n;
double p, r;
node data[100005];
double min_price = INF;
int min_size = 0;

void dfs(int index, double price) {
    if (data[index].child.size() == 0) {
        if (price < min_price) {
            min_price = price;
            min_size = 1;
        } else if (price == min_price) {
            min_size++;
        }
        return;
    }

    for (int i = 0; i < data[index].child.size(); ++i) {
        dfs(data[index].child[i], price * (1 + r / 100));
    }
}

void pat1106() {
    cin >> n >> p >> r;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j < t; ++j) {
            int num;
            cin >> num;
            data[i].child.push_back(num);
        }
    }

    dfs(0, p);
    printf("%.4lf %d\n", min_price, min_size);
}

int main() {
    pat1106();
    return 0;
}