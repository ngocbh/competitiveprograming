#include <bits/stdc++.h>
#define x first
#define y second
const long N = 60000 + 10;
using namespace std;
typedef long long LL;
typedef pair <LL,LL> point;

char s[N];
point ca[N];
char cs[N];
LL gcd(LL a,LL b)
{
    a = abs(a);
    b = abs(b);
    if ( a == 0 || b == 0 ) return 1;
    LL t = 1;
    while ( t != 0 ) {
            t = a % b;
            if ( t > 0 ) {
                    a = b;
                    b = t;
            }
    }
    return b;
}
point add(point a, point b)
{
        point c;
        c.x = a.x*b.y + b.x*a.y;
        c.y = a.y*b.y;
        LL g;
        g = gcd(c.x,c.y);
        c.x /= g;
        c.y /= g;
        if ( a.x == 0 && a.y == 0 ) return b;
        if ( b.x == 0 && b.y == 0 ) return a;
        return c;
}
point mul(point a,point b)
{
        point c;
        c.x = a.x*b.x;
        c.y = a.y*b.y;
        int g;
        g = gcd(c.x,c.y);
        c.x /= g;
        c.y /= g;
        if ( a.x == 0 && a.y == 0 ) return a;
        if ( b.x == 0 && b.y == 0 ) return b;
        return c;
}
int xss(char c)
{
    return (int) ( c - '0' );
}
int main()
{       freopen("BAI1.inp","r",stdin);
        freopen("BAI1.out","w",stdout);
        scanf("%s", s+1 );
        int n;
        n = strlen(s+1);
        s[0] = '+'; s[n+1] = '+';
        LL tuso = 0, mauso = 0;
        LL sl = 0;
        for (int i = 0; i <= n+1; i++)    {
                if ( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == ':' ) {
                        ca[sl].y = mauso;
                        cs[sl] = s[i];
                        tuso = 0;
                        mauso = -1;
                        continue;
                }
                if ( s[i] == '/' ) {
                        mauso = 0;
                        ca[++sl].x = tuso;
                        continue;
                }
                if ( mauso == -1 ) {
                        tuso = tuso*10 + xss(s[i]);
                        continue;
                }
                mauso = mauso*10 + xss(s[i]);
        }
        point tc , sc ;
        tc = make_pair(0,0);
        sc = make_pair(0,0);
        cs[sl] = '+';
        for (int i = 0; i <= sl; i++) {
                    if ( cs[i] == '+' ) {
                            tc = add(tc,sc);
                            sc = make_pair(ca[i+1].x,ca[i+1].y);
                    }
                    if ( cs[i] == '-' ) {
                            tc = add(tc,sc);
                            sc = make_pair(-ca[i+1].x,ca[i+1].y);
                    }
                    if ( cs[i] == '*' ) {
                            sc = mul(sc,ca[i+1]);
                    }
                    if ( cs[i] == ':' ) {
                            sc = mul(sc,make_pair(ca[i+1].y,ca[i+1].x));
                    }
        }
        cout << tc.x << "/" << tc.y;

}
