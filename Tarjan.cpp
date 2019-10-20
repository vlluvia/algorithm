
/*
 * poj1236,poj3177,poj3164
 */

int dfn[maxn],low[maxn],scc[maxn], stack[maxn],index=0,sccnum=0,top=0;\

void tarjan(int root){
    if(dfn(root)) return ;
    dfn[root] = low[root]= ++index;
    stack[++top] = root;
    for (int i = head[root]; ~i ; i=e[i].ne) {
        int v = e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[root] = min(low[root],low[v]);
        }else if(!scc[v]){
            low[root] = min(low[root],dfn[v]);
        }
    }

    if(low[root]==dfn[root]){
        sccnum++;
        int x;
        do{
            x = stack[top--];
            scc[x]= sccnum;
        }while (x==root);
    }
}

