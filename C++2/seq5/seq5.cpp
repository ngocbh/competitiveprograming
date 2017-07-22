#include <bits/stdc++.h>

using namespace std;
ifstream fi("seq5.inp");
ofstream fo("seq5.out");
int64_t n,k,a[1010],b[5]={5,1,-2,3,-4};
int64_t f[1010][220][5];
int main()
{
   fi>>n>>k;
   for (int i=1; i<=n; i++) fi>>a[i];
    //============================
   for (int i=0; i<=n; i++)
    for (int j=0; j<=k; j++)
     { for (int l=0; l<=4; l++)

        {   if (i==0&&j==0&&l==0) f[i][j][l]=0;
            else
            f[i][j][l]=-100000000000000000000;
             if (i==0) continue;
             f[i][j][l]=f[i-1][j][l];
                if (l>0)
                    f[i][j][l]=max( f[i-1][j][l] , f[i-1][j][l-1]+a[i]*b[l] );
                else
                  if (j>0)
                    f[i][j][0]=max( f[i][j][l] , f[i-1][j-1][4]+a[i]*b[l] );
        }
     }
   fo<<f[n][k][0]<<endl;
  // for (int i=1; i<=n; i++)
   //for (int j=1; j<=k; j++)
   //{ for (int l=0; l<=4; l++) fo<<f[i][j][l]<<" "; fo<<f[i][j][0]<<endl; }
}
