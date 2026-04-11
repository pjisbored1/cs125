/**********************************
Author: Lauren Chilen
File: routeC.c
Resources:
	-chat gpt for debugging
	- slide decks for loop help
	-https://stackoverflow.com/questions/33380282/how-does-rand-work-in-c
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "STATS.h"

int getChoice() 
{
    	int choice;

    	while (1) 
	{
        	printf("Choice (1 or 2): ");

        	if (scanf("%d", &choice) != 1) 
		{
            		printf("Please enter a number.\n");
            		while (getchar() != '\n');
            		continue; //could not get getChoice to work. chat restructured it and added this
        	}

        	while (getchar() != '\n');

        		if (choice == 1 || choice == 2) 
			{
            			return choice;
        		}

        	printf("Please enter 1 or 2.\n");
    	}
}

void routeC(Character team[4]) 
{
	printf("\n--- welcome to the frontier ---\n");

    	int day;
    	int choice;
	
    	for (day = 1; day <= 7; day++) 
	{
        	printf("\n---------------- DAY %d -----------------\n", day);

        	int event = rand() % 5;

// EVENT 1: maybe they find some food. maybe it kills them (it wont)
        	if (event == 0) 
		{
            		printf("You discover a patch of wild berries\n");
           	 	printf("1. Eat now\n2. Store for later\n");
            		choice = getChoice();

            		if (choice == 1) 
			{
                		printf("They were safe!\n");
               	 		team[0].health += 5;
            		} 
			else 
			{
                		printf("Stored successfully\n");
               			team[0].resources += 15;
            		}
        	}
// EVENT 2: now they get to cross a river
        	else if (event == 1) 
		{
            		printf("You reach a wide river\n");
            		printf("1. Cross\n2. Build raft (cost resources)\n");
            		choice = getChoice();

            		if (choice == 1) 
			{
                		if (rand() % 2) 
				{
                    			printf("You slipped.. ouch\n");
                    			team[0].health -= 15;
                		} 	
				else 
				{
                    			printf("Safe crossing\n");
                		}
            		} 
			else 
			{
                		if (team[0].resources >= 10) 
				{
                    			printf("Raft worked\n");
                    			team[0].resources -= 10;
                		} 
				else 
				{
                    			printf("Not enough resources, forced crossing\n");
                    			team[0].health -= 10;
                		}
            		}
        	}

// EVENT 3: a minecraft villager is here to trade with you
        	else if (event == 2) 
		{
            		printf("A traveling trader appears\n");
            		printf("1. Buy food (20 dabloons)\n2. Ignore\n");
            		choice = getChoice();

            		if (choice == 1 && team[0].dabloons >= 20) 
			{
                		team[0].dabloons -= 20;
                		team[0].resources += 20;
                		printf("Trade successful\n");
            		} 
			else
			{
                		printf("No trade\n");
            		}
        	}

// EVENT 4: oh no, TB
        	else if (event == 3) 
		{
            		printf("Someone has tuberculosis\n");

            		if ((rand() % 10) < (team[0].LuckOfIllness * 10)) 
			{
                		printf("They recovered\n");
            		}
 			else 
			{
                		printf("It got worse and will be a miracle if they make it the night\n");
                		team[0].health -= 20;
            		}
        	}

// EVENT 5: robbers
        	else 
		{
            		printf("Bandits are attacking\n");
            		printf("1. Fight\n2. Run\n");
            		choice = getChoice();

            		if (choice == 1) 
			{
                		if (rand() % 2) 
				{
                    			printf("You won\n");
                    			team[0].dabloons += 40;
                		} 
				else 
				{
                    			printf("You were horribly injured\n");
                    			team[0].health -= 25;
                		}
            		} 	
			else 
			{
                			printf("You escaped but at the cost of lost supplies\n");
                			team[0].resources -= 15;
            		}
        	}

// status
        	printf("\nSTATUS:\n");
        	printf("Health: %d | Dabloons: %d | Resources: %d\n", team[0].health, team[0].dabloons, team[0].resources);

// daily ish resource drain
        	team[0].resources -= 5;

        	if (team[0].resources < 0) 
		{
            		printf("You are very hungry. You should probably eat\n");
            		team[0].health -= 10;
        	}

        	if (team[0].health <= 0) 
		{
            		printf("You did not survive the frontier. womp womp\n");
            		return;
        	}
    	}

    	printf("\nYou survived the frontier. enjoy the wild west\n");
}
