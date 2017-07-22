#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 110;

char s[N][N];
int a[N][N];
int b[N][N];

int main() {
    freopen("D.inp", "r", stdin);
    //freopen("out", "w", stdout);
    //ios::sync_with_stdio(false);
   // cin.tie(nullptr);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; ++j)
            if (s[i][j] == 'W') {
                a[i][j] = 1;
            } else {
                a[i][j] = -1;
            }
    }
    int answer = 0;
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j) {
            if (a[i][j] != b[i][j]) {
                answer++;
                int d = b[i][j] - a[i][j];
                for (int ii = 1; ii <= i; ++ii)
                    for (int jj = 1; jj <= j; ++jj) {
                        b[ii][jj] -= d;
                    }
            }
        }
    printf("%d", answer);
}
