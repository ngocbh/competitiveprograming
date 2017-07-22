#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#include <algorithm>
#define maxn 100+10
#define eps 1e-5
#define x first
#define y second
using namespace std;
typedef pair<float,float> point;
int n;
point p[maxn],a1,a2;
float areaG=0,res=0;
float kc(point a,point b)
{
    return (float) sqrt( (a.x-b.x)*(a.x-b.x) + ( a.y-b.y)*(a.y-b.y) ) ;
}
float areatg( point a,point b,point c )
{   float cc;
  cc=   ( float )( ( a.x-b.x )*( a.y+b.y ) + ( b.x-c.x )*( b.y+c.y ) + ( c.x-a.x )*(c.y+a.y) );
    return abs(cc);
}
bool trong(point A)
{   float c=0;
    for ( int i=1; i<=n; i++ )
       { c+=areatg(A,p[i],p[i+1]);
         //cout<<areatg(A,p[i],p[i+1])<<endl;
       }
    //cout<<c<<endl;
    if ( c - areaG < eps ) return true;
    else return false;
}
void caculate(point a,point b)
{   if ( kc(a,b) < eps ) return;
    if ( trong(a) && trong(b) ) {
        res+=kc(a,b);
        return;
    }
    point c;
    c.x=(a.x+b.x)/2; c.y=(a.y+b.y)/2;
    caculate(a,c);
    caculate(c,b);
}
int main()
{   freopen("POLY.inp","r",stdin);
    freopen("POLY.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>p[i].x>>p[i].y;
    cin>>a1.x>>a1.y>>a2.x>>a2.y;
    p[n+1]=p[1];
    for (int i=1; i<=n; i++) areaG+=( p[i].x - p[i+1].x )*( p[i].y + p[i+1].y );
    areaG=abs(areaG);
    caculate(a1,a2);
    //cout<<res<<endl;
    res= res*100;
    res=(int) res;
    cout<<res;
}
