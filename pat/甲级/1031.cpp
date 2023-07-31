#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1031() {
    string str;
    cin >> str;
    int n = 0, n2 = 0;
    for (int i = 3; i < str.size(); ++i) {
        int a = (str.size() + 2 - i) % 2;
        int b = (str.size() + 2 - i) / 2;
        if (!a && b <= i) {
            n = b;
            n2 = i;
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << str[i];
        if (i != n - 1) {
            for (int k = 0; k < n2 - 2; ++k) {
                cout << " ";
            }
        }else{
            cout<<str.substr(n,n2-2);
        }
        cout << str[str.size() - i - 1] << endl;
    }

}


//int main() {
//    pat1031();
//    return 0;
//}