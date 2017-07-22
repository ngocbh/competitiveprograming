#include <bits/stdc++.h>

using namespace std;
int n,m,s,t,ta[10100],qeue[10100],l,r;
bool a[10100][10100],f[10100];

void nhap()
{  freopen("stnode.inp","r",stdin);
   freopen("stnode.out","w",stdout);
   scanf("%d %d %d %d" , &n,&m,&s,&t);
    memset(a,false,sizeof(a));
    for (int i=1; i<=m; ++i)
    { int u,v;
      scanf("%d %d",&u,&v);
      a[u][v]=true;
    }
}
void khoitao()
{  memset(ta,0,sizeof(ta));
   memset(f,true,sizeof(f));
   f[s]=false;
   qeue[1]=s;
   l=1; r=1;
}
void bfs()
{ while ()

}
int main()
{ nhap();
  khoitao();
}
