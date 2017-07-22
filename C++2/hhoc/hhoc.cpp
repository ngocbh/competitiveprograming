

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int xa,xb,xc,xd,ya,yb,yc,yd;
void dtdt(int xa,int ya,int xb,int yb, int xc,int yc)
{
    if ( ((ya-yb)*(xc-xa) + (xb-xa)*(yc-ya) ) == 0 ) cout<<" Điểm C có nằm trên đường thẳng AB \n";
    else cout<<" Điểm C không nằm trên đường thẳng AB \n";
}
int ktphia( int xa,int ya,int xb,int yb, int xc,int yc )
{
    if (( (ya-yb)*(xc-xa) + (xb-xa)*(yc-ya) ) > 0 ) return 1;
    if (( (ya-yb)*(xc-xa) + (xb-xa)*(yc-ya) ) < 0 ) return -1;
    if (( (ya-yb)*(xc-xa) + (xb-xa)*(yc-ya) ) ==0 ) return 0;
}
void dtcdt( int xa,int ya,int xb,int yb, int xc,int yc, int xd, int yd )
{   int dem=0;
    if (ktphia( xa,ya,xb,yb,xc,yc ) + ktphia( xa,ya,xb,yb,xd,yd ) <=1 &&
        ktphia( xa,ya,xb,yb,xc,yc ) + ktphia( xa,ya,xb,yb,xd,yd ) >=-1 ) ++dem;
    if (ktphia( xc,yc,xd,yd,xa,ya ) + ktphia( xc,yc,xd,yd,xb,yb ) <=1 &&
        ktphia( xc,yc,xd,yd,xa,ya ) + ktphia( xc,yc,xd,yd,xb,yb ) >=-1 ) ++dem;
    if (dem==2) cout<<" Hai đoạn thẳng cắt nhau \n";
    else cout<<" Hai đoạn thẳng không cắt nhau \n ";
}
void kct1ddt( int xa,int ya,int xb,int yb, int xc,int yc )
{   float dd=0;
    dd=( (ya-yb)*xc + ( xb-xa)*yc - ( ( xa*(ya-yb) + ya*( xb-xa ) ) ) ) / ( sqrt( (ya-yb)*(ya-yb) + (xb-xa)*(xb-xa) ) ) ;
    cout<<" Khoảng cách từ C đến đường thẳng AB là :"<<dd<<endl;
}
void ktphiaa(int xa,int ya,int xb,int yb,int xc,int yc)
{
    if (ktphia(xa,ya,xb,yb,xc,yc) ==1 ) cout<<" Điểm C nằm bên trên AB\n";
    if (ktphia(xa,ya,xb,yb,xc,yc) ==0 ) cout<<" Điểm C nằm trên AB\n";
    if (ktphia(xa,ya,xb,yb,xc,yc) ==-1 ) cout<<" Điểm C nằm bên dưới AB\n";
}
int main()
{
    freopen("hhoc.inp","r",stdin);
    freopen("hhoc.out","w",stdout);
    cin>>xa>>ya;
    cin>>xb>>yb;
    cin>>xc>>yc;
    cin>>xd>>yd;
    dtdt(xa,ya,xb,yb,xc,yc);
    ktphiaa(xa,ya,xb,yb,xc,yc);
    dtcdt(xa,ya,xb,yb,xc,yc,xd,xd);
    kct1ddt(xa,ya,xb,yb,xc,yc);
}
