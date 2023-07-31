#include <bits/stdc++.h>

using namespace std;

int ca, cb, n;

int main() {
    while(cin>>ca>>cb>>n){
        int a = 0, b = 0;
        if(ca == n){
            cout<<"fill A\nsuccess"<<endl;
            continue;
        }
        if(cb == n){
            cout<<"fill B\nsuccess"<<endl;
            continue;
        }
        while(true){
            if(a == 0){
                a = ca;
                cout<<"fill A"<<endl;
            }else if(a +b <= cb){
                b+=a;
                a = 0;
                cout<<"pour A B"<<endl;
            }else{
                a = a - (cb-b);
                b = cb;
                cout<<"pour A B"<<endl;
            }
            if(b == cb){
                cout<<"empty B"<<endl;
                b=0;
            }
            if(b == n){
                cout<<"success"<<endl;
                break;
            }
        }
    }
    return 0;
}