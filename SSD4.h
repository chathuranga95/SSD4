#ifndef SSD4_H
#define SSD4_H

#include "Arduino.h"

class SSD4{ 
public:
	SSD4(int A,int B,int C,int D,int E,int F_SEG,int G,int comc1,int comc2,int comc3, int comc4);
	void lightFourDigits(int number,int dly);
	void lightDigit1(int digit);
	void lightDigit2(int digit);
	void lightDigit3(int digit);
	void lightDigit4(int digit);
	void lightSegments(int digit);
	int CC1;
};

#endif