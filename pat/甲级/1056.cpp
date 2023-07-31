#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;
struct node {
    int i;
    int data;
    int rank;
};
int np, ng;
vector<node> weight;
vector<int> need_order;

void pat1056() {
    cin >> np >> ng;
    for (int i = 0; i < np; ++i) {
        int w;
        cin >> w;
        node n = {
                i, w, -1
        };
        weight.push_back(n);
    }
    for (int i = 0; i < np; ++i) {
        int l;
        cin >> l;
        need_order.push_back(l);
    }
    //获取当前晋级的排名，分的组数+1.如果多出来一组（不满）则在加1
    int r = need_order.size() % ng ? (need_order.size() / ng) + 2 : (need_order.size() / ng) + 1;
    while (need_order.size() != 1) {
        int t = 0;
        vector<int> need;
        do {
            int max = -1;
            int in = 0;
            for (int h = t; h < t + ng && h < weight.size() && h < need_order.size(); h++) { //获取这一小组中最大的位置
                if (max < weight[need_order[h]].data) {
                    max = weight[need_order[h]].data;
                    in = need_order[h];
                }
            }
            //除了最大的，其他的rank都设置为r（之前算过的）。并将最大的位置放置到下一次需要比较
            for (int h = t; h < t + ng && h < weight.size() && h < need_order.size(); h++) {
                if (in != need_order[h]) {
                    weight[need_order[h]].rank = r;
                }
            }
            need.push_back(in);
            //下一小组
            t += ng;
        } while (t < need_order.size());
        need_order = need;
        r = need_order.size() % ng ? (need_order.size() / ng) + 2 : (need_order.size() / ng) + 1;
    }
    weight[need_order[0]].rank = 1;

    for (int i = 0; i < weight.size(); ++i) {
        cout << weight[i].rank ;
        if(i !=weight.size()-1){
            cout<<" ";
        }
    }
}

//int main() {
//    pat1056();
//    return 0;
//}