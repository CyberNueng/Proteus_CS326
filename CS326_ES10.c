#include<reg51.h>
unsigned char runled[] = {0x01, 0x02, 0x04, 0x08};
unsigned char stateled[] = {0x80, 0x40, 0x00};
unsigned char m;
unsigned int i,j,f;

void delay(unsigned int tick){
	for(i=0;i<tick;i++){
		for(j=0;j<200;j++){
			   f = 30;
		}
	}
}

void exti() interrupt 0{
	P2 = stateled[1];
	P0--;
	delay(100);
	P2 = stateled[2];
}

void extii() interrupt 2{
	P2 = stateled[0];
	P0++;
	delay(100);
	P2 = stateled[2];
}

void main(void){
	IE = 0x85;
	IT0	= 1;
	P0 = 0x00;
	while(1){
		for(m=0;m<4;m++){
			  P1 = runled[m];
			  delay(200);
		}
	}
}