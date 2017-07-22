#include <bits/stdc++.h>

using namespace std;

const long N = 200003;
int dp[N];
int x;
int n;int ans = 0;
int asdasdasd = 1;
int asfdaf = 0;

int main() {


///NOOOOOOOOOOOOOOOOOOOO
///NOOOOOOOOOOOOOOOOOOOOO
cin >> n;
for (int i = 1; i <= n; ++i)
{
cin >> x;
dp[x] = dp[x - 1] + 1;
ans = max(ans, dp[x]);
}
//%JKJASASJIFAKSF
cout << n - ans;
}
