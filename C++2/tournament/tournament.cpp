#include <bits/stdc++.h>

using namespace std;
const long maxn=100000+100;
int n,a[2*maxn],k,d[maxn];
vector <int> b[maxn];
int main()
{
    freopen("tournament.inp","r",stdin);
    freopen("tournament.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n ;i++ ) {
        int u,v;
        cin>>u>>v;
        b[u].push_back(v);
        b[v].push_back(u);
    } cin>>k;
    a[1]=1; a[0]=b[1][1];
    memset(d,true,sizeof(d));
    d[1]=false;
    for (int i=2 ; i<=n; i++){
        if (b[a[i-1]][0]!=a[i-2] && d[b[a[i-1]][0]])
            {a[i]=b[a[i-1]][0];d[b[a[i-1]][0]]=false; continue;}
        else
        if (d[b[a[i-1]][1]])
       {a[i]=b[a[i-1]][1]; d[b[a[i-1]][1]]=false; continue; }
        for (int j=1; j<=n; j++)
        if (d[j]) { a[i]=j; break; }
    }
    if (k>n/2) {cout<<0; return 0;}
    else {
        for (int i=1; i<=2*k; i+=2) cout<<a[i]<<" ";
    }
}
