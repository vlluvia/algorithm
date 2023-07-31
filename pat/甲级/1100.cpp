#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

string num[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string num2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void pat1100() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        string t;
        getline(cin, t);
        if (t[0] >= '0' && t[0] <= '9') {
            int temp;
            stringstream ss;
            ss << t;
            ss >> temp;
            int a = temp % 13;
            int b = temp / 13;
            if (a == 0) {
                cout << num2[b] << endl;
            } else if (b == 0) {
                cout << num[a] << endl;
            } else {
                cout << num2[b] << " " << num[a] << endl;
            }
        } else {
            int site = t.find(' ');
            if (site != -1) {
                string pre = t.substr(0, site);
                string back = t.substr(site + 1, t.size());
                int i_pre = 0, i_back=0;
                for (int j = 0; j < 13; ++j) {
                    if (back == num[j]) {
                        i_back = j;
                        break;
                    }
                }
                for (int j = 0; j < 13; ++j) {
                    if (pre == num2[j]) {
                        i_pre = j;
                        break;
                    }
                }
                int res = i_pre * 13 + i_back;
                cout << res << endl;
            } else {
                int res=-1;
                for (int j = 0; j < 13; ++j) {
                    if (t == num[j]) {
                        res = j;
                        break;
                    }
                }
                if(res==-1){
                    for (int j = 0; j < 13; ++j) {
                        if (t == num2[j]) {
                            res = j*13;
                            break;
                        }
                    }
                }
                cout << res << endl;
            }
        }
    }

}

int main() {
    pat1100();
    return 0;
}