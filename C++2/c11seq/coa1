#include <iostream>
#define max_n 100000
using namespace std;

void swap(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void quickSort(long long a[], int idx[], int left, int right) {
     int i = left, j = right;
     long long pivot = a[(left + right) / 2];

     /* partition */
    while (i <= j) {
          while (a[i] < pivot)
                i++;
          while (a[j] > pivot)
                j--;

          if (i <= j) {
             swap(a[i], a[j]);
             swap(idx[i], idx[j]);
             i++;
             j--;
          }
    };

    /* recursion */
    if (left < j)
       quickSort(a, idx, left, j);

    if (i < right)
       quickSort(a, idx, i, right);
}

void inp(int a[], long long sum[], long long sum_l[], long long sum_r[], int &n, int &l, int &r) {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) {
			sum[i] = a[i];
			sum_l[i] = a[i] + l - 1;
			sum_r[i] = a[i] + r;
		}
		else {
			sum[i] = sum[i - 1] + a[i];
			sum_l[i] = sum_l[i - 1] + a[i];
			sum_r[i] = sum_r[i - 1] + a[i];
		}
    }
}

void update(int x, long long t[]) {
	while (x <= 3 * max_n + 2) {////AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA! WHY??????
		t[x] += 1LL;
		x += x & (-x);
	}
}

long long get(int x, long long t[]) {
	long long sum = 0LL;
	while (x > 0) {
		sum += t[x];
		x -= x & (-x);
	}
	return sum;
}

void solve(int b[], int b_l[], int b_r[], int n, long long t[]) {
	long long kq = 0LL, x, y;
	for (int i = n; i >= 1; i--) {
		update(b[i], t);
		x = get(b_r[i - 1], t);
		y = get(b_l[i - 1], t);
		kq += x - y;
	}

	cout << kq;
}

void roiRacHoa(int b[], int b_l[], int b_r[], int b_together[], long long sum_together[], int idx[], int n) {
	int i, j;
	b_together[idx[1]] = 1;
	for (i = 2; i <= 3 * n + 2; i++)
	    if (sum_together[i] == sum_together[i - 1])
			b_together[idx[i]] = b_together[idx[i - 1]];
		else
			b_together[idx[i]] = i;

	for (i = 1; i <= n; i++)
		b[i] = b_together[i];
	j = 0;
	for (i = n + 1; i <= 2 * n + 1; i++) {
		b_l[j] = b_together[i];
		j++;
	}
	j = 0;
	for (i = 2 * n + 2; i <= 3 * n + 2; i++) {
		b_r[j] = b_together[i];
		j++;
	}
}

int main() {
    int i, j, n, l, r;
	int *a = new int [max_n + 1];
	long long *sum = new long long [max_n + 1];
	long long *sum_l = new long long [max_n + 1];
	long long *sum_r = new long long [max_n + 1];
	long long *sum_together = new long long [3 * max_n + 3];
	int *b = new int [max_n + 1];
	int *b_l = new int [max_n + 1];
	int *b_r = new int [max_n + 1];
	int *b_together = new int [3 * max_n + 3];
	int *idx = new int [3 * max_n + 3];
	long long *t = new long long [3 * max_n + 3];
	//int a[100];
	//long long sum[100];
	//long long sum_l[100];
	//long long sum_r[100];
	//long long sum_together[100];
	//int b[100];
	//int b_l[100];
	//int b_r[100];
	//int b_together[100];
	//int idx[100];
	//int t[max_n + 1];

	inp(a, sum, sum_l, sum_r, n, l, r);
//===============================================================
	for (i = 1; i <= n; i++)
		sum_together[i] = sum[i];
	sum_l[0] = l - 1;
	j = 0;
	for (i = n + 1; i <= 2 * n + 1; i++) {
		sum_together[i] = sum_l[j];
		j++;
	}
	sum_r[0] = r;
	j = 0;
	for (i = 2 * n + 2; i <= 3 * n + 2; i++) {
		sum_together[i] = sum_r[j];
		j++;
	}
//================================================================
	for (i = 1; i <= 3 * n + 2; i++)
		idx[i] = i;

	quickSort(sum_together, idx, 1, 3 * n + 2);

	roiRacHoa(b, b_l, b_r, b_together, sum_together, idx, n);
//================================================================
	for (i = 1; i <= 3 * max_n + 2; i++)
		t[i] = 0LL;

	solve(b, b_l, b_r, n, t);
}


