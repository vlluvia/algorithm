#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

int n;
map<string, string> data;
const int maxn = 10005;
int primes[maxn] = {0};

bool isPrime(int num) {
    if (num == 1) return false;
    int sqr = sqrt(num);
    for (int i = 2; i <= sqr; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void getPrimes() {
    int index = 0;
    for (int i = 1; i < maxn; ++i) {
        if (isPrime(i))
            primes[i] = 1;
    }
}

void pat1116() {
    getPrimes();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        if (i == 1)
            data[str] = "Mystery Award";
        else if (primes[i])
            data[str] = "Minion";
        else
            data[str] = "Chocolate";
    }
    int t;
    cin >> t;
    map<string, int> temp;
    for (int i = 0; i < t; ++i) {
        string str;
        cin>>str;
        if (data.find(str) == data.end()) {
            temp[str] = 1;
            cout << str << ": Are you kidding?" << endl;
        } else if (temp[str]) {
            cout << str << ": Checked" << endl;
        } else {
            cout << str << ": " << data[str] << endl;
            temp[str] = 1;
        }
    }
}

int main() {
    pat1116();
    return 0;
}