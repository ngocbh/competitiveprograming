#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> a;
int f[25005];
int main()
{ scanf("%d",&n);
  a.push_back(0);
  for (int i=1; i<=n-1; ++i){
    int x;
    scanf("%d", &x);
    a.push_back(x);
    } f[1]=0;int dem;
      f[2]=a[1];
      f[3]=a[1]+a[2];
  for (int i=4; i<=n; ++i){
     f[i]=min(f[i-1],f[i-2])+a[i-1];
  }
  printf("%d",f[n]);
}
