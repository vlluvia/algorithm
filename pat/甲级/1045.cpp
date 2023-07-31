#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n, m, l;
int m_data[205], l_data[10005];
bool colors[205] = {false};
int dp[10005];
int priority[10005];

void pat1045() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> m_data[i];
        colors[m_data[i]] = true;
        priority[m_data[i]] = i;
    }
    cin >> l;
    for (int i = 0; i < l; ++i) {
        cin >> l_data[i];
    }

    int ans = -1;
    for (int i = 0; i < l; ++i) {
        if (colors[l_data[i]]) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (priority[l_data[i]] >= priority[l_data[j]] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;
}

//int main() {
//    pat1045();
//    return 0;
//}