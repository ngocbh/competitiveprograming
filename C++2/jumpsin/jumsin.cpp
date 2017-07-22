#include <bits/stdc++.h>

using namespace std;
ifstream fi("jumpsin.inp");
ofstream fo("jumpsin.out");
int a[1010],f[1010],n,x,b,h,q,f1[1010];
string s;
int main()
{  fi>>x;
   fi>>s;
   n=s.length();
  // fo<<n;
   //return 0;
   b=n/3;
   h=n%3;
   for (int i=1; i<=n; i++) {f[i]=i;f1[i]=i;}
   q=0;
  // for (int i=1; i<=n; i++) fo<<f[i]<<" "; fo<<endl;
   //=====================
   x=x%(n-1);
  for (int l=1; l<=x; l++)
    {
    q=0;
    for (int i=1; i<=n; i++)
      { if (i%2==0) {f[n-q]=f1[i]; ++q;}
        else
         f[i-q]=f1[i];
      }

    for (int j=1; j<=n; j++) {f1[j]=f[j];} //fo<<endl;


    }
    memset(f1,0,sizeof(f1));
    for (int i=1; i<=n; i++)  f1[f[i]]=i;
     for (int i=1; i<=n; i++) fo<<s[f1[i]-1];


}
