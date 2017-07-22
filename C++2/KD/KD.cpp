/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>
#define cin fi
#define cout fo
const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
ifstream fi("KD.inp");
ofstream fo("KD.out");

typedef long long LL;
typedef pair <int,int> ii;

int n;
string s, t;
int main()
{
    //freopen("KD.inp","r",stdin);
    //freopen("KD.out","w",stdout);

    cin >> s;
    cin >> t;

    while ( true ) {
        int x = s.find(t);
        if ( x == -1 ) break;
        s.erase(s.begin()+x,s.begin()+x+t.size());
    }

    cout << s;

}
