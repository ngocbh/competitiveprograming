#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef pair<int,int> ii;
int n, MAX, t, a[N];
double S[N], R[N];
int gcd(int a,int b)
{
    int tg;
    while ( b != 0 ) {
        tg = a % b;
        a = b;
        b = tg;
    }
    return a;
}
int main()
{   //freopen("VMSUM2.inp","r",stdin);
    priority_queue <ii,vector<ii>,greater<ii> > qu;
    while ( scanf("%d", &n) == 1 ) {
            a[++t] = n;
            MAX = max(MAX,n);
    }
    for (int i = 2; i <= MAX; i++) {
            R[i] = R[i-1];
            for (int j = 1; j <= i; j++) {
                    if ( gcd(i,j) == 1 ) {
                            R[i] += (float) 1 / (i*j);
                            qu.push(ii( i+j , i*j ));
                    }
            }
            while ( true ) {
                    int u, v;
                    u = qu.top().first;
                    v = qu.top().second;
                    if ( u < i ) {
                            qu.pop();
                            R[i] -= (float) 1 / v;
                    }
                    else break;
            }
            S[i] = S[i-1] + R[i];
    }
    for (int i = 1; i <= t; i++) {
            cout.precision(10 + log10(S[a[i]]));
            cout << S[a[i]] << endl;
    }


}

