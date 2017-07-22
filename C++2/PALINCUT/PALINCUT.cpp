/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 10000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;

int n, t, q, k;
int L[N], C[N], a[N], ca[N];

char s[N], s1[N];

void init()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 0;;j++){
            if ( i-j == 0 || i+j > n || s[i-j] != s[i+j]) {
                    L[i] = j - 1;
                    break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if ( s[i] != s[i+1] ) continue;
        for (int j = 0;;j++)
            if ( i-j == 0 || i+1+j > n || s[i-j] != s[i+1+j] ) {
                    C[i] = j;
                    break;
            }
    }

}

bool solve()
{
        LL sum = 0;
        for (int i = 1; i <= k; i++)
            sum |= (1<<i);
        queue <ii> qu;
        qu.push(ii(0,0));

        while ( !qu.empty() ) {
            int u = qu.front().first;
            LL du = qu.front().second;
            qu.pop();
            if ( du == sum )
                return true;


            for (int i = 1; i <= k; i++)
                if ( ((du>>i)&1) == 0 ) {
                    if ( a[i] % 2 == 1 ) {
                        for (int j = u+1; j <= n; j++) {
                            if ( L[j] >= a[i] / 2 && j - L[j] > u ) {
                                qu.push(ii(j+L[j],du|(1<<i)));
                                break;
                            }
                        }
                    }
                    else {
                        for (int j = u+1; j <= n; j++) {
                            if ( C[j] >= a[i] / 2 && j - C[j] >= u ) {
                                qu.push(ii(j+C[j],du|(1<<i)));
                                break;
                            }
                        }
                    }
                }
        }

    return false;
}

bool cmp(int a,int b)
{
    return a > b;
}

bool solve1()
{
    LL sum = 0, du = 0;
    memset(ca,true,sizeof ca);
    sort(a+1,a+k+1,cmp);

    for (int i = 1; i <= k; i++) sum |= (1<<i);

    for (int j = 1; j <= k; j++) {
        if ( a[j] % 2 == 1 ) {
        for (int i = 1; i <= n; i++)
            if ( ((du>>j)&1) == 0 && ca[i] && L[i] >= a[j]/2 && a[j] % 2 == 1 ) {
                bool ok = true;
                for (int o = i-a[j]/2; o <= i+a[j]/2; o++){
                        if (ca[o] == false ) {
                            ok = false;
                            break;
                        }
                    }
                if ( !ok ) continue;
                for (int o = i-a[j]/2; o <= i+a[j]/2; o++)
                        ca[o] = false;
                du |= (1<<j);
            }
        }
        else {

        for (int i = 1; i <= n; i++)
            if ( ((du>>j)&1) == 0 && ca[i] && C[i] >= a[j]/2 && a[j] % 2 == 0 ) {
                bool ok = true;
                for (int o = i-a[j]/2+1; o <= i+a[j]/2; o++){
                    if ( ca[o] == false ) {
                        ok = false;
                        break;
                    }
                }
                if ( !ok ) continue;
                for (int o = i-a[j]/2+1; o <= i+a[j]/2; o++)
                    ca[o] = false;
                du |= (1<<j);
            }
        }
    }

    if ( du == sum ) return true;
    else return false;
}

int main()
{
    freopen("PALINCUT.inp","r",stdin);
    freopen("PALINCUT.out","w",stdout);


    scanf("%s", s+1) ;
    n = strlen(s+1) ;

    init();

    cin >> t;

    while ( t-- ) {

        cin >> k;
        for (int i = 1; i <= k; i++) cin >> a[i];

        if ( n > 1000 && k != 1 ) {
            if ( solve1() ) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;

        if ( solve() ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
