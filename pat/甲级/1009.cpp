#include<bits/stdc++.h>

#define INF 1<<30
using namespace std;

double res[2005] = {0};
map<int, double> a;

void pat1009() {
    int t , nk, sum=0;
    double ank;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> nk >> ank;
        a[nk] = ank;
    }
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> nk >> ank;
        for(auto s : a){
            int k = s.first + nk;
            if(res[k] == 0) sum++;
            res[k] += (ank  * s.second);
            if(res[k] == 0) sum--;
        }
    }
    printf("%d", sum);
    for (int j = 2001; j >= 0 ; --j) {
        if(res[j] != 0){
            printf(" %d %.1lf", j, res[j]);
        }
    }
}

int main() {
    pat1009();
    return 0;
}
