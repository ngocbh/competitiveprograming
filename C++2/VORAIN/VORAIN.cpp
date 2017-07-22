#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#include <vector>
#define maxn 100000+10
#define maxk 1000000+10
using namespace std;
struct line
{
    int sa;
    int sb;
    int sc;
    int dc;
};
struct line2
{
    int xx1;
    int yy1;
    int xx2;
    int yy2;
};
int q,d[maxn],sl=0;
line a[maxn];
line2 b[maxn];
void new_line(int x1,int y1,int x2,int y2)
{
    int aa,bb,cc;
    aa=y2-y1;
    bb=x1-x2;
    cc=x2*y1-x1*y2;
    ++sl;
    b[sl].xx1=x1;
    b[sl].yy1=y1;
    b[sl].xx2=x2;
    b[sl].yy2=y2;
    a[sl].sa=aa;
    a[sl].sb=bb;
    a[sl].sc=cc;
    a[sl].dc=0;
}
void xuly1()
{   int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    new_line(x1,y1,x2,y2);
}
void xuly2()
{   int x;
    cin>>x;
    a[x].dc=1;
}
bool sameside(int x1,int y1,int x2,int y2,int aa,int bb,int cc)
{
    int d1,d2;
    d1=aa*x1+bb*y1+cc;
    d2=aa*x2+bb*y2+cc;
    if ( d1 <= 0 && d2 >= 0 ) return true;
    if ( d1 >= 0 && d2 <= 0 ) return true;
    return false;
}
void xuly3()
{   int x,y;
    int ok=false;
    cin>>x>>y;
    for (int i=1 ;i<=sl; i++)
        if ( !a[i].dc ){
            if ( sameside( x,y,x,0,a[i].sa,a[i].sb,a[i].sc ) && sameside( b[i].xx1,b[i].yy1,b[i].xx2,b[i].yy2,1,0,-x ) )
                { ok=true; break; }
        }
    if ( ok ) cout<<1<<endl;
    else cout<<0<<endl;
}
int main()
{   freopen("VORAIN.inp","r",stdin);
    freopen("VORAIN.out","w",stdout);
    cin>>q;
    for (int i=1; i<=q; i++) {
        int loai;
        cin>>loai;
        if ( loai==1 ) xuly1();
        if ( loai==2 ) xuly2();
        if ( loai==3 ) xuly3();
    }

}
