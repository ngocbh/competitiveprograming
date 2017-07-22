#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

const int N = 5678;

struct coin {
    int id, a, b;
};

bool used[N];
int id[N];

int main() {
//    freopen("input.txt", "r", stdin);
 //   std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<coin> cash(n);
    std::vector<int> vals;
    for (int i = 0; i < n; ++i) {
        cash[i].id = i;
        std::cin >> cash[i].a;
        vals.push_back(cash[i].a);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> cash[i].b;
    }
    std::sort(vals.begin(), vals.end());
    for (auto& z : cash) {
        z.a = std::lower_bound(vals.begin(), vals.end(), z.a) - vals.begin();
        id[z.a] = z.id + 1;
    }
    std::sort(cash.begin(), cash.end(), [] (const coin& x, const coin& y) { return x.b > y.b; } );
    int ans = 0;
    for (auto z : cash) {
        int diff = 0;
        for (int i = vals.size() - 1; i > z.a; --i) {
            if (used[i]) {
                --diff;
            } else {
                ++diff;
            }
        }
        if (diff > 0) {
            --diff;
            bool ok = true;
            for (int i = z.a - 1; i >= 0; --i) {
                if (used[i]) {
                    --diff;
                } else {
                    ++diff;
                }
                if (diff < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                used[z.a] = true;
                ans += z.b;
            }
        }
    }
    std::cout << ans << '\n';
    for (int i = 0, j = 0, step = 0; step < n >> 1; ++step, ++i, ++j) {
        while (used[i]) ++i;
        while (!used[j]) ++j;
        std::cout << id[i] << ' ' << id[j] << '\n';
    }
}
