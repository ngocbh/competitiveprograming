#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#define maxn 10000+100
using namespace std;
int n,m,s,t,ta[maxn];
bool ca[maxn],fr[maxn];
vector <int> a[maxn];
void khoitao()
{
    for (int i=1; i<=n; i++) a[i].push_back(0);
    memset(fr,true,sizeof(fr));
    fr[0]=false;
}
void bfs()
{   queue <int> qe;
    int u;
    qe.push(s);
    fr[s]=false;
    while (!qe.empty())
    {
            u=qe.front();
            qe.pop();
            int v;
            for (int i=0; v=a[u][i];i++)
                if ( fr[v] ){
                    fr[v]=false;
                    qe.push(v);
                    ta[v]=u;
                }
    }
}
void vet()
{
    if (fr[t]) cout<<"Khong co duong di";
    else {
        while (t!=s){
            cout<<t<<" ";
            t=ta[t];
        }
        cout<<s;
   }
}
int main()
{   freopen("bfs.inp","r",stdin);
    freopen("bfs.out","w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1; i<=m; i++){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    khoitao();
    bfs();
    vet();

}
