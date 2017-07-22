#include <bits/stdc++.h>

using namespace std;
ifstream fi("domine.inp");
ofstream fo("domine.out");
int n,j,a[1010][4],f[1010][1010];
int main()
{  fi>>n>>j;
   for (int i=1; i<=n; i++)
     for (int j=1; j<=3; j++)
       fi>>a[i][j];
   ///===============
   memset(f,0,sizeof(f));
   for (int i=1; i<=n ;i++)
     for (int k=0 ; k<=j; k++)
      {  int a1=-100000000,a2=-100000000,a3=-100000000,a4=-100000000,a5=-100000000,a6=-100000000,a7;

         if( k>0) a1=f[i-1][k-1]+ max(a[i][1],a[i][3])+a[i][2];

         if (i>2) a2=f[i-2][k-1]+ max(a[i-1][1]+a[i][1],max(a[i-1][2]+a[i][2],a[i-1][3]+a[i][3]));

         if (i>2&&k>2) a3=f[i-2][k-2]+ max(a[i-1][1]+a[i][1] ,      a[i-1][3]+a[i][3])+   a[i-1][2]+a[i][2];

         if (i>2&&k>2) a4=f[i-2][k-2]+ max(a[i-1][2]+a[i-1][3],     a[i][2]+a[i][3] )+  a[i-1][1]+a[i][1];

         if (i>2&&k>2) a5=f[i-2][k-2]+ max(a[i-1][1]+a[i-1][2],     a[i][1]+a[i][2] )+  a[i-1][3]+a[i][3];

         if (i>2&&k>3) a6=f[i-2][k-3]+a[i-1][1]+a[i-1][2]+a[i-1][3]+a[i][1]+a[i][2]+a[i][3];

         a7=f[i-1][k];

         f[i][k]=max(a1,max(a2,max(a3,max(a4,max(a5,max(a6,a7))))));
      }
  fo<<f[n][j]<<endl;
 //for (int i=0; i<=n ;i++)
    //{for (int k=0 ; k<=j; k++)fo<<f[i][k]<<" "; fo<<endl;}
}
