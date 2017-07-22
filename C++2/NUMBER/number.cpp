#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#include <string>
#define maxn 10000000+100
using namespace std;
int n;
bool ok;
char s[10][maxn];
char nsx(int x)
{
    return (char) (x+48);
}
int xsn(char c)
{
    return (int) ( c-'0' );
}
int main()
{   freopen("number.inp","r",stdin);
    freopen("number.out","w",stdout);
    int res=0;
    while ( cin>>n != 0 ){

    ok=false; int best=n+1;
    for (int oo=1; oo<=9; oo++){
             int h=0;
        for (int i=1; i<=best-1; i++){
                h=h*10+oo;
                s[oo][i]=nsx(h/n);
                h=h%n;
                if ( h == 0 ) { best=i; res=oo; ok = true;  break; }
        }
    }
    if ( !ok ) printf("-1\n");
    else { int nho=1;
    while ( s[res][nho]=='0' ) ++nho;
    for (int i=nho; i<=best; i++) printf("%c",s[res][i]);printf("\n");
    }
   }
}
