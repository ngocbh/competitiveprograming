#include <bits/stdc++.h>

using namespace std;
ifstream fi("tilechng.inp");
ofstream fo("tilechng.out");
const long maxn=10+1;
const long maxm=1000000+100;
const long maxa=100+10;
int n,m,a[maxn],f[maxn][maxm],t[maxn][maxm],res=0,rr;
int main()
{
    fi>>n>>m;
    for (int i=1; i<=n; i++) { fi>>a[i]; res+=a[i]*a[i]; }
    rr=max(m,res);
  //  fo<<res;
   for (int j=1; j<=rr; j++) f[0][j]=0;
   memset(t,false,sizeof(t));
   t[0][res]=true;
                    ///============
    for (int i=1; i<=n; i++)
        for (int j=1; j<=rr; j++)
        {       f[i][j]=100000000;
                for (int k=1; k<=100; k++)
                    if (j+a[i]*a[i]-k*k>0 )
                    if (t[i-1][j+a[i]*a[i]-k*k]){
                     f[i][j]=min(f[i-1][j+a[i]*a[i]-k*k]+(abs(k-a[i])*abs(k-a[i])),f[i][j]);
                     t[i][j]=true;
                    }
        }
   // for (int i=1; i<=n; i++){
     //  for (int j=1; j<=rr; j++)
           // fo<<f[i][j]<<" "; fo<<endl;}
    fo<<f[n][m];
}
