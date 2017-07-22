#include <bits/stdc++.h>

using namespace std;
int n,x,y,a[100100];
long long f[100100],dem;

int tim(int x)
{ int res,l,r;
    l=1; r=n;
    while (l<=r)
   { int m;
     m=(l+r)/2;
     if (x>=f[m])  res=m,l=m+1;
     else r=m-1;
   }
  return res;

}
int tim1(int x)
{ int res,l,r;
    l=1; r=n;
    while (l<=r)
   { int m;
     m=(l+r)/2;
     if (x<=f[m])  res=m,r=m-1;
     else l=m+1;
   }
  return res;

}
void xuly()
{ for (int i=1 ; i<=n; ++i)
  if (a[i]<=y)
  {  int i1,i2;
     i1=tim(a[i]+y);
     i2=tim1(a[i]+x);
     if (i1>=i2) dem=dem+(i1-i2+1);
  }

}
int main()
{ // freopen("c11seq.inp","r",stdin);
   //freopen("c11seq.out","w",stdout);
 cin>>n>>x>>y;
  for (int i=1; i<=n; i++)
  { cin>>a[i];
    f[i]=f[i-1]+a[i];
  }
  sort(f+1,f+n+1);
 // int k; for (int i=1; i<=n; ++i) printf("%d " ,f[i]); printf("\n");
 // k=tim(12); printf("%d ", k );
 xuly();
cout<<dem;

}
