#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include "fft.h"

const int N = 1000;
const double PI = acos(-1);
char sa[N], sb[N];
int n = 4, lena, lenb, res[N];
cp a[N], b[N], omg[N], inv[N];
void init_omg() {
	for (int i = 0; i < n; i++) {
		omg[i] = cp(cos(2 * PI * i / n), sin(2 * PI * i / n));
		inv[i] = conj(omg[i]);
	}
}
void fft(cp *a) {
	init_omg();
	int lim = 0;
	while ((1 << lim) < n) lim++;
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < lim; j++)
			if ((i >> j) & 1) t |= (1 << (lim - j - 1));
		if (i < t) swap(a[i], a[t]); // i < t 的限制使得每对点只被交换一次（否则交换两次相当于没交换）
	}
	for (int l = 2; l <= n; l *= 2) {
		int m = l / 2;
		for (cp *p = a; p != a + n; p += l)
			for (int i = 0; i < m; i++) {
				cp t = omg[n / l * i] * p[i + m];
				p[i + m] = p[i] - t;
				p[i] += t;
			}
	}
}
int fft_test() {
	scanf("%s%s", sa, sb);
	lena = strlen(sa), lenb = strlen(sb);
	while (n < lena + lenb) n *= 2;
	for (int i = 0; i < lena; i++)
		a[i].real(sa[lena - 1 - i] - '0');
	for (int i = 0; i < lenb; i++)
		b[i].real(sb[lenb - 1 - i] - '0');
	init_omg();
	fft(a);
	fft(b);
	for (int i = 0; i < n; i++)
		a[i] *= b[i];
	fft(a);
	for (int i = 0; i < n; i++) {
		res[i] += floor(a[i].real() / n + 0.5);
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	for (int i = res[lena + lenb - 1] ? lena + lenb - 1 : lena + lenb - 2; i >= 0; i--)
		putchar('0' + res[i]);
	putchar('\n');
	return 0;
}