/**************************
Author: Lauren Chilen
File: routeD.c
Resources: 
	-https://www.geeksforgeeks.org/c/c-arrays/
	- chat for debugginging
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "STATS.h"

int getAnswer(int min, int max) 
{
    	int choice;

    	while (1) 
	{
        	printf("Enter choice (%d-%d): ", min, max);

        	if (scanf("%d", &choice) != 1) 
		{
            		printf("That is not a valid input. Enter a number.\n");
            		
			while (getchar() != '\n');
            		continue;
        	}

        	while (getchar() != '\n');

        	if (choice >= min && choice <= max) 
		{
            		return choice;
        	}

        	printf("Please enter between %d and %d.\n", min, max);
    	}
}


void routeD(Character team[4]) 
{
    	printf("\n--- welcome to the wild ---\n");

    	int stage;
    	int choice;

    	for (stage = 1; stage <= 9; stage++) 
	{
        	printf("\n------------ STAGE %d --------------\n", stage);

        	printf("Choose your path:\n");
        	printf("1. Safe (low risk, low reward)\n");
        	printf("2. Balanced\n");
        	printf("3. Risky (high reward, high danger)\n");
        	
		choice = getAnswer(1, 3);

// safe ish
        if (choice == 1) 
	{
            	printf("You travel cautiously.\n");
            	team[0].resources -= 5;
            	team[0].health -= 2;

            	if (rand() % 5 == 0) 
		{
                	printf("Minor illness (not tuberculosis)\n");
                	team[0].health -= 5;
            	}
        }

// in the middle level of risky
        else if (choice == 2) 
	{
            	printf("You take a medium risk.\n");

            	int outcome = rand() % 3;

            	if (outcome == 0) 
		{
                	printf("Found supplies\n");
                	team[0].resources += 15;
            	}
            	else if (outcome == 1) 
		{
                	printf("Nothing happened\n");
            	}
            	else 
		{
                	printf("You got hurt\n");
               		team[0].health -= 20;
            	}
        }

//very risky
        else if (choice == 3) 
	{
            	printf("You take a dangerous shortcut\n");

            	int outcome = rand() % 4;

            	if (outcome == 0) 
		{
                	printf("Huge reward!\n");
                	team[0].dabloons += 100;
            	}
            	else if (outcome == 1) 
		{
                	printf("You found resources\n");
                	team[0].resources += 30;
            	}
            	else if (outcome == 2) 
		{
                	printf("You were ambushed by cowboys\n");
                	team[0].health -= 60;
            	}
            	else 
		{
                	printf("Disaster. You lost a lot in a natural disastor\n");
                	team[0].resources -= 40;
                	team[0].dabloons -= 50;
            	}
        }

        else 
	{
            	printf("That is not a valid choice. You hesitate and lose time.\n");
            	team[0].resources -= 5;
        }

// extra dablooms
        if (rand() % 3 == 0) 
	{
            	printf("\nBonus Event: You found hidden dablooms\n");
            	team[0].dabloons += 25;
        }

// player status
        printf("\nSTATUS:\n");
        printf("Health: %d | Dabloons: %d | Resources: %d\n", team[0].health, team[0].dabloons, team[0].resources);

// resource drainage
        team[0].resources -= 10;

        if (team[0].resources < 0) 
	{
            	printf("You are starving!\n");
            	team[0].health -= 10;
        }

        if (team[0].health <= 0) 
	{
            	printf("You did not survive the wild.\n");
            	return;
        }
	}

    	printf("\nYou survived! \n");
}
