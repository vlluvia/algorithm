#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,k,m;
int ans[6];

struct stu{
    int id;
    int score;
    int num[6] = {-2,-2,-2,-2,-2,-2};
    int rank;
};

stu sum[11000], peo[11000];

bool cmp(stu a, stu b){
    bool flag ;
    int c = 0, d = 0;
    if(a.score == b.score){
        for(int i=1; i<=m; i++){
            if(a.num[i] == ans[i]) c++;
            if(b.num[i] == ans[i]) d++;
        }
        if(c == d ) return a.id < b.id;
        else return c > d;
    }
    else return a.score > b.score;
}

int main(){

    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=m; i++){
        scanf("%d",&ans[i]);
    }
    for(int i=0; i<k; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        sum[a].id = a;
        if(sum[a].num[b] < c)
            sum[a].num[b] = c;
    }

    int nu = 0;
    for(int j=1; j<=n; j++){ //之前这个地方有误
        bool ke = false;
        for(int i=1; i<=m; i++){
            if(sum[j].num[i] != -2 && sum[j].num[i] != -1) ke = true;
        }
        if(ke) {
            peo[nu] = sum[j];
            nu++;
        }
    }

    for(int j=0; j<nu; j++)
        for(int i=1; i<=m; i++){
            if(peo[j].num[i] == -1)
                peo[j].num[i] = 0;
            if(peo[j].num[i] != -2)
                peo[j].score += peo[j].num[i];
        }
    sort(peo,peo+nu,cmp);

    peo[0].rank = 1;
    for(int i=1; i<=nu; i++){
        if(peo[i].score == peo[i-1].score) peo[i].rank = peo[i-1].rank;
        else peo[i].rank = i+1;
    }

    for(int j=0; j<nu; j++){
        printf("%d %05d %d",peo[j].rank,peo[j].id,peo[j].score);
        for(int i=1; i<=m; i++){
            if(peo[j].num[i] == -2)
                cout << " -";
            else cout << " " << peo[j].num[i] ;
        }
        cout << endl;
    }

    return 0;
}