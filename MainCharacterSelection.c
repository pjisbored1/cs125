////
//// sources: Copilot & slides & Chat for debugging
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STATS.h"

Character MainCharacterSelection () {
	Character MainCharacter;
	int Choice;
	MainCharacter.health = 100;
  while (1) {
    printf ("Hello traveler! Would you rather be a (1)banker, (2)hunter, (3)farmer, (4)doctor, (5)carpenter, or (6)lawyer? \n");	
    scanf ("%d", &Choice);
    
  if (Choice==1) {
    strcpy(MainCharacter.name, "Banker");
      MainCharacter.dabloons = 1600;
		  MainCharacter.LuckOfIllness = 5/10;
      MainCharacter.resources = 50;
      printf ("Great! As the %s, you will start off with $%d to your name and an ox.\n", MainCharacter.name, MainCharacter.dabloons);
		 }

      else if (Choice==2) {
        strcpy(MainCharacter.name, "Hunter");
        MainCharacter.dabloons = 450;
		    MainCharacter.LuckOfIllness = 4/10;
        MainCharacter.resources = 90;
        printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.dabloons);
	      }
        
      else if (Choice==3) {
		    strcpy(MainCharacter.name, "Farmer");
        MainCharacter.dabloons = 400;
		    MainCharacter.LuckOfIllness= 8/10;
        MainCharacter.resources = 100;
        printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.dabloons);
	      }

	     else if (Choice==4) {
		     strcpy(MainCharacter.name, "Doctor");
         MainCharacter.dabloons = 500;
         MainCharacter.LuckOfIllness = 10/10;
         MainCharacter.resources = 30;
         printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.dabloons);
       		}

	    else if (Choice==5) {
	       strcpy(MainCharacter.name, "Carpenter");
         MainCharacter.dabloons = 800;
         MainCharacter.LuckOfIllness= 4/10;
         MainCharacter.resources = 75;
         printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.dabloons);
         }
	
	    else if (Choice==6) {
        strcpy(MainCharacter.name, "Lawyer");
        MainCharacter.dabloons = 700;
        MainCharacter.LuckOfIllness = 6/10;
        MainCharacter.resources = 25;
        printf ("Great! As the %s, you will start off with $%d to your name.\n", MainCharacter.name, MainCharacter.dabloons);
        }
      else {
        printf ("Enter a number 1-6 to select your character. \n");
        while (getchar() != '\n');
        continue;
      }
      break;
  }
  printf ("------------------------------------------------------------------------------------- \n    Main Character: %s | Health: %d | Dabloons: %d | Resources: %d\n------------------------------------------------------------------------------------- \n\n",
  MainCharacter.name, MainCharacter.health, MainCharacter.dabloons,  MainCharacter.dabloons);
return MainCharacter;
}
