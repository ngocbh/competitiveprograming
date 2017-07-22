#include <bits/stdc++.h>

using namespace std;
ifstream fi("salesman.inp");
ofstream fo("salesman.out");
int n, a[1550][1550],f[1550][1550];
int main()
{ fi>>n;
  for (int i=1; i<=n; i++)
     for (int j=1; j<=n; j++)  fi>>a[i][j];
  //===================
  for (int i=2; i<=n; i++)
     for (int j=1; j<=n; j++) f[i][j]=1000000000;
     f[1][0]=0;
    //===================
  for (int i=1; i<=n; i++)
     for (int j=i-1; j>=1; --j)
       { f[i][j]=min(f[i-1][j]+a[i][i-1],f[i][j]);
         f[i][i-1]=min(f[i][i-1],f[i-1][j]+a[j][i]);
       }
    int kq=1000000000;
   for (int i=1; i<=n; i++)
     //{for (int j=1; j<=n; j++) fo<<f[i][j]<<" "; fo<<endl;}
       if (kq>f[n][i]) kq=f[n][i];

   fo<<kq;
}
