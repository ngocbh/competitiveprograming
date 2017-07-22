#include <bits/stdc++.h>

using namespace std;

const long N = 1000000 + 10;

int n;
char a[N];
stack <char> s;

bool dong(char c)
{
    if ( c == '>' || c == '}' || c == ']' || c == ')' ) return true;
    return false;
}

bool check(char d,char c)
{
    if (c == '<' && d == '>' ) return false;
    if (c == '{' && d == '}' ) return false;
    if (c == '[' && d == ']' ) return false;
    if (c == '(' && d == ')' ) return false;
    return true;
}

int main()
{
        //freopen("C.inp","r",stdin);
        scanf("%s", a+1);
        n = strlen(a+1);

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if ( s.empty() && dong(a[i] ) ) {
                cout << "Impossible";
                return 0;
            }
            if ( !dong(a[i]) )
                s.push(a[i]);
            else {
                if ( check(a[i],s.top()) ) ++ans;
                s.pop();
            }
        }
        if ( !s.empty() ) cout << "Impossible" ;
        else
        cout << ans;
}
