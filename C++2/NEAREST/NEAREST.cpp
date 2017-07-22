#include <iostream>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <algorithm>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
typedef pair <double,double> ii;
double ans = 1e17;
struct point{
    double x,y;
};
int n;
point a[N],Ply[N], Pry[N], ar[N], al[N], ship[N], root;

inline bool cmp(const point& A,const point& B)
{
    return ( A.x < B.x || ( A.x == B.x && A.y < B.y ) );
}

inline double sqr(double x)
{
    return x*x;
}

inline bool compare_y(const point& A,const point& B)
{
    return A.y < B.y;
}

inline double kc(const point& A,const point& B)
{
    return sqrt((B.x-A.x)*(B.x-A.x) + ( B.y - A.y ) * (B.y - A.y));
}

double bruteforce(int l,int r, int n )
{
    double d = 100000000 * 2 + 7;
        for (int i = l; i <= r; i++)
            for (int j = i+1; j <= r; j++) {
                if ( kc(a[i],a[j]) < d ) d = kc(a[i],a[j]);
                //if ( d == kc(a[i],a[j]) && abs( d - 263452.485 ) < 0.01 ) cout << i << " " << j << endl;
            }

    sort(a+l,a+n+l,compare_y);
    return d;
}

void merge_sort(int l,int r,int n)
{
    int mid = (l+r) / 2;
    for (int i = l; i <= r; i++) {
            if ( i <= mid ) Ply[i-l+1] = a[i];
            else Pry[i-mid] = a[i];
    }
    int ci = 1, cj = 1;
    for (int i = l; i <= r; i++) {
            if ( ci > mid-l+1 ) { a[i] = Pry[cj++]; continue; }
            if ( cj > r - mid ) { a[i] = Ply[ci++]; continue; }
            if ( Ply[ci].y < Pry[cj].y ) a[i] = Ply[ci++];
            else a[i] = Pry[cj++];
    }
}

double closest(int l,int r, int n)
{
        if ( l == r ) return ans;
        int mid = (l + r) / 2;
        point pointmid = a[mid];

        double dl,dr,d;
        dl = closest(l,mid,mid-l+1);
        dr = closest(mid+1,r,r-mid);

        d = min(dl,dr);
        ans = min( ans , d );
        int ship_size = 0;
        merge_sort(l,r,n);

        for (int i = l; i <= r; i++) {
            if ( abs(a[i].x - pointmid.x ) < ans )
                ship[++ship_size] = a[i];
        }
        for (int i = 1; i <= ship_size; i++)
            for (int j = i+1; j <= ship_size && ( ship[j].y - ship[i].y < d ) ; j++)
                d = min(d , kc(ship[i] , ship[j]));
        ans = min( ans , d );
        return d;
}

void sol_100()
{
    sort(a+1,a+n+1,cmp);
    double res;
    ans = closest(1,n,n);
    printf("%0.3lf", ans);
}

int main()
{
    //freopen("NEAREST.inp","r",stdin);
    //freopen("NEAREST.out","w",stdout);

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf%lf" , &a[i].x, &a[i].y);
    sol_100();

}

