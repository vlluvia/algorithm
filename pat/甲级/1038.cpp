#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

bool cmp(string a, string b) {
    return a + b < b + a;
}

void pat1038() {
    int n;
    string data[10005];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    sort(data, data + n, cmp);
    string s;
    for (int i = 0; i < n; i++)
        s += data[i];
    while (s.size() != 0 && s[0] == '0')
        s.erase(s.begin());
    if (s.size() == 0)
        printf("0");
    else
        cout << s;
}


//int main() {
//    pat1038();
//    return 0;
//}