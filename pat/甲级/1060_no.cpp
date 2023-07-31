#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

void pat1060() {

    int num;
    string s1, s2;
    cin >> num >> s1 >> s2;
    int s1_size = s1.find('.');
    int s2_size = s2.find('.');
    s1 = s1_size == -1 ? s1 : s1.replace(s1_size, 1, "");
    s2 = s2_size == -1 ? s2 : s2.replace(s2_size, 1, "");
    cout << s1.size() << "  " << s2.size() << endl;
    if (s1.size() < num) {
        char s[100];
        for (int i = 0; i < num - s1.size(); ++i) {
            s[i] = '0';
        }
        s1.insert(s1.size(), s);
    }
    if (s2.size() < num) {
        char s[100];
        for (int i = 0; i < num - s2.size(); ++i) {
            s[i] = '0';
        }
        s2.insert(s2.size()-1, s);
    }
    cout << "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    cout << s1.substr(0, num)  << endl;
    cout << s2.substr(0, num)    << endl;

    bool flag = s1.substr(0, num) == s2.substr(0, num);
    if (flag) {
        cout << "YES 0." << s1.substr(0, num) << "*10^" << (s1_size == -1 ? num : s1_size);
    } else {
        cout << "NO 0." << s1.substr(0, num) << "*10^" << (s1_size == -1 ? num : s1_size) << " 0." << s2.substr(0, num)
             << "*10^" << (s2_size == -1 ? num : s2_size);
    }

}


//int main() {
//    pat1060();
//    return 0;
//}