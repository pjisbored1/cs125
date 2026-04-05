#ifndef ROUTEA_H
#define ROUTEA_H
typedef struct SingleEvent{
	int threshold;

	char char1Adv[50];
	float char1ChanceMult;
	float char1OutputMult;

	char char2Adv[50];
	float char2ChanceMult;
	float char2OutputMult;
	
	float inputAmt;
	int inputType; // 0 = health, 1 = resources, 2 = money
	
	float outputAmtGood;
	float outputAmtBad;
	int outputType; // see above
	
	char string[1000];
} event;

void getFile(event evt[6], char Map[1000]);
#endif
