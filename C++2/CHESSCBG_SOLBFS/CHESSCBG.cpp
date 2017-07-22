#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;

struct data{
    char a[5][5];
};

typedef pair <data,int> ii;


int n;
int ca[N];

data a, b;

void get(data a)
{
    int res = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            ans = ans * 2 + a.a[i][j];
}

int main()
{   freopen("CHESSCBG.inp","r",stdin);

    for (int i = 1; i <= 4; i++) {
        scanf("%s", a.a[i]+1);
    }
    for (int i = 1; i <= 4; i++) {
        scanf("%s", b.a[i]+1);
    }

    ///BFS();
    queue <ii> qu;
    qu.push(ii(a,0));
    while ( !qu.empty() ) {
        int x,u;
        x = qu.front().first;
        u = qu.front().second;
        qu.pop();
        if ( x == get(b) ) {
            cout << u;
            return 0;
        }
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
        {
            up(i,j,x,u+1);
            down(i,j,x,u+1);
            left(i,j,x,u+1);
            right(i,j,x,u+1);
        }

    }

}
