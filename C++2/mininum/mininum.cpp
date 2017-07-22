#include <bits/stdc++.h>

using namespace std;
//ifstream fi("mininum.inp");
//ofstream fo("mininum.out");
int m,n,k,a[100010],f[1000010];
void nhap()
{ freopen("mininum.inp","r",stdin);
  freopen("mininum.out","w",stdout);
  scanf("%d %d", &n,&k);
  for (int i=1; i<=n; ++i) scanf("%d " ,&a[i]);
}
void khoitao()
{
  ///=================
  int64_t min1=1000000000000;
  m=(int )sqrt(n);
  for (int i=1; i<=n; ++i)
    { if (a[i]<min1) min1=a[i];
      if ( i % m==0 )
     { f[i/m]=min1;
        min1=1000000000000;
     }
    }
}
int64_t timmin(int e,int b)
{ int c,d;
 int64_t min1=1000000000000;
 if (b>n) b=n;
c=(e/m+2);
d=b/m+1;
  if (d-c<=0)
  { for (int i=e; i<=b; ++i)
      if (a[i]<min1)
        min1=a[i];
    return min1;
  }
 //===========
 for (int i=e; i<=c*m; ++i)  if (a[i]<min1) min1=a[i];
 for (int i=(d-1)*m; i<=b;++i) if (a[i]<min1) min1=a[i];
 for (int i=c; i<=d-1; ++i) if (f[i]<min1) min1=f[i];
 return min1;


}
void xuly()
{ for (int i=1; i<=n-k+1; ++i)
   {  int h;
     h=timmin(i,i+k-1);
     printf("%d ", h);
     printf("\n");

   }

}
int main()
{ nhap();
 khoitao();
 xuly();
//for (int i=1; i<=n; ++i) {printf("%d", f[i] ); printf("\n");}

 //int m; m=timmin(12,16);printf("%lld ",k);

}
