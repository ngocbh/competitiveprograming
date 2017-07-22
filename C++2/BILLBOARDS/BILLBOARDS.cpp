#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <stack>
#define maxn 1000000+100
using namespace std;
int n,a[maxn],l[maxn],r[maxn],f[maxn],res=0;
void timl()
{   stack <int> s;
    s.push(0);
    for (int i=1; i<=n; i++) {
        while ( a[s.top()] >= a[i] ) s.pop();
        l[i]=s.top();
        s.push(i);
    }
}
void timr()
{   stack <int> s;
    s.push(n+1);
    for (int i=n; i>=1; i--) {
        while ( a[s.top()] >=a[i] ) s.pop();
        r[i]=s.top();
        s.push(i);
    }
}
int main()
{   freopen("BILLBOARDS.inp","r",stdin);
    freopen("BILLBOARDS.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    a[0]=a[n+1]=-1;
    timl();
    timr();
    for (int i=1; i<=n; i++) {
        int ress=0;
        ress=a[i]*(r[i]-l[i]-1);
        //cout<<a[i]<<" "<<r[i]<<" "<<l[i]<<endl;
        res=max(res,ress);
    }
    printf("%d",res);

}
