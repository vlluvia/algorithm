#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct fraction {
    long up, down;
};

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

fraction fraction_add(fraction f1, fraction f2);

fraction reduction(fraction result) {

    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;

}

void pat1081() {
    int n;
    fraction f = {
            0, 1
    };
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int up_res, down_res;
        scanf("%d/%d", &up_res, &down_res);
        fraction f2 = {
                up_res, down_res
        };
        f = fraction_add(f, f2);
    }

    if (f.down == 1) printf("%lld", f.up);
    else if (abs(f.up) > f.down) {
        printf("%d %d/%d", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%d/%d", f.up, f.down);
    }
}

fraction fraction_add(fraction f1, fraction f2) {
    fraction res;
    res.up = f1.up * f2.down + f2.up * f1.down;
    res.down = f1.down * f2.down;
    return reduction(res);
}


//int main() {
//    pat1081();
//    return 0;
//}