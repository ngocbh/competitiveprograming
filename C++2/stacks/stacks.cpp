#include <fstream>
#include <stack>

using namespace std;
ifstream fi("stacks.inp");
ofstream fo("stacks.out");
const long maxn=100000+100;

int n,m,d[maxn],a[maxn],k,nb,l,r;
stack <int> b[4*maxn];

void xulya()
{    int xx;
    fi>>l>>r>>xx;
    //=======
    a[++k]=xx;
    int fu=0,fv = 0,u=nb+l-1,v=nb+r-1;
    while (u!=v){
         if ((u&1) && fu==0)
            { b[u].push(k); fu=1; }
                else
                    if ((u&1)==0 && (fu==1) && (u+1 != v) )
                        {  b[u+1].push(k); }
         ///==================
         if ((v&1)==0 && fv==0)
            { b[v].push(k); fv=1;  }
                else
                    if ((v&1)==1 && (fv==1) && (u+1 != v) )
                        {b[v-1].push(k);  }
         u>>=1;
         v>>=1;
    }
    if (fu==0 && fv==0) { b[u].push(k); return;}
    if (fu==0 ){    b[2*u].push(k);     return;  }
    if (fv==0){     b[2*u+1].push(k);   return;}
}
void xulyg()
{  int u,kx=0,kk,x;
    fi>>kk;
    u=nb+kk-1;
    while (u!=0){
        if (!b[u].empty()){
            do {
                x=b[u].top(); if (d[x]) b[u].pop();
            } while (d[x] && (!b[u].empty()));
        }
        if (b[u].empty() ) x=0; if (kx<x) kx=x;
        u>>=1;
    }
    if (a[kx]==0) fo<<-1<<'\n';
    else
    fo<<a[kx]<<'\n';
   // fo<<1;
}
void xulyr()
{  int kk;
    fi>>kk;
    d[kk]=1;
}
int main()
{
  fi>>n>>m; --n;
  for (int i=20; i>0; i--)
  if ((n >> i ) &1 ) { nb=(1<<(i+1)); break;}
  k=0;
  for (int i=1; i<=m; i++){
      char c;
      fi>>c;
      if (c=='A') xulya();
      if (c=='G') xulyg();
      if (c=='R') xulyr();
  }
//  for (int i=1; i<=4*n; i++) fo<<b[i].top();

}
