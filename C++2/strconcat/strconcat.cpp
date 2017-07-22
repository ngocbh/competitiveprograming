#include <bits/stdc++.h>

using namespace std;
ifstream fi("strconcat.inp");
ofstream fo("strconcat.out");
const long maxn=1000000+100;
const long base=1000000000+7;
int n,m,k,kq[maxn],h;
string s;
pair <int,int> a[maxn],b[maxn];
int main()
{ fi>>n>>m;
  fi>>s;
  h=50017; k=n/m;
  for (int i=0; i<=m-1; i++){
     int64_t t=0;
     for (int j=0;j<=k-1;j++) t=(t*h+s[i*k+j])%base;
    // fo<<t<<endl;
     a[i].first=t;
     a[i].second=i+1;
  }
  for (int i=1; i<=m; i++){
     int64_t t=0;
     fi>>s;
     //for (int j=0; j<=k; j++) fo<<s[j];
     for (int j=0; j<=k-1; j++) t=(t*h+s[j])%base;
   //  fo<<t<<endl;
     b[i].first=t;
     b[i].second=i;
  }
  ///======================
  sort(a,a+m+1); sort(b,b+m+1);
 // for (int i=1; i<=m; i++) fo<<a[i].first<<" "<<a[i].second<<endl;
  for (int i=1; i<=m; i++)
    kq[a[i].second]=b[i].second;
  for (int i=1; i<=m; i++) fo<<kq[i]<<" ";
}
