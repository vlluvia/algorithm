#include <bits/stdc++.h>

using namespace std;
bool a, b;

void dfs(int x, int y, int sum) {
    if (a) return;

    if (x == 1 && y == 1) {
        a = true;
        return;
    }
    if (y == 1) {
        b = true;
    }
    while (sum > 1) {
        if (x % sum == 0)
            dfs(x / sum, y, sum - 1);
        if (y % sum ==0)
            dfs(x, y / sum, sum - 1);
        sum--;
    }
    return;
}

int main() {
    int x, y;
    while (cin >> x >> y) {
        if (x < y) swap(x, y);
        a = b = false;
        dfs(x, y, 100);
        if (!a && b) {
            cout << y << endl;
        } else {
            cout << x << endl;
        }
    }

    return 0;
}