#include <bits/stdc++.h>

#define INF 1<<29
using namespace std;

bool flag;
int n, mina = INF, min_size = INF, sum = 0;
map<char, int> mp_str;
vector<string> data;
vector<map<char, int>> data2;

map<char, int> transfer(string s) {
    map<char, int> mp;
    for (int i = 0; i < s.size(); ++i) {
        if (mp[s[i]]) mp[s[i]]++;
        else mp[s[i]] = 1;
    }
    return mp;
}

bool cmp(string a, string b) {
    return a < b;
}

void dfs(int ind, int surplus, int size) {
    if (sum > 150) return;
    sum++;
    if (surplus > mina) {
        return;
    }
    if (size == 0) {
        flag = true;
        if (surplus < mina) {
            mina = surplus;
        }
        return;
    }

    if (size < min_size) {
        min_size = size;
    }
    for (int i = ind + 1; i < data.size(); ++i) {
        int count = 0, temp_size = 0;
        map<char, int> tempC;
        for (auto &item:mp_str) {
            if (item.second > 0) {
                int t = min(data2[i][item.first], item.second);
                item.second -= t;
                temp_size += t;
                tempC[item.first] = t;
            }
        }

        dfs(i, surplus + data[i].size() - temp_size, size - temp_size);
        for (auto item : tempC) {
            mp_str[item.first] += item.second;
        }
    }
}

int main() {

    string bs, s;
    cin >> bs >> n;
    mp_str = transfer(bs);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        data.push_back(s);
        map<char, int> mp;
        for (int j = 0; j < data[i].size(); ++j) {
            if (mp_str.find(data[i][j]) != mp_str.end()) mp[data[i][j]]++;
        }
        data2.push_back(mp);
    }
    dfs(-1, 0, bs.size());
    if (flag) {
        cout << "Yes " << mina;
    } else {
        cout << "No " << min_size;
    }
    return 0;
}