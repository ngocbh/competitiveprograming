#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

int     t,q,n,a[35000],l[35000],r[35000],res,L,R;

int main()
{   fi>>t;
  for (int oo=1; oo<=t; oo++){
    memset(a,0,sizeof(a));
  memset(l,0,sizeof(l));
  memset(r,0,sizeof(r));
    scanf("%d",&q);
    while (q--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) {
            l[i] = i;
            while (a[l[i]-1] >= a[i]) l[i] = l[l[i]-1];
        }
        for (int i=n;i>=1;i--) {
            r[i] = i;
            while (a[r[i]+1] >= a[i]) r[i] = r[r[i]+1];
        }
        res = 0;
        for (int i=1;i<=n;i++)
            if (res < a[i]*(r[i]-l[i]+1)) {
                res = a[i]*(r[i]-l[i]+1);
                L = l[i];
                R = r[i];
            }
        printf("%d\n",res);
    }
  }

}
