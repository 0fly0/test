#pragma once

#include <complex>
using namespace std;

typedef complex <double> cp;

void init_omg();
int fft_test();
void fft(cp* a);
