/*
File	:	route.c
Author	:	Em Pearlman
Purpose	:	This is a list of commands for operating the route filesystem,
		pun not intended, in the Oregon Trail video game project.

Version		Date		Additions
0.1		Mar 22 2026	Program created

Res.	: 	https://www.w3schools.com/c/ & https://www.geeksforgeeks.com/c/
			in general, very helpful
		https://stackoverflow.com/questions/49663660/segmentation-fault-
			when-using-fopen
		https://www.geeksforgeeks.org/c/eof-and-feof-in-c/
		https://stackoverflow.com/questions/4358728/end-of-file-eof-in-c
		https://www.geeksforgeeks.org/c/c-program-to-read-contents-of-
			whole-file/
		https://stackoverflow.com/questions/1285097/how-to-copy-text-
			file-to-string-in-c
Comment	: 	
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "routeB.h"
/*
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
*/ //commented out for routeA.h

void getFileB(event evt[6], char Map[1000], int e[100]){// ARRAY INSIDE OF ARRAY
				// take array E[6] and put it in another array
				// in main that's just the crossed off places
				// player has been
				// When E[final] < 0, end the game
	char string[100];
	char dS[100] = "./"; // first part of string must be separate so it can
	char sD[100];	     // stay defined
	char temp[80];
	int check = 0;
	int x = 0;
	
	printf("Please enter the exact name of the route folder: ");
	while (check == 0){
		scanf(" %s",&sD); // sD = "test", let's say
		while(getchar() != '\n');
		strcpy(string,sD); // string = sD = "test"

		strcat(dS,sD);	// dS = "./test"
		strcat(dS,"/");	// dS = "./test/"
		strcat(dS,sD);	// dS = "./test/test"
		strcpy(sD,dS);	// sD = dS = "./test/test"
		strcat(dS,".events");	// dS = "./test/test.events"
		strcat(sD,".map");	// sD = "./test/test.map"

		FILE* rte = fopen(dS,"r");
		FILE* map = fopen(sD,"r");
		
		if ((rte == NULL) || (map == NULL)){
			printf("Invalid route name, please try again: ");
			strcpy(string,"");
			strcpy(dS,"./");
			strcpy(sD,"");
			check = 0;
		}
		else{
			while (check == 0){
				if (feof(map) == 1){
					printf(	"Error: .map file misconfigured"
						"\n");
					fclose(map);
					check = 1;
				}
				else{
					fgets(temp,80,map);
					if (strncmp(temp,"End",3) == 0){
						fclose(map);
						check = 1;
					}
					else strcat(Map,temp);
					for(x=0;x<=99;x++){
						fscanf(map,"%d",&e[x]);
						if(e[x] < 0) break;
					}
				}
			}
			for(x=0;x<=5;x++){ // list of values defined in docs
				fscanf(rte,"%d",&evt[x].threshold);
				fscanf(rte,"%f",&evt[x].char1ChanceMult);
				fscanf(rte,"%f",&evt[x].char1OutputMult);
				fscanf(rte,"%f",&evt[x].char2ChanceMult);
				fscanf(rte,"%f",&evt[x].char2OutputMult);
				fscanf(rte,"%f",&evt[x].inputAmt);
				fscanf(rte,"%d",&evt[x].inputType);
				fscanf(rte,"%f",&evt[x].outputAmtGood);
				fscanf(rte,"%f",&evt[x].outputAmtBad);
				fscanf(rte,"%d",&evt[x].outputType);
				fseek(rte,1,SEEK_CUR);
				fgets(evt[x].char1Adv,50,rte);
				fgets(evt[x].char2Adv,50,rte);
				fgets(evt[x].string,1000,rte);
				printf("POS: %d\n",ftell(rte));
				fseek(rte,1,SEEK_CUR);
			}
			fclose(rte);

			printf("\n--- Loading the map ---\n");
			printf("Map:\n%s\n", Map);

			int i, choice;

			for (i = 0; i < 6; i++) 
			{
    				printf("\n-----------------------\n");
    				printf("Event %d:\n", i + 1);
    				printf("%s\n", evt[i].string);

    				printf("1. %s", evt[i].char1Adv);
    				printf("2. %s", evt[i].char2Adv);
    				printf("Choice: ");

    				scanf("%d", &choice);
    				while (getchar() != '\n');

    				if (choice == 1) 
				{
       		 			printf("Good outcome\n");

        				if (evt[i].outputType == 0)
            					printf("Health +%.0f\n", evt[i].outputAmtGood);
        				else if (evt[i].outputType == 1)
            					printf("Resources +%.0f\n", evt[i].outputAmtGood);
        				else
            					printf("Dabloons +%.0f\n", evt[i].outputAmtGood);
    				}
    
				else 
				{
        					printf("Bad outcome!\n");

        					if (evt[i].outputType == 0)
            						printf("Health %.0f\n", evt[i].outputAmtBad);
        					else if (evt[i].outputType == 1)
            						printf("Resources %.0f\n", evt[i].outputAmtBad);
        					else
            						printf("Dabloons %.0f\n", evt[i].outputAmtBad);
    				}
			}

		printf("\n🎉 Route Complete!\n");
		}
	}
}

// This int main() is merely for testing purposes. Uncomment it to test if this
// file is working.
// THIS INT MAIN() FILE IS OUTDATED AS OF APR 6, DO NOT DO THE ABOVE
/*
int main(){
	char map[1000];
	event evt[6];
	int x = 0;
	
	getFile(evt,map);
	printf("%s\n",map);
	for(x=0;x<=5;x++){
		printf("ts: %d\n",evt[x].threshold);
		printf("1multC: %f\n",evt[x].char1ChanceMult);
		printf("1multO: %f\n",evt[x].char1OutputMult);
		printf("2multC: %f\n",evt[x].char2ChanceMult);
		printf("2multO: %f\n",evt[x].char2OutputMult);
		printf("Iamt: %f\n",evt[x].inputAmt);
		printf("Ityp: %d\n",evt[x].inputType);
		printf("OamtG: %f\n",evt[x].outputAmtGood);
		printf("OamtB: %f\n",evt[x].outputAmtBad);
		printf("Otyp: %d\n",evt[x].outputType);
		printf("char1: %s\n",evt[x].char1Adv);
		printf("char2: %s\n",evt[x].char2Adv);
		printf("str: %s\n",evt[x].string);
	}
	return 0;
}
*/
