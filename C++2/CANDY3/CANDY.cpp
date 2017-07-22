#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

const int N = 1010;
const int MAX = 10010;

bool used[N];
int a[N];
int dp[N * MAX / 2];

int main() {
    freopen("CANDY.inp", "r", stdin);
    freopen("CANDY.out", "w", stdout);
    int n = 0;
    int sum = 0;
    while (~scanf("%d", a + ++n)) {
        sum += a[n];
    }
    --n;
    std::sort(a + 1, a + n + 1);
    int half = sum / 2;
    dp[0] = -1;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = cur; j >= 0; --j)
            if (dp[j] && j + a[i] <= half) {
                dp[j + a[i]] = i;
            }
        cur = std::min(half, cur + a[i]);
    }
    int best = 0;
    for (int i = half; i >= 1 && !best; --i) {
        if (dp[i]) {
            best = i;
        }
    }
    printf("%d %d %d\n",sum - best, best, sum - best - best);
    for (int i = best; i; i = i - a[dp[i]]) {
        printf("%d ", a[dp[i]]);
        used[dp[i]] = true;
    }
    putchar('\n');
    for (int i = 1; i <= n; ++i)
        if (!used[i])
            printf("%d ", a[i]);
}
