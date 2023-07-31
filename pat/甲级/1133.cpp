#include<bits/stdc++.h>
#include<string>

#define INF 1<<29
using namespace std;

struct node {
    int data, out, in;
};

int n, k, beg;
map<int, node> data;
vector<node> big_zero, small_zero;


void pat1133() {
    cin >> beg >> n >> k;
    for (int i = 0; i < n; ++i) {
        int in, d, out;
        cin >> in >> d >> out;
        data[in] = {
                d, out, in
        };
    }

    while (beg != -1) {
        if (data[beg].data >= 0) {
            big_zero.push_back(data[beg]);
        } else {
            small_zero.push_back(data[beg]);
        }
        beg = data[beg].out;
    }
    vector<node> temp1, temp2,res;
    if (k >= 0) {
        for (int i = 0; i < big_zero.size(); ++i) {
            if (big_zero[i].data <= k) {
                temp1.push_back(big_zero[i]);
            } else {
                temp2.push_back(big_zero[i]);
            }
        }
        res= small_zero;
        res.insert(res.end(),temp1.begin(),temp1.end());
        res.insert(res.end(),temp2.begin(),temp2.end());
    } else {
        for (int i = 0; i < small_zero.size(); ++i) {
            if (small_zero[i].data <= k) {
                temp1.push_back(small_zero[i]);
            } else {
                temp2.push_back(small_zero[i]);
            }
        }
        res= temp1;
        res.insert(res.end(),temp2.begin(),temp2.end());
        res.insert(res.end(),big_zero.begin(),big_zero.end());
    }

    for (int i = 0; i < res.size()-1; ++i) {
        printf("%05d %d %05d\n",res[i].in,res[i].data,res[i+1].in);
    }
    printf("%05d %d -1",res[ res.size()-1].in,res[ res.size()-1].data);

}

int main() {
    pat1133();
    return 0;
}