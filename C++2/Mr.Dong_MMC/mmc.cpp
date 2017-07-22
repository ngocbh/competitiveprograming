#include <bits/stdc++.h>

using namespace std;
ifstream fi("mmc.inp");
ofstream fo("mmc.out");
const long maxn=500+10;
int64_t  c[maxn],a[maxn][maxn],b[maxn][maxn],c1[maxn],c2[maxn],cc[maxn];
int n,t;


int main()
{  fi>>t;
  for (int oo=1; oo<=t; oo++){
    fi>>n;
    for (int i=1; i<=n; i++) {c[i]=rand()%10+1; }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) fi>>a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) fi>>b[i][j];
  ///==========================
    for (int i=1; i<=n; i++) c1[i]=0;
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++)
        {c1[i]+=a[i][j]*c[j]; }
 //        for (int i=1; i<=n; i++)  fo<<c1[i]<<" "; fo<<endl; fo<<"%"<<endl;
//======================
    for (int i=1; i<=n; i++) cc[i]=0;
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++)
       { cc[i]+=a[i][j]*c1[j]; }
    //   for (int i=1; i<=n; i++)  fo<<cc[i]<<" "; fo<<endl; fo<<"%"<<endl;
//======================
    for (int i=1; i<=n; i++) c1[i]=0;
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++)
        {c1[i]+=a[i][j]*cc[j];  }
///===
       //  for (int i=1; i<=n; i++)  fo<<c1[i]<<" "; fo<<endl; fo<<"%"<<endl;
///==
    for (int i=1; i<=n; i++) c2[i]=0;
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++)
        c2[i]+=b[i][j]*c[j];

        //for (int i=1; i<=n; i++){for (int j=1; j<=n; j++) fo<<a[i][j]<<" "; fo<<endl; }
   ///==
//for (int i=1; i<=n; i++)  fo<<c2[i]<<" "; fo<<endl; fo<<"%"<<endl;
  ///===========================
    int nho=0;
    for (int i=1; i<=n; i++)
        if (c1[i]!=c2[i]) nho=1;
    if (nho==0) fo<<"YES"<<endl;
    else fo<<"NO"<<endl;

  }
}
