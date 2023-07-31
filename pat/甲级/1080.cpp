#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct Stu{
    int id, ge, gi, total, rank;
    int choice[5];
}s[40010];

struct School{
    int choice = 0, quota, last = -1;
    int admit[40010];
}sc[101];

bool cmp(Stu a, Stu b){
    if (a.total != b.total)
        return a.total > b.total;
    else
        return a.ge > b.ge;
}

bool cmpsc(int a, int b){
    return s[a].id < s[b].id;
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
        scanf("%d", &sc[i].quota);
    for (int i = 0; i < n; i++){
        s[i].id = i;
        scanf("%d%d", &s[i].ge, &s[i].gi);
        for (int j = 0; j < k; j++)
            scanf("%d", &s[i].choice[j]);
        s[i].total = s[i].ge + s[i].gi;
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++)
        if (i>0 && s[i].total == s[i - 1].total&&s[i].ge == s[i-1].ge)
            s[i].rank = s[i - 1].rank;
        else
            s[i].rank = i;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            if (sc[s[i].choice[j]].choice < sc[s[i].choice[j]].quota ||
                (sc[s[i].choice[j]].last != -1 && s[i].rank == s[sc[s[i].choice[j]].last].rank)){
                sc[s[i].choice[j]].admit[sc[s[i].choice[j]].choice] = i;
                sc[s[i].choice[j]].choice++;
                sc[s[i].choice[j]].last = i;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++){
        if (sc[i].choice>0){
            sort(sc[i].admit, sc[i].admit + sc[i].choice,cmpsc);
            for (int j = 0; j < sc[i].choice; j++){
                if (j == sc[i].choice - 1)
                    printf("%d", s[sc[i].admit[j]].id);
                else
                    printf("%d ", s[sc[i].admit[j]].id);
            }
        }
        printf("\n");
    }
    return 0;
}