#include<bits/stdc++.h>

using namespace std;

string s;

void pat1005() {

    cin >> s;
    int res = 0;
    for (char i : s) {
        res += (i - 48);
    }
    char res_string[10];
    sprintf(res_string, "%d", res);

    // 输出
    for (int j = 0; j < strlen(res_string); ++j) {
        bool b = true;
        if (j==strlen(res_string)-1){
            b = false;
        }
        if (res_string[j]=='0'){
            cout << "zero";
        } else if(res_string[j]=='1'){
            cout << "one";
        } else if(res_string[j]=='2'){
            cout << "two";
        } else if(res_string[j]=='3'){
            cout << "three";
        } else if(res_string[j]=='4'){
            cout << "four";
        } else if(res_string[j]=='5'){
            cout << "five";
        } else if(res_string[j]=='6'){
            cout << "six";
        } else if(res_string[j]=='7'){
            cout << "seven";
        } else if(res_string[j]=='8'){
            cout << "eight";
        } else if(res_string[j]=='9'){
            cout << "nine";
        }
        if (b){
            cout << " ";
        }
    }
}

//int main() {
//    pat1005();
//    return 0;
//}