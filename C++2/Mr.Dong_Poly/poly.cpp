/// cach 1;
    /// tim giao cua doan va doan .
    /// kiem tra 1 diem nam trong da giac
    /// loai bo lap . ( exp: co 2 dinh? trung nhau thi coi la 1 )
    /// tinh so diem nam trong da giac
    /// cach 2;
    /// tinh AB;
    ///  void tinh (a,b:point)
    ///       if ( kc(a,b) < eps ) return;
    ///    if (trong(a) && trong(b) ) {
    ///   r=r+kc(a,b);
    ///    return;
    ///        }
    ///        cx=(a.x+b*y)/2 ; cy=(ay+bx)/2;
    ///        tinh(a,c);
    ///        tinh(c,b);
    ///    } */
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#define eps 0.00000001
#define maxn 100+10
#define x first
#define y second

using namespace std;
typedef pair <float,float> ii;
int n,m;
float area=0,res=0;
ii p[maxn],a1,a2;
float areatamgiac(ii aa,ii bb,ii cc)
{
    float cs=0;
    cs=( bb.x-aa.x )*( bb.y+aa.y ) + ( cc.x-bb.x )*( cc.y+bb.y ) + ( aa.x-cc.x )*(aa.y+cc.y) ;
    return abs(cs);
}
float kc( ii a,ii b )
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
bool trong(ii x)
{   float cc=0;
    for (int i=1; i<=n; i++)
        cc+=areatamgiac(x,p[i],p[i+1]);

    if ( abs( cc - area ) < eps ) return true;
    else return false;
}
void tinh(ii a,ii b)
{
    if ( kc(a,b) < eps ) return;
    if ( !trong(a) && !trong(b) ) return;
    if ( trong(a) && trong(b) ) {
        res+=kc(a,b);
        return;
    }
    ii c;
    c.x=( a.x + b.x )/2.0; c.y=( a.y + b.y )/2.0;
    tinh(a,c);
    tinh(c,b);

}
int main()
{   freopen("poly.inp","r",stdin);
    freopen("poly.out","w",stdout);
        cin>>n;
        for (int i=1; i<=n; i++) cin>>p[i].x>>p[i].y;
        cin>>a1.x>>a1.y>>a2.x>>a2.y;;
        p[n+1].x=p[1].x; p[n+1].y=p[1].y;
        ///==================tinhdientichdagiac
        for (int i=1; i<=n; i++) area+=( p[i+1].x - p[i].x )*( p[i+1].y + p[i].y );
        area=abs(area);
        ///==============
   // cout<<trong(c)<<" "<<trong(c1)<<endl;
   cout<<area;
    tinh(a1,a2);
    printf("%0.0f",res*100 );
}
