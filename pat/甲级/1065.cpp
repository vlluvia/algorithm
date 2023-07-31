#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

string add(string a, string b);

string sub(string a, string b);

void pat1065() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        long long int a, b, c;
        cin >> a >> b >> c;
        long long int c2 = a + b;
        printf("Case #%d: ", i);
        if (a < 0 && b < 0 && c2 >= 0) //最小负数相加溢出
            cout << "false" << endl;
        else if (a > 0 && b > 0 && c2 <= 0) //最大正数相加溢出
            cout << "true" << endl;
        else if (c2 > c)
            cout << "true" << endl;
        else
            cout << "false" << endl;

    }
}


//int main() {
//    pat1065();
//    return 0;
//}