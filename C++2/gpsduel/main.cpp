#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> pii;
#define st first
#define nd second
const int N=100001;
vector<pii> a[N];
vector<ii> b[N];
int n,m,d1[N],d2[N],d[N];
priority_queue<ii> q;

void D1()
{
    while(!q.empty()) q.pop();
    q.push(ii(0,n));
    for(int i=1; i<=n; i++)
        d1[i]=N*10;
    d1[n]=0;
    while(!q.empty())
    {
        int u=q.top().nd,du=-q.top().st;
        q.pop();
        if(d1[u]!=du) continue;
        for(int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i].st;
            if(d1[v]>a[u][i].nd.st+d1[u])
            {
                d1[v]=a[u][i].nd.st+d1[u];
                q.push(ii(-d1[v],v));
            }
        }
    }
}

void D2()
{
    while(!q.empty()) q.pop();
    q.push(ii(0,n));
    for(int i=1; i<=n; i++)
        d2[i]=N*10;
    d2[n]=0;
    while(!q.empty())
    {
        int u=q.top().nd,du=-q.top().st;
        q.pop();
        if(d2[u]!=du) continue;
        for(int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i].st;
            if(d2[v]>a[u][i].nd.nd+d2[u])
            {
                d2[v]=a[u][i].nd.nd+d2[u];
                q.push(ii(-d2[v],v));
            }
        }
    }
}

void D()
{
    while(!q.empty()) q.pop();
    q.push(ii(0,1));
    for(int i=1; i<=n; i++)
        d[i]=N*10;
    d[1]=0;
    while(!q.empty())
    {
        int u=q.top().nd,du=-q.top().st;
        q.pop();
        if(d[u]!=du) continue;
        for(int i=0; i<b[u].size(); i++)
        {
            int v=b[u][i].st;
            if(d[v]>b[u][i].nd+d[u])
            {
                d[v]=b[u][i].nd+d[u];
                q.push(ii(-d[v],v));
            }
        }
    }
}

int main()
{
    freopen("gpsduel.in","r",stdin);
    freopen("gpsduel.out","w",stdout);
    cin>>n>>m;
    int u,v,c1,c2;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v>>c1>>c2;
        a[v].push_back(pii(u,ii(c1,c2)));
    }
    D1();
    D2();
    for(int i=1; i<=n; i++)
        for(int j=0; j<a[i].size(); j++)
        {
            int c1=a[i][j].nd.st,c2=a[i][j].nd.nd,v=a[i][j].st,c=0;
            if(d1[v]-d1[i]!=c1) c++;
            if(d2[v]-d2[i]!=c2) c++;
            b[v].push_back(ii(i,c));
            //cout<<v<<" "<<i<<" "<<c<<endl;
        }
    D();
    cout<<d[n]<<endl;
    return 0;
}
