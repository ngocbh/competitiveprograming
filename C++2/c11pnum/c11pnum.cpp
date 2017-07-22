#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
ULL n,t,q,f[4000000],k1[17],cpr;
ULL a1[17],kq[4000000];
void khoitao()
{ ULL i,j,can,m;
  m=3000000;
  can=(int) sqrt(m);
  i=1;
  while (i<=can){
    i=i+2;
    if (f[i]==0){
        j=i*i;
        while   (j<=m ){
            f[j]=1;
            j=j+2*i;
        }
    }
  }
//  printf("%d",m);
  kq[1]=2;
  cpr=1; i=3;
  while (i<=m ){
    if (f[i]==0){
        cpr++;
        kq[cpr]=i;
    }
    i=i+2;
  }
}
ULL tim(ULL x)
{  ULL l=1, r=cpr,res=0;
  while (l<=r){
    ULL m;
    m=(l+r)/2;
    if (kq[m]<=x) res=m,l=m+1;
    else r=m-1;
  }
  return res;

}
void xuly(ULL a,ULL k)
{ ULL m,h;
  ULL q;
  h=(ULL)pow(a,(double)1/k);
  m=tim(h);
  //cout<<m;
  for (int i=m; i>=1; i--){
    q=1;
    for (int j=i; j<=i+k-1; j++)
        q=q*kq[j];
        //cout<<q<<" "<<a<<" ";
    if (q<=a&&q>0) { cout<<q<<endl; return; }
  }
  cout<<-1<<endl;
}
int main()
{ //freopen("c11pnum.inp","r",stdin);
  //freopen("c11pnum.out","w",stdout);
  khoitao();
  cin>>t;
  for (int i=1; i<=t;i++ ){
      //scanf("%I64d %d",&a1[i],&k1[i]);
      cin>>a1[i]>>k1[i];

  }
  for (int i=1; i<=t;i++ ){
      xuly(a1[i],k1[i]);

  }
 // double m;m=(double) pow(a,(double) 1/k);cout<<m;
  //for (int i=1; i<=300; i++) printf("%d \n",kq[i]);
 // int m; m=tim(705); printf("%d ",m);
}
