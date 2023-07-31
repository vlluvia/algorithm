#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

vector<int> factor,factors, temp, res;
int n, k, p;
int max_sum = -1;

void dfs(int index, int now_index, int factor_sum, int sum) {
    if (now_index == k &&sum == n) {
        if (factor_sum > max_sum) {
            max_sum = factor_sum;
            res = temp;
        }
        return;
    }
    if (now_index >= k || sum > n || index == 0) {
        return;
    }
    if(index-1>=0) {
        temp.push_back(factor[index]);
        dfs(index, now_index + 1, factor_sum + index, sum + factors[index]);
        temp.pop_back();
        dfs(index - 1, now_index, factor_sum, sum);
    }
}

void pat1103() {
    cin >> n >> k >> p;
    for (int i = 0; pow(i, p) <= n; ++i) {
        factors.push_back(pow(i, p));
        factor.push_back(i);
    }

    dfs(factors.size() - 1, 0, 0,0);
    if (max_sum == -1) {
        printf("Impossible\n");
    } else {
        printf("%d = %d^%d", n, res[0], p);
        for (int i = 1; i < res.size(); i++) {
            printf(" + %d^%d", res[i], p);
        }
    }
}

int main() {
    pat1103();
    return 0;
}