#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

vector<int> data;
vector<int> data_order;

void pat1057() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string c;
        int num;
        cin >> c;
        if (c[1] == 'u') {
            cin >> num;
            data.push_back(num);
            auto it = lower_bound(data_order.begin(), data_order.end(), num);
            data_order.insert(it, num);
        } else if (c[1] == 'o') {
            if (data.empty()) {
                printf("Invalid\n");
            } else {
                printf("%d\n", data[data.size() - 1]);
                auto it = lower_bound(data_order.begin(), data_order.end(), data[data.size() - 1]);
                data_order.erase(it);
                data.pop_back();
            }
        } else {
            if (data.empty()) {
                printf("Invalid\n");
            } else {
                int med = data.size() % 2 ? (data.size() + 1) / 2 : data.size() / 2;
                printf("%d\n", data_order[med - 1]);
            }
        }

    }
}

//int main() {
//    pat1057();
//    return 0;
//}