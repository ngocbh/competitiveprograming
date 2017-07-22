#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;

int n, k;
int a[N];
long long suma, sumd, lsuma, lsumd;
vector <int> sa, sd;

int main()
{
        freopen("ROBOT.inp","r",stdin);
        freopen("ROBOT.out","w",stdout);

        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if ( a[i] > 0 ) sd.push_back(a[i]), sumd += a[i];
            else sa.push_back(a[i]), suma += a[i];
        }

        lsuma = suma;
        lsumd = sumd;

        sort(sd.begin(), sd.end(), greater<int>() );
        sort(sa.begin(), sa.end());

        int nsa = sa.size();
        int nsd = sd.size();
        for (int i = 0; i < min(k,nsa); i++)
            sumd -= sa[i], lsuma -= sa[i];

        for (int i = 0; i < min(k,nsd); i++)
            suma -= sd[i], lsumd -= sd[i];

        cout << max(sumd + lsuma,-(suma+lsumd) );
}
