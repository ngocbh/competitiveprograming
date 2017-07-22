#include <stdio.h>
#include <vector>
using namespace std;

vector<int> a[230997]; //
int parent[230997]; //
int l[230997];
int M[230997][23];
int n;

void direct(int u){
    int i, v;
    for (i=0; v=a[u][i]; i++)
    if (v!=parent[u]) {
        parent[v]=u;
        l[v]=l[u]+1;
        direct(v);
    }
}

void make_lca(){
    int i, k;
    for (i=1; i<=n; i++) M[i][0]=parent[i];

    for (k=1; k<=20; k++)
    for (i=1; i<=n; i++)
    M[i][k]=M[M[i][k-1]][k-1];
}

int lca(int p, int q){
    int i;

    // ensure l[p]=l[q]
    for (i=20; i>=0; i--) if (l[M[p][i]] >= l[q]) p=M[p][i];
    for (i=20; i>=0; i--) if (l[M[q][i]] >= l[p]) q=M[q][i];

    if (p==q) return p;
    for (i=20; i>=0; i--) if (M[p][i]!=M[q][i]) { p=M[p][i], q=M[q][i]; }
    return parent[p];
}

main(){
    int i, j, p, q, m, T, t;
    T = 1;

    for (t=1; t<=T; t++){
        scanf("%d", &n);

        for (i=1; i<=n; i++) { a[i].clear(); parent[i]=0; }
        printf("Case %d:\n", t);

        for (i=1; i<=n; i++) {
            scanf("%d", &m);
            for (j=1; j<=m; j++) {
                scanf("%d", &p);
                a[i].push_back(p);
            }
        }
        for (i=1; i<=n; i++) a[i].push_back(0);

        for (i=1; i<=n; i++)
        if (parent[i]==0){ parent[i]=i; l[i]=1; direct(i); }
        make_lca();

        scanf("%d", &m);
        while (m--){
            scanf("%d%d", &p, &q);
            printf("%d\n", lca(p, q));
        }
    }
}
