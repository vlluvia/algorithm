#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n, data[100005];
int data_left[100005];
int data_right[100005];

void pat1046() {
    int l = 0, r = 0;
    data_left[1] = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> data[i];
        l += data[i];
        data_left[i + 1] = l;
    }
    for (int i = n; i >= 1; --i) {
        r += data[i];
        data_right[i] = r;
    }
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int left = 0, right = 0;
        right = data_left[b] - data_left[a];
        if (a != 1)
            left += data_left[a];
        left += data_right[b];
        if (left < right) {
            cout << left << endl;
        } else {
            cout << right << endl;
        }
    }

}


//int main() {
//    pat1046();
//    return 0;
//}