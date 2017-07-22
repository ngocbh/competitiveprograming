#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

typedef pair<int,int> ii;
#define X first
#define Y second

ii origin;
void operator -= (ii &A, ii B){ A.X-=B.X; A.Y-=B.Y; }
bool ccw(ii O, ii A, ii B){ A-=O, B-=O; return A.X*B.Y > A.Y*B.X; }
bool cmp(ii A, ii B){ return ccw(origin, A, B); }

int n,m;
ii a[12309];
double s=0,v=0;

main(){
    freopen("poly.inp","r",stdin);
    freopen("poly.out","w",stdout);
    int i, t;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    scanf("%d%d", &a[i].X, &a[i].Y);

    sort(a+1, a+n+1);
    origin = a[1];
    sort(a+2, a+n+1, cmp);
    a[0]=a[n]; a[n+1]=a[1];
    int j=1;
    for (i=1; i<=n+1; i++){ // a[1] and a[n+1] will be both added
        while (j>2 && !ccw(a[j-2], a[j-1], a[i])) j--;
        a[j++]=a[i];
    }
    n=j-2;
   // for (i=1; i<=n; i++) printf("%d %d\n", a[i].X, a[i].Y);
    a[n+1]=a[1];
    a[0]=a[n];
    for (int i=2; i<=n+1; i++)
        s=s + ( a[i].X - a[i-1].X ) * ( a[i].Y + a[i-1].Y );
        s=abs(s)/2;
    for (int i=2; i<=n+1; i++)
        v+= sqrt( pow(a[i].X - a[i-1].X,2) + pow( a[i].Y - a[i-1].Y ,2) );
    printf("%d %0.2f %0.2f" , n , v , s);
}
