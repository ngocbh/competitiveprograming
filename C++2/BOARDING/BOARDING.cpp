#include <bits/stdc++.h>
    #define cin fi
    #define cout fo

const long N = 100000 + 10;
const long long oo = 1000000000 + 7;

using namespace std;
    ifstream fi("BOARDING.inp");
    ofstream fo("BOARDING.out");

typedef long long LL;
typedef pair <LL,LL> ii;
typedef pair <ii,ii> iii;

struct data{
    LL ver, cos, tim;
};
LL n, m, P;
LL p[N];
LL d[N][2];
LL ca[N];

vector <data> a[N];
struct compare{
    bool operator() (data A, data B)
    {
        return A.cos < B.cos;
    }
};
void dijkstra()
{
    for (int i = 1; i <= n; i++) d[i][0] = d[i][1] = oo*oo;
    memset(ca,true,sizeof ca);

    priority_queue <iii, vector<iii>, greater<iii> > qu;
    data A;
    A.ver = 1, A.cos = 0, A.tim = 0;
    qu.push(iii(ii(0,0) , ii(1,0)));
    ca[1] = false;
    d[1][0] = d[1][1] = 0;
    data B;
    LL u , c , du, time, dc ;

    while ( !qu.empty() ) {
        u = qu.top().second.first;
        du = qu.top().first.first;
        dc = qu.top().first.second;
        time = qu.top().second.second;
        qu.pop();
        //cout << u << " " << du << " " << time << endl;

        for (int i = 0; i < a[u].size(); i++) {
            LL v = a[u][i].ver;
            c = a[u][i].cos;
            LL ti = a[u][i].tim;
            if ( time % 2 == ti ) {
                if ( d[v][(time+1)%2] > du + c ) {
                    d[v][(time+1)%2] = du + c;
                    qu.push(iii(ii(d[v][(time+1)%2],(time+1)%2),ii(v,(time+1)%2)));
                    //cout << d[v] << " " << v << " " << time + 1 << endl;
                }
            }
            else
            {
                if ( d[v][time] > du + c + p[u] ) {
                    d[v][time] = du + c + p[u];
                    qu.push(iii(ii(d[v][time],time),ii(v,time)));
                    //cout << d[v] << " " << v << " " << time + 2 << endl;
                }
            }
        }
    }
}

int main()
{   //freopen("BOARDING.inp","r",stdin);
    cin >> n >> m >> P;
    for (int i = 1; i <= n; i++) p[i] = P;

    data A;
    LL u, v, c;
    for (int i = 1; i <= m; i++) {

        cin >> u >> v >> c;
        if ( u == v ) {
            //p[u] = min(p[u],c);
            //continue;
        }

        A.ver = v, A.cos = c, A.tim = 0;
        a[u].push_back(A);
        A.ver = u, A.tim = 1;
        a[v].push_back(A);
    }

    dijkstra();
    if ( d[n][0] == oo*oo && d[n][1] == oo*oo ) {
        cout << -1;
        return 0;
    }

    cout << min(d[n][1],d[n][0]);
}
