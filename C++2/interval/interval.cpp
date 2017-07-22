#include <bits/stdc++.h>

using namespace std;
ifstream fi("interval.inp");
ofstream fo("interval.out");
int n;
pair <int,int> a[100010],b[100010];
int main()
{ fi>>n;
int j1=1,j2=1;
  for (int i=1; i<=2*n; ++i)
  {  char c;
     int q;
    fi>>c>>q;
    if (c=='B') {a[j1].first=q;a[j1].second=i; ++j1;}
    else {b[j2].first=q;b[j2].second=i;++j2;}

  }
  int64_t dem=0;
  sort(a+1,a+n+1); sort(b+1,b+n+1);
  for (int i=1; i<=n; i++)
    dem=dem+abs(a[i].first-b[i].first);
 fo<<dem<<endl;
 for (int i=1; i<=n; i++)
     fo<<a[i].second<<" "<<b[i].second<<endl;
}
