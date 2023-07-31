#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

int n;
set<int> res;

void pat1120() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        int sum = 0;
        do {
            sum += (num % 10);
            num /= 10;
        } while (num != 0);
        res.insert(sum);
    }

    cout << res.size() << endl;
    int j=0;
    for (auto &item:res) {
        cout<< item ;
        if(j!=res.size()-1){
            cout<<" ";
        }
        j++;
    }
}

int main() {
    pat1120();
    return 0;
}