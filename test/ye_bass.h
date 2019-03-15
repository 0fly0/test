#pragma once

#include <stdio.h>
#include <iostream>
#include "ooura_fft.h"
#include "fft.h"
using namespace webrtc;
using namespace std;
#define READ_BUF 128

void bass_test() {
	init_omg();
	FILE* fpIn = fopen("speaker_16bit_8k.pcm", "rb");
	FILE* fpOut = fopen("out.pcm", "wb");
	if (!fpIn || !fpOut)
		return;
	
	//OouraFft fft;
	int i;
	short buf[READ_BUF];
	short writeBuf[READ_BUF];
	float bufFft[READ_BUF] = {1.0f, 2.0f, -1.0f, 3.0f};
	complex<double>* a = new complex<double>[4];
	for (i = 0; i < 4; i++)
	{
		a[i].real(bufFft[i]);
	}
	fft(a);
	for (i = 0; i < 4; i++)
	{
		cout << "a" << i<<"="<<a[i].real() <<a[i].imag()<<"i"<< endl;
	}

	while (1)
	{
		if (fread(buf, sizeof(short), READ_BUF, fpIn) == READ_BUF)
		{
			for (i = 0; i < READ_BUF; i++) //convert short to float
			{
				//bufFft[i] = buf[i];
			}
			//fft.Fft(bufFft);
			/*unsigned short fl;
			for (i = 0; i < 10; i++)
			{
				fl = (unsigned short)bufFft[i];
				if (fl < (unsigned short)(1 << 15))
				{
					fl += 100;
					bufFft[i] = fl;
				}
			}*/
			//fft.InverseFft(bufFft);
			for (i = 0; i < READ_BUF; i++) //convert float to short
			{
				writeBuf[i] = (short)bufFft[i];
			}
			fwrite(writeBuf, sizeof(short), READ_BUF, fpOut);
		}else
			break;
	}

	fclose(fpIn);
	fclose(fpOut);
}
