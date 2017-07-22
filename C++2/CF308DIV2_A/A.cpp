#include <bits/stdc++.h>

const long N = 100+10;
using namespace std;
int n,a[N][N],res = 0;
int main()
{   //freopen("A.inp","r",stdin);
    scanf("%d", &n);
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    for (int i = 1; i <= n; i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
                ++a[i][j];
    }
    for (int i = 1; i <= 100; i++)
        //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
            for (int j = 1; j <= 100; j++)
                res += a[i][j];
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    cout<<res;

}
