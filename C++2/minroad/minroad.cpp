#include <bits/stdc++.h>

using namespace std;
int n,t1[300010],t2[300010],a,b,maxn=1000000000;
pair <int,int>  f[300010];
void nhap()
{
  //freopen("minroad.inp","r",stdin);
  //freopen("minroad.out","w",stdout);
  scanf("%d%d%d" ,&n,&a,&b);
   for (int i=1; i<=n;  i++){
      scanf("%d%d",&f[i].first,&f[i].second);
   }
   sort(f+1,f+n+1);
   for (int i=1; i<=n; i++){
        if (f[i].second==1)  t1[i]=t1[i-1]+1; else t1[i]=t1[i-1];
      if (f[i].second==2)  t2[i]=t2[i-1]+1; else t2[i]=t2[i-1];
   }
f[n+1].first=1000000000;
}
int tim1(int x)
{ int l=1, r=n,res=0;
 while (l<=r)
   { int m;
     m=(l+r)/2;
     if (x>t1[m])  res=m,l=m+1;
     else r=m-1;
   }

  if (res==n)
  {  if (t1[res]>=x ) return res;
     else return res+1;

  }
  return res+1;

}
int tim2(int x)
{ int l=1, r=n,res=0;
 while (l<=r)
   { int m;
     m=(l+r)/2;
     if (x>t2[m])  res=m,l=m+1;
     else r=m-1;
   }
  if (res==n)
  {  if (t2[res]>=x ) return res;
     else return res+1;

  }
  return res+1;

}
int tim(int x,int y)
{ int m1,m2;
  m1=tim1(x);
  m2=tim2(y);
  return max(m1,m2);
}
void xuly()
{    for (int i=1; i<=n ; i++)
      if (t1[i]+a-1<=t1[n] && t2[i]+b-1<=t2[n]){
        int m;
        if (f[i].second==1) m=tim(t1[i]+a-1,t2[i]+b);
        else m=tim(t1[i]+a,t2[i]+b-1);
        if (f[m].first-f[i].first<maxn ) maxn=f[m].first-f[i].first;
        //printf("%d ",m);
     }
 //printf("\n");

}
int main()
{  nhap();
   if (t1[n]<a || t2[n]<b) { printf("-1"); return 0;}
   xuly();
   // for (int i=1; i<=n ; i++) printf("%d ",t1[i]); printf("\n");
    //for (int i=1; i<=n ; i++) printf("%d ",t2[i]); printf("\n");
  // int i=149; int m; m=tim(150,2);

   printf("%d ",maxn);
}
