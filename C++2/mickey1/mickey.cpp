#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define MAX_N 1000
#define MAX_NODEFINE  1000000

struct Node{
    int rightPosition;
    int leftPosition;
    int height;
};

Node platformData[ MAX_N + 10 ];//记录每个板的信息
int rightMinTime[ MAX_N + 10 ] ;//第i个板右边到地面的时间
int leftMinTime[ MAX_N + 10 ];

int t, N, X, Y, Max;
//大到小排序
int MyCompare( const void*  x, const void*  y ){
    Node * p1, *p2;
    p1 = ( Node* )x;
    p2 = ( Node* )y;
    return p2 -> height - p1 ->height;
}

int MinTime( int num ,bool bLeft){
    int i;
    int y = platformData[ num ].height;
    int x;
    if( bLeft )
        x = platformData[ num ].leftPosition;
    else
        x = platformData[ num ].rightPosition;

    //找到第一个在num下面的板
    for(  i = num + 1; i <= N; i++ ){
        if( platformData[ i ].rightPosition >= x &&  platformData[ i ].leftPosition <= x )
            break;
    }
    //如果找到这个板
    if( i <= N ){
        if ( y - platformData[ i ].height > Max )
            return MAX_NODEFINE;
    }
    else{ // 没有找到板
        if( y > Max )
            return MAX_NODEFINE;
        else
            return  y;

    }
    int leftTime = y - platformData[ i ].height + x - platformData[ i ].leftPosition;
    int rightTime = y -platformData[ i ].height + platformData[ i ].rightPosition - x;

    if( rightMinTime[ i ] == -1 )
        rightMinTime[ i ] = MinTime( i, false );
    if( leftMinTime[ i ] == -1 )
        leftMinTime[ i ] = MinTime( i, true );
    leftTime += leftMinTime[ i ];
    rightTime += rightMinTime[ i ];
    if( leftTime < rightTime  )
        return leftTime;
    else
        return rightTime;
    return 0;

}
int main(int argc, const char * argv[])
{
    int tt;
    cin>>tt;
    while (tt--){
    cin >> t;
    while( t ){
        memset( rightMinTime, -1, sizeof( rightMinTime ) );
        memset( leftMinTime, -1, sizeof( leftMinTime ) );
        cin>> N >> X >> Y >> Max;
        platformData[ 0 ].leftPosition = X;
        platformData[ 0 ].rightPosition = X;
        platformData[ 0 ].height = Y;
        for( int i = 1; i <= N; i++ )
            cin >> platformData[ i ].leftPosition >> platformData[ i ].rightPosition >> platformData[ i ].height;
        qsort( platformData, N + 1,sizeof( Node ), MyCompare);
        cout << MinTime( 0, true ) << endl;
        t--;
    }}
    return 0;


}
