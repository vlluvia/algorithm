#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

int n, m;
int temp_data[50005];
vector<int> temp;

bool cmp(int a, int b) {
    if (temp_data[a] != temp_data[b]) {
        return temp_data[a] > temp_data[b];
    }
    return a < b;
}

void pat1129() {
    int a;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (i != 0) {
            cout << a << ": ";
            for (int j = 0; j < temp.size() && j < m; ++j) {
                cout << temp[j];
                if (j != temp.size() - 1 && j != m - 1)
                    cout << " ";
            }
            cout << endl;
            if(i==n-1)
                break;
        }
        temp_data[a]++;
        if (temp_data[a] == 1)
            temp.push_back(a);
        sort(temp.begin(), temp.end(), cmp);
    }


}

int main() {
    pat1129();
    return 0;
}