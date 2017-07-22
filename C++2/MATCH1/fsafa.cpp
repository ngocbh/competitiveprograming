#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 102;
int n, m, Assigned[N];
int Visited[N], t=0;
vector<int> a[N];

bool visit(int u) {
    if (Visited[u]!=t)
        Visited[u]=t;
    else
        return false;

    for (int i=0; int v=a[u][i]; i++)
    if (!Assigned[v] || visit(Assigned[v])) {
        Assigned[v]=u;
        return true;
    }
    return false;
}

main() {
    scanf("%d%d", &m, &n);
    int x, y;
    while (scanf("%d%d", &x, &y) > 0)
        a[x].push_back(y);
    for (int i=1; i<=m; i++)
        a[i].push_back(0);

    int Count = 0;
    for (int i=1; i<=m; i++) {
        t++;
        Count += visit(i);
    }
    printf("%d\n", Count);
    for (int i=1; i<=n; i++)
    if (int j=Assigned[i])
    printf("%d %d\n", j, i);
}
