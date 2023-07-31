#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 100100;
const int BE = 8*3600;
const int ED = 17*3600;
int tim[maxn];
struct Node{
    int pro,st,ed;
};
vector <Node> vc;
bool cmp(Node a,Node b)
{
    return a.st<b.st;
}
int main(void)
{
    Node tmp;
    int n,i,x,k,hh,mm,ss,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&x);
        tmp.st=hh*3600+mm*60+ss;
        tmp.pro=x*60;
        tmp.ed=tmp.st+tmp.pro;
        if(tmp.st<ED) vc.push_back(tmp);
    }
    if(vc.size()==0){
        printf("0.0\n");
        return 0;
    }
    double sum=0;
    int pos,mi;
    for(i=0;i<k;i++) tim[i]=BE;
    sort(vc.begin(),vc.end(),cmp);
    for(i=0,x=vc.size();i<x;i++){
        for(j=1,mi=tim[0],pos=0;j<k;j++) //这里很重要，一定要找到一个，不能一个也找不到。
            if(mi>tim[j]){
                mi=tim[j];pos=j;
            }

        if(mi<=vc[i].st){
            tim[pos]=vc[i].ed;
        }
        else{
            tim[pos]=mi+vc[i].pro;
            sum+=(mi-vc[i].st);
        }
    }
    printf("%.1lf\n",sum/(60*x));
    return 0;
}