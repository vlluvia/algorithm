#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

struct Gas{
    float price = 0, distance;
}gas[510];

bool cmp(Gas a, Gas b){
    return a.distance < b.distance;
}

int main(){
    float c, d, d_avg;
    int n;
    scanf("%f%f%f%d", &c, &d, &d_avg, &n);
    for (int i = 0; i < n; i++)
        scanf("%f%f", &gas[i].price, &gas[i].distance);
    gas[n].distance = d;
    sort(gas, gas + n, cmp);
    if (gas[0].distance != 0){ //如果起点没有加油站
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    int g_now = 0;
    float count = 0, fuel = 0, now = 0;
    while (now < d){
        float max = gas[g_now].distance + c*d_avg; //当前加油站能达到的最远距离
        if (max < gas[g_now + 1].distance || (g_now == n - 1 && max < d)){ //如果满油也到不了下一个加油站
            printf("The maximum travel distance = %.2f", max);
            return 0;
        }
        int g_next = -1;
        float temp = 200;
        for (int i = g_now + 1; i <= n; i++){ //查找能到达的所有加油站的最低价格
            if (gas[i].distance>max)
                break;
            if (gas[i].price < gas[g_now].price){
                temp = gas[i].price;
                g_next = i;
                break;
            }
            if (gas[i].price < temp){
                temp = gas[i].price;
                g_next = i;
            }
        }
        if (g_next == -1 || g_next== n){ //已经是最后一个加油站
            count += (((d - gas[g_now].distance) / d_avg) - fuel)*gas[g_now].price;
            printf("%.2f", count);
            return 0;
        }
        if (temp <= gas[g_now].price){ //如果有比当前加油站还低的价格，加刚好加油到那个加油站
            if (((gas[g_next].distance - gas[g_now].distance) / d_avg) - fuel < 0){
                g_now = g_next;
                fuel -= (gas[g_next].distance - gas[g_now].distance) / d_avg;
                now = gas[g_next].distance;
                continue;
            }
            count += (((gas[g_next].distance - gas[g_now].distance) / d_avg) - fuel)*gas[g_now].price;
            g_now = g_next;
            fuel = 0;
            now = gas[g_next].distance;
            continue;
        }
        else{ //如果接下来的加油站没有比这个价格更低的
            //就在这个地方加满油，到下一个价格最低的加油站
            count += (c - fuel)*gas[g_now].price;
            fuel = c - (gas[g_next].distance - gas[g_now].distance) / d_avg;
            g_now = g_next;
            now = gas[g_next].distance;
            continue;
        }
    }
    return 0;
}