#include "SSD4.h" //include the declaration for this class

int segs [7] = {0,0,0,0,0,0,0};
const byte numbers [10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011,0b1011111, 0b1110000, 0b1111111, 0b1111011 };
int CC1, CC2, CC3, CC4;

//<<constructor>> 
SSD4::SSD4(int A,int B,int C,int D,int E,int F_SEG,int G,int comc1,int comc2,int comc3, int comc4){
	segs[0] = A;
	segs[1] = B;
	segs[2] = C;
	segs[3] = D;
	segs[4] = E;
	segs[5] = F_SEG;
	segs[6] = G;
	
        for(int i = 0; i<7 ; i++){
          pinMode(segs[i],OUTPUT);
        }
	CC1 = comc1;
	CC2 = comc2;
	CC3 = comc3;
	CC4 = comc4;
	pinMode(CC1,OUTPUT);
	pinMode(CC2,OUTPUT);
	pinMode(CC3,OUTPUT);
	pinMode(CC4,OUTPUT);
      }

//other methods
void SSD4::lightFourDigits(int number,int dly){
  
  for(int j=0;j<dly/8;j++){
    lightDigit1(number/1000);
    delay(2);
    lightDigit2((number/100)%10);
    delay(2);
    lightDigit3((number/10)%10);
    delay(2);
    lightDigit4(number%10);
    delay(2);
    digitalWrite(CC4, HIGH);
  }
}
void SSD4::lightDigit1(int digit) {
  digitalWrite(CC2, HIGH);
  digitalWrite(CC1, LOW);
  digitalWrite(CC3, HIGH);
  digitalWrite(CC4, HIGH);
  lightSegments(digit);
}

void SSD4::lightDigit2(int digit) {
  digitalWrite(CC2, LOW);
  digitalWrite(CC1, HIGH);
  digitalWrite(CC3, HIGH);
  digitalWrite(CC4, HIGH);
  lightSegments(digit);
}
void SSD4::lightDigit3(int digit) {
  digitalWrite(CC2, HIGH);
  digitalWrite(CC1, HIGH);
  digitalWrite(CC3, LOW);
  digitalWrite(CC4, HIGH);
  lightSegments(digit);
}
void SSD4::lightDigit4(int digit) {
  digitalWrite(CC2, HIGH);
  digitalWrite(CC1, HIGH);
  digitalWrite(CC3, HIGH);
  digitalWrite(CC4, LOW);
  lightSegments(digit);
}


void SSD4::lightSegments(int digit) {
  
  for (int i = 0; i < 7; i++) {
    int bit = bitRead(numbers[digit], 6-i);
    digitalWrite(segs[i],bit); 
  }
}


