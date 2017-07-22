#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
typedef pair <double,double> ii;
struct point{
    int x,y,val;
};
int n;
point a[N], root;
double kc(point A,point B)
{
    return (double) (sqrt((double)(B.x-A.x)*(B.x-A.x) + (double)( B.y - A.y ) * (B.y - A.y)));
}

bool cmp_greed(point A,point B)
{
    return A.val < B.val;
}
void sol_greed()
{
    sort(a+1,a+n+1,cmp_greed);
    double ans = 100000000*2+7;
   for (int i = 1; i <= n; i++) {
        for (int j = i-10; j <= i+10;j++)
            if ( i != j && j >= 1 && j <= n ) {
                ans = min(ans,kc(a[i],a[j]));
                //if ( ans == kc(a[i],a[j]) ) cout << a[i].x << " " << a[i].y << endl << a[j].x << " " << a[j].y << endl;
            }
    }
    printf("%0.3f\n", ans);
}
int main()
{
    //freopen("NEAREST.inp","r",stdin);
    //freopen("NEAREST.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    root = {5000000,10000007,0};
    cin >>  n;
    for (int i = 1; i <= n; i++) {  cin >> a[i].x >> a[i].y; a[i].val = kc(a[i],root);  }

    sol_greed();
}
