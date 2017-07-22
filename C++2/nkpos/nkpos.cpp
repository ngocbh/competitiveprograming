#include <bits/stdc++.h>

using namespace std;

int     n,m,w,a[300][300];
stack   <int> s;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&w);
    for (int i=1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        a[u][v]++;
        a[v][u]++;
    }
    s.push(1);
    printf("%d\n",m);
    while (not s.empty()) {
        int u = s.top();
        bool kt = true;
        for (int v=1;v<=n;v++) {
            if (a[u][v] > 0) {
                a[u][v]--;
                a[v][u]--;
                kt = false;
                s.push(v);
                break;
            }
        }
        if (kt) {
            printf("%d ",u);
            s.pop();
        }
    }
    return 0;
}

