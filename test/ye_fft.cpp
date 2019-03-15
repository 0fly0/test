#include <cmath> //M_PI cos sin
#include <iostream> //cout

#include "ye_fft.h"

const double cf_pi = acos(-1);

void simple_fft(comp* a, int len)
{
	if (len > 1024)
		return;

	int i = 0, j = 0;
	int k = len, n = len;
	comp** omg_nk = new comp*[n];

	for (i = 0; i < n; i++)
	{
		cout << "a" << i << "=" << a[i] << " ";
	}
	cout << endl;
	comp* ctmp = new comp[n];
	for (i = 0; i < n; i++)
	{
		omg_nk[i] = new comp[k];
		for (j = 0; j < k; j++)
		{
			omg_nk[i][j] = comp(cos(2 * cf_pi*j*i / n), -1.0*sin(2 * cf_pi*j*i / n));
			cout << "omg" << i << j << "=" << omg_nk[i][j] << "  ";
			ctmp[i] += omg_nk[i][j] * a[j];//
		}
	}
	for (i = 0; i < n; i++)
	{
		a[i] = ctmp[i];
		delete []omg_nk[i];
	}
	delete []omg_nk;
	delete []ctmp;
}
