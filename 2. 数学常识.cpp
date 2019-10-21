

// 最大公约数
int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}


// 分数加减乘除
struct Fraction {
    int up, down;
};

Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }

    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), gcd(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction minu(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void show(Fraction r) {
    r = reduction(r);
    if (r.down == 1) printf("%lld", r.up);
    else if (abs(r.up) > r.down) {
        printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);
    } else {
        printf("%d/%d", r.up, r.down);
    }
}


// 素数
bool isPrime(int n) {
    if (n <= 1) return false;
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}


// 大整数相加
string add(string a, string b) {
    string res;
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size() || i < b.size(); ++i) {
        int a_i = a[i] - '0';
        int b_i = a[i] - '0';
        int temp = a_i + b_i + carry;
        res += to_string(temp % 10);
        carry = temp / 10;
    }
    if (carry != 0) {
        res += to_string(carry % 10);
    }
    reverse(res.begin(), res.end());
    return res;
}
