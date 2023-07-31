#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
bool vis[520];
int dispre[520],timepre[520],e[520][520],t[520][520],dis[520],tim[520],distim[520],nodenum[520];
int st,en;
vector<int>dispath,timepath;
void dfsdispath(int v)
{
    if(v==st)
    {
        dispath.push_back(v);
        return ;
    }
    dfsdispath(dispre[v]);
    dispath.push_back(v);
}
void dfstimepath(int v)
{
    if(v==st)
    {
        timepath.push_back(v);
        return ;
    }
    dfstimepath(timepre[v]);
    timepath.push_back(v);
}
int main(void)
{
    fill(dis,dis+520,inf);
    fill(tim,tim+520,inf);
    fill(t[0],t[0]+520*520,inf);
    fill(e[0],e[0]+520*520,inf);
    fill(distim,distim+520,inf);
    int n,m;
    scanf("%d %d",&n,&m);
    int a,b,flag,len,ti;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d %d",&a,&b,&flag,&len,&ti);
        e[a][b]=len;
        t[a][b]=ti;
        if(flag!=1)
        {
            e[b][a]=len;
            t[b][a]=ti;
        }
    }
    scanf("%d %d",&st,&en);
    dis[st]=0;
    for(int i=0;i<n;i++) dispre[i]=i;
    for(int i=0;i<n;i++)
    {
        int u=-1,minn=inf;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false&&dis[j]<minn)
            {
                u=j;
                minn=dis[j];
            }
        }
        if(u==-1) break;
        vis[u]=true;
        for(int v=0;v<n;v++)
        {
            if(vis[v]==false&&e[u][v]!=inf)
            {
                if(dis[u]+e[u][v]<dis[v])
                {
                    dis[v]=dis[u]+e[u][v];
                    dispre[v]=u;
                    distim[v]=distim[u]+t[u][v];
                }else if(dis[u]+e[u][v]==dis[v]&&distim[u]+t[u][v]<distim[v])
                {
                    distim[v]=distim[u]+t[u][v];
                    dispre[v]=u;
                }
            }
        }
    }
//	printf("%d",dis[en]); 
    dfsdispath(en);
    tim[st]=0;
    fill(vis,vis+520,false);
    for(int i=0;i<n;i++)
    {
        int u=-1,minn=inf;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false&&tim[j]<minn)
            {
                u=j;
                minn=tim[j];
            }
        }
        if(u==-1) break;
        vis[u]=true;
        for(int v=0;v<n;v++)
        {
            if(vis[v]==false&&e[u][v]!=inf)
            {
                if(tim[u]+t[u][v]<tim[v])
                {
                    tim[v]=tim[u]+t[u][v];
                    timepre[v]=u;
                    nodenum[v]=nodenum[u]+1;
                }else if(tim[u]+t[u][v]==tim[v]&&nodenum[u]+1<nodenum[v])
                {
                    nodenum[v]=nodenum[u]+1;
                    timepre[v]=u;
                }
            }
        }
    }
    dfstimepath(en);
    //printf("%d",dis[en]);
    if(timepath==dispath)
    {
        printf("Distance = %d; Time = %d: ",dis[en],tim[en]);
        for(int i=0;i<dispath.size();i++)
        {
            printf("%d",dispath[i]);
            if(i!=dispath.size()-1) printf(" -> ");
        }
    }else
    {
        printf("Distance = %d: ",dis[en]);
        for(int i=0;i<dispath.size();i++)
        {
            printf("%d",dispath[i]);
            if(i!=dispath.size()-1) printf(" -> ");
        }
        printf("\nTime = %d: ",tim[en]);
        for(int i=0;i<timepath.size();i++)
        {
            printf("%d",timepath[i]);
            if(i!=timepath.size()-1) printf(" -> ");
        }
    }

    return 0;
}