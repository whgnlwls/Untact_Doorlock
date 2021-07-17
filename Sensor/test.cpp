#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "sensorControl.h"

#define buz 21
#define ulst 28
#define ulse 27
#define mot 26

int main() {
	if (wiringPiSetup() == -1) return -1;

	DoorLock doorlock = DoorLock(buz, ulst, ulse, mot);

	doorlock.BZsetBuzzer();
	for(int i = 0; i < 5; i++) {
		doorlock.USgetDist();
	}
	doorlock.MTsetOpen();
	doorlock.MTsetClose();
	
	printf("Finish\n");

	return 0;
}
