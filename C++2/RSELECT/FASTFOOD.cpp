#include<bits/stdc++.h>

using namespace std;typedef pair<int, int> pi2;
typedef pair<int,pi2> pi3;
ifstream fi ("fastfoot.inp");
ofstream fo ("fastfood.out");
int b[6001]={0},c[6001]={0},cp[6001]={0},bp[6001]={0},bm[6001]={0},cm[6001]={0},
    n,n2,nb,k,t,t1,t2,bx,cx,cpx;
pi3 a[2250002],p;

int res[1501][1501]={0},ans[3000]={0},ib,ie,m;

void get_bx(int x)
{int tg,u,v,tgl,tgr;
 tgr=nb+x;tgl=nb+1;
 bx=(bm[tgl]==m)? b[tgl]:0;
 while(tgl!=tgr)
   {u=tgr>>1; v=tgl>>1;
    if(bm[2*u]==m)if( bx<b[2*u] && bp[2*u]<=x)bx=b[2*u];
    if(bm[2*u+1]==m)if( bx<b[2*u+1] && bp[2*u+1]<=x)bx=b[2*u+1];
    if(bm[2*v]==m)if( bx<b[2*v] && bp[2*v]<=x)bx=b[2*v];
    if(bm[2*v+1]==m)if( bx<b[2*v+1] && bp[2*v+1]<=x)bx=b[2*v+1];
    tgl>>=1; tgr>>=1;
   }
}
void get_cx(int x)
{int tg,u,v,tgl,tgr;
 tgl=nb+x;tgr=nb+n;
 cx=(cm[tgr]==m)?c[tgr]:0;
 while(tgr!=tgl)
   {u=tgl>>1; v=tgr>>1;
    if(cm[2*u]==m)if( cx<c[2*u] && cp[2*u]>=x)cx=c[2*u];
    if(cm[2*u+1]==m)if( cx<c[2*u+1] && cp[2*u+1]>=x)cx=c[2*u+1];
    if(cm[2*v]==m)if( cx<c[2*v] && cp[2*v]>=x)cx=c[2*v];
    if(cm[2*v+1]==m)if( cx<c[2*v+1] && cp[2*v+1]>=x)cx=c[2*v+1];
    tgl>>=1; tgr>>=1;
   }
}
void upd_bx(int x,int y)
{int tg,tgl,tgr,u,v;
 tgr=nb+x;tgl=nb+1;
 if(bm[tgr]==m)if(b[tgr]>y || (b[tgr]==y && bp[tgr]<=x))return;
 b[tgr]=y;bp[tgr]=x;bm[tgr]=m;
 while(tgr!=1)
 {u=tgr>>1;
  if(bm[2*u]!=m){b[2*u]=0; bm[2*u]=m;bp[2*u]=n+1;}
  if(bm[2*u+1]!=m){b[2*u+1]=0; bm[2*u+1]=m;bp[2*u+1]=n+1;}
  if(bm[u]!=m){bm[u]=m;b[u]=0;bp[u]=n+1;}
  if(b[u]<b[2*u]){b[u]=b[2*u];bp[u]=bp[2*u];}else if(b[u]==b[2*u] &&   bp[u]>bp[2*u])bp[u]=bp[2*u];
  if(b[u]<b[2*u+1]){b[u]=b[2*u+1];bp[u]=bp[2*u+1];}else if(b[u]==b[2*u+1] && bp[u]>bp[2*u+1])bp[u]=bp[2*u+1];
  tgr=u;tgl>>=1;
  }
}
void upd_cx(int x,int y)
{int tg,tgl,tgr,u,v;
 tgr=nb+n;tgl=nb+x;
 if(cm[tgl]==m)if(c[tgl]>y || (c[tgr]==y && cp[tgr]>=x))return;
 c[tgl]=y;cp[tgl]=x;cm[tgl]=m;
 while(tgl!=1)
 {u=tgl>>1;
  if(cm[2*u]!=m){c[2*u]=0; cm[2*u]=m;cp[2*u]=0;}
  if(cm[2*u+1]!=m){c[2*u+1]=0; cm[2*u+1]=m;cp[2*u+1]=0;}
   if(cm[u]!=m){cm[u]=m;c[u]=0;cp[u]=0;}
  if(c[u]<c[2*u]){c[u]=c[2*u];cp[u]=cp[2*u];}else if(c[u]==c[2*u] && cp[u]<cp[2*u])cp[u]=cp[2*u];
  if(c[u]<c[2*u+1]){c[u]=c[2*u+1];
cp[u]=cp[2*u+1];}else if(c[u]==c[2*u+1] && cp[u]<cp[2*u+1])cp[u]=cp[2*u+1];
  tgl=u;tgr>>=1;
 }
}
void xly_b(int x,int y)
{int i1,j1;
 for(int i=x;i<=y;++i)
   {i1=a[i].second.first; j1=a[i].second.second;
    get_bx(j1); t1=bx+1;res[i1][j1]=t1;
    upd_bx(j1,t1);
   }
}

void xly_c(int x, int y)
{int i1,j1,tg;
 //memset(c,0,sizeof(c));memset(cp,0,sizeof(cp));
 for(int i=y;i>=x;--i)
   {i1=a[i].second.first; j1=a[i].second.second;
    get_cx(j1); t1=cx+1;res[i1][j1]+=t1;
    upd_cx(j1,t1);
   }
}

void get_ans()
{for(int i=1;i<=n;++i)
   for(int j=1;j<=n;++j)
     {t=res[i][j]-1;
      ++ans[t];
     }
  for(int i=1;i<=2*n-1;++i)fo<<ans[i]<<' ';
}
int main()
{clock_t aa=clock();
 fi>>n; k=0;
 for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
     {fi>>t;p=make_pair(t,make_pair(i,j));
      a[++k]=p;
     }
  n2=n*n;
  for(int i=20;i>=0;--i) if(((n>>i) & 1) == 1){t=i+1;break;}
  nb=1<<t;--nb; m=0;
  sort(a,a+n2+1); a[n2+1].first=0;
  ib=1;t=a[1].first;
  for(int i=1;i<=n2+1;++i)
    if(t!=a[i].first){ie=i-1;t=a[i].first; ++m;
xly_b(ib,ie);xly_c(ib,ie); ib=i;}
 get_ans();
 clock_t bb=clock();
 fo<<"\nTime: "<<(double)(bb-aa)/1000<<" sec.";
}

