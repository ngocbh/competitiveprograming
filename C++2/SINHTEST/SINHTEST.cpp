#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("SINHTEST.inp","w",stdout);
	srand(time(NULL));
	int n = rand() % 10 + 2;
	int k = rand() % n*n/2 ;
	cout << n << " " << k << endl;
	int a[20][20];
	for (int i = 1; i <= k; i++) {
		while ( true ) {
			int x = rand() % n + 1;
			int y = rand() % n + 1;
			if ( a[x][y] || (x==1&&y==1) || (x==1&&y==n ) ) continue;
			cout << x << " " << y << endl;
			a[x][y] = 1;
			break;
		}
	}
	return 0;
}
