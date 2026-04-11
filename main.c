/*
File: main.c
Author: Lauren Chilen
Purpose: combine everything together and make it work
Version: 3.0 April 7th 2026
Resources:
	- https://www.youtube.com/watch?v=oe11Dhw9dOg
	- ASCII color table 
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "STATS.h"
#include "routeB.h"
#include "routeC.h"
#include "routeD.h"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

Character MainCharacterSelection();
void OtherCharacterSelection(Character team[4]);

int main() 
{
    	srand(time(NULL));

    	Character team[4]; 

    	printf(CYAN"-----------------------------------------------------\n");
    	printf(MAGENTA"        welcome to our take on the oregon trail\n");
    	printf(CYAN"-----------------------------------------------------\n\n");

    	printf(RED"how to play:\n");
    	printf(CYAN"-----------------------------------------------------\n");
    	printf(BLUE"1. Choose your main character\n");
    	printf(BLUE"2. Choose 3 sidekicks\n");
    	printf(BLUE"3. Pick a route to travel\n\n");

    	printf(RED"throughout the game:\n");
    	printf(YELLOW"- events will happen randomly or by choice\n");
    	printf(YELLOW"- your stats will change:\n");
    	printf(YELLOW"		Health → if it hits 0, you die\n");
    	printf(YELLOW"    	Dabloons → money used for not dying\n");
    	printf(YELLOW"    	Resources → supplies like food (for not dying)\n\n");

    	printf(RED"survive to the end to win\n");
    	printf(CYAN"-----------------------------------------------------\n\n");


    	team[0] = MainCharacterSelection();
    	OtherCharacterSelection(team);

    	int choice;

	while (1)
	{
   		printf(RED"\nchoose your route by entering 1, 2, or 3:\n");
   		printf(GREEN"1. The original trail\n");
    		printf(MAGENTA"2. Survive the frontier\n");
    		printf(BLUE"3. Survive the wild\n");
    		printf("Enter choice: ");

    		scanf("%d", &choice);
		while (getchar() != '\n');

    		if (choice == 1) 
		{
        		event evt[6];
        		char map[1000] = "";
        		int e[100];

        		getFileB(evt, map, e); 

        		printf("\n--- loading the map ---\n");
        		printf("Map:\n%s\n", map);

        		printf("\nEvent data loaded\n");
        		printf("(Gameplay system can be expanded here)\n");
			break;
    		}

    		else if (choice == 2) 
		{
        		routeC(team);
			break;
    		}
    		else if (choice == 3) 	
		{
        		routeD(team);
			break;
    		}
    		else 	
		{
        		printf("That is not a valid choice, try again\n");
			
    		}
	}

    	return 0;
}
