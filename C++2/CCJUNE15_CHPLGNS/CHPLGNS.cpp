#include <bits/stdc++.h>
#define x first
#define y second
const long N = 2*100000+10;
using namespace std;
typedef pair<int64_t,int64_t> point;
long long m,n,cs[N],t,res[N];
double a[N];
point p[N];
double abs1(double cc)
{
    if ( cc > 0 ) return cc;
    else return -cc;
}
double calculate_area()
{   double c=0;

    for (int i = 0; i <= m-1; i++) {
        c +=  p[i].x * p[i+1].y - p[i+1].x * p[i].y;
          //c += (p[i].x - p[i+1].x) * (p[i].y + p[i+1].y);
      // cout<<p[i].x <<" "<<p[i].y<<" "<<p[i+1].x <<" "<<p[i+1].y<<endl;
      //  cout<<c<<endl;
    }
    return abs(c/2);
}
bool cmp(int i,int j)
{
    return a[i] < a[j];
}
int main()
{   //freopen("in.inp","r",stdin);
    scanf("%d", &t);
    while ( t-- ) {
    scanf("%d", &n);
    for (int o=1; o<=n; o++) {
        scanf("%d" , &m);
        for (int i = 1; i <= m; i++) {
            scanf("%lld %lld" , &p[i].x ,&p[i].y);
        }

        p[0] = p[m];
        //for (int i = 0; i <= m; i++) cout<<p[i].x <<" "<<p[i].y<<" ";
        a[o] = calculate_area();
        //cout<<a[o]<<endl;
    }
    for (int i=1 ; i <= n; i++) cs[i] = i;
    sort(cs+1,cs+n+1,cmp);
    for (int i = 1 ; i <= n; i++) res[cs[i]] = i;
    for (int i=1; i<=n ;i++) printf("%d ", res[i]-1);
    printf("\n");
    }
}

