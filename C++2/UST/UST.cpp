#include <bits/stdc++.h>

using namespace std;

const long N = 100 + 10;
typedef long long LL;
typedef pair <LL,int> ii;
struct data
{
    LL val;
    int cs;
    int k[N];
};

struct compare
{
    bool operator () ( const data A, const data B)
    {
        return A.val > B.val;
    }
};
int n;
int p[N], k[N];
ii x[4];
LL res[4];



int main()
{
    freopen("UST.inp","r",stdin);
    freopen("UST.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i] >> k[i];

    for (int i = 1; i <= 3; i++)
    {
        cin >> x[i].first; x[i].second = i;
    }

    sort(x+1,x+3+1);
    priority_queue <data,vector<data>,compare > qu;

    for (int i = 1; i <= n; i++) {
        data A;
        A.val = p[i];
        A.cs = i;
        for (int j = 1; j <= n; j++) if ( i != j ) A.k[j] = k[j]; else A.k[j] = k[j] - 1;
        qu.push(A);
    }

    for (int j = 1; j <= 3; j++)
            if ( x[j].first == 1 ) {
                res[x[j].second] = 1;
            }

    for (int i = 2; i <= x[3].first; i++)
    {
        data A = qu.top();
        data B;
        qu.pop();

        for (int j = A.cs; j <= n; j++)
            if ( A.k[j] ) {
                B = A;
                B.val = A.val * p[j];
                B.k[j] = A.k[j] - 1;
                B.cs = j;
                qu.push(B);
            }

        for (int j = 1; j <= 3; j++)
            if ( x[j].first == i ) {
                res[x[j].second] = A.val;
            }
    }

    for (int i = 1; i <= 3; i++) cout << res[i] << endl;
}
