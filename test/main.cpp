#include <windows.h>
#include <iostream>
#include "fft.h"
#include "ye_bass.h"
#include "ye_fft.h"
using namespace webrtc;
using namespace std;

int main() {
	//bass_test();
	//fft_test();
	comp a[4];
	a[0] = comp(1, 0);
	a[1] = comp(2, 0);
	a[2] = comp(-1, 0);
	a[3] = comp(3, 0);
	simple_fft(a, 4);
	cout << "after fft:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "a" << i << "=" << a[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}
