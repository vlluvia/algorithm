#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct fraction {
    long long up, down;
};


fraction reduction(fraction result);

void print(fraction f);

fraction fraction_add(fraction a, fraction b) {
    fraction c;
    c.up = a.up * b.down + a.down * b.up;
    c.down = a.down * b.down;
    return reduction(c);
}

fraction fraction_sub(fraction a, fraction b) {
    fraction c;
    c.up = a.up * b.down - a.down * b.up;
    c.down = a.down * b.down;
    return reduction(c);
}

fraction fraction_multiply(fraction a, fraction b) {
    fraction c;
    c.up = a.up * b.up;
    c.down = a.down * b.down;
    return reduction(c);
}

fraction fraction_divide(fraction a, fraction b) {
    fraction c;
    c.up = a.up * b.down;
    c.down = a.down * b.up;
    return reduction(c);
}

int gcd(long long a, long long b) {
    return !b ? a : gcd(b, a % b);
}

void pat1088() {
    fraction a{}, b{};
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    a = reduction(a);
    b = reduction(b);

    print(a);cout << " + ";print(b);cout << " = ";print(fraction_add(a, b));cout << endl;
    print(a);cout << " - ";print(b);cout << " = ";print(fraction_sub(a, b));cout << endl;
    print(a);cout << " * ";print(b);cout << " = ";print(fraction_multiply(a, b));cout << endl;
    print(a);cout << " / ";print(b);cout << " = ";
    if (b.up != 0) {
        print(fraction_divide(a, b));
    } else {
        printf("Inf");
    }
}


void print(fraction f) {
    f = reduction(f);
    if (f.up < 0) printf("(");
    if (f.down == 1) {
        printf("%lld", f.up);
    } else if (abs(f.up) > f.down) {
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }
    if (f.up < 0) printf(")");
}

fraction reduction(fraction result) {
    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs((result.up)), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

//
//int main() {
//    pat1088();
//    return 0;
//}