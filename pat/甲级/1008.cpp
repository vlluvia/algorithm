#include<bits/stdc++.h>

using namespace std;

int n;
int data[105];
int sum = 0;
int last_floor = 0;

void pat1008() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int floor;
        cin >> floor;
        if (last_floor < floor) {
            int c = floor - last_floor;
            sum += (c * 6 + 5);
        } else if(last_floor > floor){
            int c = last_floor - floor;
            sum += (c * 4 + 5);
        } else{
            sum += 5;
        }
        last_floor = floor;
    }
    cout << sum;
}


//int main() {
//    pat1008();
//    return 0;
//}